/*
** EPITECH PROJECT, 2020
** util.c
** File description:
** util.c
*/

#include "my.h"

int check_line(int a, int limit, matchstick *test)
{
    if (a >= h){
        my_printf("Error: this line is out of range\n");
        return -1;
    }
    if (a == 0){
        my_putstr("Error: invalid input (positive number expected)\n");
        return -1;
    }
    return 0;
}

int check_match(matchstick *test, int matchs, int lim, int line)
{
    if (matchs <= 0){
        my_printf("Error: you have to remove at least one match\n");
        return 1;
    }
    if (matchs > lim){
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(lim);
        my_putstr(" matches per turn\n");
        return 1;
    }
    if (matchs > test->list[line]){
        my_printf("Error: Not enough matches on this line\n");
        return 1;
    }
    return 0;
}

void print(matchstick *test)
{
    int a = 0;
    int b = 0;

    while (a < h){
        while (b <= l){
            my_printf("%c", test->map[a][b]);
            b = b + 1;
        }
        my_printf("\n");
        b = 0;
        a = a + 1;
    }
}

void freee(matchstick test)
{
    int a = 0;

    while (a < h){
        free(test.map[a]);
        a = a + 1;
    }
    free(test.list);
}
