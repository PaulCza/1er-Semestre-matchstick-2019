/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** header
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
int h;
int l;

typedef struct game{
    char **map;
    int *list;
    int total;
    int flag;
}matchstick;

int testons(matchstick *test, int limit);
matchstick prepare_grid_two(matchstick test);
matchstick memory_alloc(matchstick test);
matchstick prepare_grid(matchstick test, int min, int max);
int my_printf(const char *format, ...);