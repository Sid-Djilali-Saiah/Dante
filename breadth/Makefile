##
## Makefile for ok in /home/abdel/lem-in
## 
## Made by abdel cherkaoui
## Login   <abdel@epitech.net>
## 
## Started on  Wed Apr 12 14:24:02 2017 abdel cherkaoui
## Last update Sun May 14 14:07:48 2017 abdel cherkaoui
##

CC	:= gcc

RM	:= rm -rf

SRCS	:=	./fc_base/gnl.c		\
		./my_reader.c		\
		./main.c

NAME	:= solver

all:
	$(CC) -O3 -O2 -O -Os $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
