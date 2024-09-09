/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** azda
*/
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int special_case_2(va_list yolo, char *test, int a)
{
    int b;

    b = test[a + 1];
    switch (b) {
    case 's':
        my_putstr(va_arg(yolo, char*));
        break;
    case '%':
        my_putchar('%');
        break;
    }
    return a;
}

int special_case(va_list yolo, char *test, int a)
{
    int b;

    b = test[a + 1];
    switch (b) {
    case 'c':
        my_putchar(va_arg(yolo, int));
        break;
    case 'i':
        my_put_nbr(va_arg(yolo, int));
        break;
    case 'd':
        my_put_nbr(va_arg(yolo, int));
        break;
    default:
        a = special_case_2(yolo, test, a);
    }
    a = a + 1;
    return (a);
}

int my_printf(const char *format, ...)
{
    int i;
    char *test;
    va_list yolo;

    i = 0;
    test = my_strdup(format);
    va_start(yolo, format);
    while (format[i] != '\0')
    {
        if (test[i] == '%'){
            i = special_case(yolo, test, i);
            i = i + 1;
        }else {
            my_putchar(test[i]);
            i = i + 1;
        }
    }
    return (0);
}
