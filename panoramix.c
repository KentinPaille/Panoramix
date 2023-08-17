/*
** EPITECH PROJECT, 2023
** Panoramix
** File description:
** panoramix
*/

#include "include/my.h"

int lunch_game(village_t v, char **av)
{
    if (check_args(av) == 84) {
        usage();
        printf("Values must be >0.\n");
        return (84);
    }
    init_struct(&v, av);
    game(&v, atoi(av[3]));
    free_all(&v);
    return (0);
}

int main(int ac, char **av)
{
    village_t v;

    if (ac == 1 || (ac == 2 && strcmp(av[1], "-h") == 0)) {
        usage();
        return (0);
    } else if (ac == 5) {
        return (lunch_game(v, av));
    }
    usage();
    return (84);
}
