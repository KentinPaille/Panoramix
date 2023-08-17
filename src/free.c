/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** free
*/

#include "../include/my.h"

void free_all(village_t *v)
{
    free(v->druid->pot);
    pthread_mutex_destroy(&v->druid->mutex);
    sem_destroy(&v->druid->need_refill);
    sem_destroy(&v->druid->pot_full);
    free(v->druid);
    free(v->villagers);
}
