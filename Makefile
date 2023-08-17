##
## EPITECH PROJECT, 2023
## Panoramix
## File description:
## Makefile
##

NAME = panoramix

SRC = panoramix.c \
	  src/init.c \
	  src/game.c \
	  src/free.c

OBJ	= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -g3 -I./include -lpthread

all	: $(NAME)

$(NAME)	: $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean :
	rm -rf $(OBJ)
	rm -rf vgcore.*

fclean : clean
	rm -rf $(NAME)

re	: fclean all

phony: all clean fclean re
