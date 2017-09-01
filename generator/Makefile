##
## Makefile for dante in /home/sid/dante/generateur/
##
## Made by Sid Djilali Saiah
## Login   <sid.djilali-saiah@epitech.eu>
##
## Started on  Fri Apr 28 20:07:47 2017 Sid Djilali Saiah
## Last update Sat May  6 23:51:23 2017 Sid
##

NAME	= generator

CC	= gcc

RM	= rm -f

SRCS	= ./main.c \
	  ./src/generator.c \
	  ./src/perfect.c \
	  ./src/perfect_tools.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I./include/
CFLAGS += -O3 -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
