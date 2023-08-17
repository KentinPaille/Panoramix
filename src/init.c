/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** init
*/

#include "../include/my.h"

void usage()
{
    printf("USAGE: ./panoramix <nb_villagers> <post_size> <nb_fights> "
        "<nb_refills>\n");
}

int check_args(char **av)
{
    for (int i = 1; av[i]; i++) {
        if (atoi(av[i]) <= 0)
            return (84);
    }
    return (0);
}

void init_struct(village_t *v, char **av)
{
    v->num_villager = atoi(av[1]);
    v->villagers = malloc(sizeof(villager_t) * v->num_villager);
    v->druid = malloc(sizeof(druid_t));
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    v->druid->mutex = mutex;
    sem_init(&v->druid->need_refill, 0, 0);
    sem_init(&v->druid->pot_full, 0, 0);
    v->druid->nb_refills_remaining = atoi(av[4]);
    v->druid->pot = malloc(sizeof(pot_t));
    v->druid->pot->pot_size = atoi(av[2]);
    v->druid->pot->qty = atoi(av[2]);
}
