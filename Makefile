##
## EPITECH PROJECT, 2024
## minishell1
## File description:
## the makefile
##

SRC = 	src/*.c

OBJ = $(SRC:.c=.o)

NAME = mysh

$(NAME):
	gcc -g -g3 -o $(NAME) $(SRC)

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
