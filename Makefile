##
## Makefile
## File description:
## oh bordel
##

SRC	=	main.c 	\
		prepare.c \
		my_printf.c \
		my_putchar.c \
		my_put_nbr_str.c \
		my_strcpy.c \
		my_strdup.c \
		my_strlen.c \
		ia.c \
		util.c \
		ia_game.c \

NAME	= matchstick

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

