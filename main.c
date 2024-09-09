/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** mai
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int match(matchstick *test, int line, int matchs, int limit)
{
    int yolo = l;
    int merde = matchs;

    while (yolo > 0){
        if (test->map[line][yolo] == '|' && merde != 0){
            test->map[line][yolo] = ' ';
            merde = merde - 1;
            test->list[line] = test->list[line] - 1;
            test->total = test->total - 1;
        }
        yolo = yolo - 1;
    }
    my_printf("Player removed %i match(es) from line %i\n", matchs, line);
    return 1;
}

int get_my_match(int limit, matchstick *test, size_t bufsize, int yolo)
{
    char *line = NULL;
    int a;
    int b;
    int c = 0;

    while (c == 0){
        my_printf("Matches: ");
        a = getline(&line, &bufsize, stdin);
        if (a == -1){
            my_putstr("ERROR\n");
            return -1;
        }
        if ((b = my_atoi(line)) != -1){
            if (check_match(test, b, limit, yolo) == 0)
                c = 1;
        } else {
            my_putstr("Error: invalid input (positive number expected)\n");
        }
    }
    return b;
}

int get_my_line(int limit, matchstick *test, size_t bufsize)
{
    char *line = NULL;
    int a;
    int b;
    int c = 0;

    while (c == 0){
        my_printf("Line: ");
        a = getline(&line, &bufsize, stdin);
        if (a == -1){
            my_putstr(line);
            return -1;
        }
        if ((b = my_atoi(line)) != -1){
            if (check_line(b, limit, test) == 0)
                c = 1;
        } else {
            my_putstr("Error: invalid input (positive number expected)\n");
        }
    }
    return b;
}

int testons(matchstick *test, int limit)
{
    int arr[2];

    my_putstr("Your turn:\n");
    arr[0] = get_my_line(limit, test, 10);
    if (arr[1] == -1)
        return 84;
    arr[1] = get_my_match(limit, test, 10, arr[0]);
    if (arr[1] == -1)
        return 84;
    match(test, arr[0], arr[1], limit);
    print(test);
    if (test->total != 0){
        my_putchar('\n');
        testons_ia(test, limit);
    }else {
        my_putstr("You lost, too bad...\n");
        test->flag = 2;
    }
    return 0;
}

int main(int argc , char *argv[])
{
    if (argc == 1 || my_atoi(argv[1]) == -1 || my_atoi(argv[2]) == -1)
        return 84;
    int arr[3];

    arr[0] = my_atoi(argv[1]);
    arr[1] = my_atoi(argv[2]);
    arr[2] = my_atoi(argv[1]);
    if (arr[0] == 1 || arr[0] > 99)
        return 84;
    matchstick test;
    h = my_atoi(argv[1]) + 2;
    l = my_atoi(argv[1]) * 2;
    test = memory_alloc(test);
    test = prepare_grid(test, arr[0], arr[2]);
    print(&test);
    my_putchar('\n');
    testons(&test, arr[1]);
    freee(test);
    return test.flag;
}
