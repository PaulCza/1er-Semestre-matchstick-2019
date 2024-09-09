/*
** EPITECH PROJECT, 2020
** ia.c
** File description:
** ia
*/

#include "my.h"

int check_ia_line(int a, int limit, matchstick *test)
{
    if (a >= h){
        return -1;
    }
    if (a == 0){
        return -1;
    }
    if (test->list[a] == 0){
        return -1;
    }
    return 0;
}

int get_ia_line(matchstick *test, int limit, int seed)
{
    int b = 0;

    srand(seed);
    while (check_ia_line(b, limit, test) == -1){
        b = rand() % (h - 1);
    }
    return b;
}

int check_ia_match(matchstick *test, int matchs, int lim, int line)
{
    if (matchs <= 0){
        return 1;
    }
    if (matchs > lim){
        return 1;
    }
    if (matchs > test->list[line]){
        return 1;
    }
    return 0;
}

int get_ia_match(matchstick *test, int limit, int line, int seed)
{
    int b = 0;

    srand(seed);
    while (check_ia_match(test, b, limit, line) == 1){
        b = rand() % (limit + 1);
    }
    return b;
}
