/*
** EPITECH PROJECT, 2020
** prepare.
** File description:
** 
*/

#include "my.h"

int my_atoi(char *str)
{
    int a;
    int i;

    a = 0;
    for (i = 0; str[i] != '\0' && str[i] != '\n'; i = i + 1){
        if (str[i] > 57 || str[i] < 48)
            return -1;
        else
            a = a * 10 + str[i] - '0';
    }
    return a;
}

matchstick prepare_grid_two(matchstick test)
{
    int y = 0;
    int z = 0;

    while (z < h){
        while (y <= l){
            if (z == 0 || y == 0 || y == l || z == h - 1)
                test.map[z][y] = '*';
            else if (test.map[z][y] != '|')
                test.map[z][y] = ' ';
            y = y + 1;
        }
        y = 0;
        z = z + 1;
    }
}

matchstick memory_alloc(matchstick test)
{
    int x;
    int a = 0;

    test.total = 0;
    test.map = (char**) malloc(h * sizeof(char*));
    for (x = 0; x < h; ++x){
        test.map[x] = (char *) malloc(l * sizeof(char));
    }
    test.list = (int *) malloc(l * sizeof(int));
    while (a < l){
        test.list[a] = 0;
        a = a + 1;
    }
    return test;
}

matchstick prepare_grid(matchstick test, int min, int max)
{
    int v = 1;
    int t = min;
    int a = 0;

    while (v + 1 < h){
        while (t <= max)
        {
            test.map[v][t] = '|';
            a = a + 1;
            test.total = test.total + 1;
            t = t + 1;
        }
        test.list[v] = a;
        a = 0;
        max = max + 1;
        min = min - 1;
        t = min;
        v = v + 1;
    }
    test = prepare_grid_two(test);
    return test;
}
