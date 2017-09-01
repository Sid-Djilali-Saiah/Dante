/*
** generator.h for map in /home/sid/Projet/map/map/sources/generateur/genrator/
**
** Made by Sid Djilali Saiah
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Thu Apr 27 19:33:30 2017 Sid Djilali Saiah
** Last update Sat May  6 23:34:13 2017 Sid
*/

#ifndef GENERATOR_H
# define GENERATOR_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

typedef struct	s_map
{
  int	h;
  int	w;
  int	height;
  int  	width;
  char  **map;
  bool 	up;
  bool	left;
}		t_map;

int   init_struct(t_map *map, int height, int width);
void  fill_line(t_map *map, int i, int j);
int   create_map(t_map *map);
int   check_sides(t_map *map, int i, int j);
void  break_walls(t_map *map, int i, int j);
void  resize_map(t_map *map);
void  create_exit(t_map *map);
void  finish_maze(t_map *map);
void  create_perfect_maze(t_map *map);
int   perfect_maze(int height, int width);
void  print_tab(char **tab);
int   check_is_num(char *str);
void  perfect_to_imperfect(t_map *map);
int   imperfect_maze(int height, int width);

# endif /*!GENERATOR_H*/
