##
## Makefile for corewar in /home/sid/CPE_2016_corewar
## 
## Made by Sid
## Login   <sid.djilali-saiah@epitech.eu>
## 
## Started on  Mon Apr  3 00:10:48 2017 Sid
## Last update Wed Jun  7 09:09:33 2017 Sid
##

all:
	make -C astar
	make -C breadth
	make -C depth
	make -C generator
	make -C tournament

re:
	make re -C astar
	make re -C breadth
	make re -C depth
	make re -C generator
	make re -C tournament


clean:
	make clean -C astar
	make clean -C breadth
	make clean -C depth
	make clean -C generator
	make clean -C tournament

fclean:
	make fclean -C astar
	make fclean -C breadth
	make fclean -C depth
	make fclean -C generator
	make fclean -C tournament
