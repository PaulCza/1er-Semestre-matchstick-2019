/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** sdzf
*/

#include <unistd.h>

int my_put_nbr(int nb)
{
    int test;

    if (nb < 0){
        my_putchar('-');
        nb = nb * - 1;
    }
    if (nb >= 0) {
        if (nb >= 10){
            test = nb % 10;
            nb = nb / 10;
            my_put_nbr(nb);
            my_putchar(48 + test);
        } else {
            my_putchar(48 + nb % 10);
        }
    }
    return (0);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i]!= '\0'){
        my_putchar(str[i]);
        i = i + 1;
    }
}