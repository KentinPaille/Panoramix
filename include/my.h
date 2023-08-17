/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** my
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct pot {
    int qty;
    int pot_size;
}pot_t;

typedef struct druid {
    pot_t *pot;
    sem_t need_refill;
    sem_t pot_full;
    int nb_refills_remaining;
    pthread_mutex_t mutex;
}druid_t;

typedef struct villager {
    int id;
    int fights_left;
    pthread_t thread;
    druid_t *druid;
}villager_t;

typedef struct village {
    int num_villager;
    druid_t *druid;
    villager_t *villagers;
}village_t;

void usage(void);
void game(village_t *v, int nb_fights);
int check_args(char **av);
void init_struct(village_t *v, char **av);
int villagers(void *args);
void druid(void *args);
void fight(villager_t *v);
void free_all(village_t *v);
int refill_remaining(villager_t *v);
