/*
** EPITECH PROJECT, 2020
** ia_game.c
** File description:
** ia
*/

#include "my.h"

int match_ia(matchstick *test, int line, int matchs, int limit)
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
    my_printf("IA removed %i match(es) from line %i\n", matchs, line);
    return 1;
}

int testons_ia(matchstick *test, int limit)
{
    int line;
    int matchs;

    my_putstr("AI's turn...\n");
    line = get_ia_line(test, limit, rand());
    matchs = get_ia_match(test, limit, line, rand());
    match_ia(test, line, matchs, limit);
    print(test);
    if (test->total != 0){
        my_putchar('\n');
        testons(test, limit);
    }else{
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        test->flag = 1;
    }
    return 0;
}
