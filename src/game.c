/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** loop
*/

#include "../include/my.h"

void game(village_t *v, int nb_fights)
{
    pthread_t druid_thread;

    pthread_create(&druid_thread, NULL, (void *)druid, v->druid);
    for (int i = 0; i != v->num_villager; i++) {
        v->villagers[i].id = i;
        v->villagers[i].fights_left = nb_fights;
        v->villagers[i].druid = v->druid;
        if (pthread_create(&v->villagers[i].thread, NULL,
        (void *) villagers, &v->villagers[i]) == 84)
            printf("Fini");
    }
    for (int j = 0; j < v->num_villager; j++)
        pthread_join(v->villagers[j].thread, NULL);
    return;
}

int villagers(void *args)
{
    villager_t *v = (villager_t *)args;

    printf("Villager %d: Going into battle!\n", v->id);
    fight(v);
    printf("Villager %d: I'm going to sleep now.\n", v->id);
    return 84;
}

void fight(villager_t *v)
{
    while (v->fights_left > 0) {
        pthread_mutex_lock(&v->druid->mutex);
        printf("Villager %d: I need a drink... I see %d servings left.\n",
        v->id, v->druid->pot->qty);
        if (refill_remaining(v) == 84)
            return;
        v->druid->pot->qty -= 1;
        pthread_mutex_unlock(&v->druid->mutex);
        v->fights_left -= 1;
        printf("Villager %d: Take that roman scum! Only %d left.\n", v->id,
        v->fights_left);
    }
}

int refill_remaining(villager_t *v)
{
    if (v->druid->pot->qty == 0) {
        if (v->druid->nb_refills_remaining <= 0) {
            pthread_mutex_unlock(&v->druid->mutex);
            return (84);
        }
        printf("Villager %d: Hey Pano wake up! We need more potion.\n",
        v->id);
        sem_post(&v->druid->need_refill);
        sem_wait(&v->druid->pot_full);
    }
    return (0);
}

void druid(void *args)
{
    druid_t *d = (druid_t *)args;

    printf("Druid: I'm ready... but sleepy...\n");
    while (d->nb_refills_remaining > 0) {
        sem_wait(&d->need_refill);
        d->nb_refills_remaining -= 1;
        d->pot->qty = d->pot->pot_size;
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I "
        "can only make %d more refills after this one.\n",
        d->nb_refills_remaining);
        sem_post(&d->pot_full);
    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return;
}
