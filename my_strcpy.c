/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** sdzez
*/

char *my_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0'){
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
