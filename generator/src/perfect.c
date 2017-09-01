/*
** perfect.c for map in /home/sid/Projet/map/map/sources/generateur/genrator/
**
** Made by Sid Djilali Saiah
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Thu Apr 27 23:34:29 2017 Sid Djilali Saiah
** Last update Wed Jun  7 09:48:23 2017 Sid
*/

#include "generator.h"

int	check_sides(t_map *map, int i, int j)
{
  if (i - 1 >= 0 && map->map[i - 1][j] == 'X')
    map->up = true;
  if (j - 1 >= 0 && map->map[i][j - 1] == 'X')
    map->left = true;
  if (map->up == true && map->left == true)
    return (1);
  return (0);
}

void	break_walls(t_map *map, int i, int j)
{
  int	k;

  k = rand()%2;
  check_sides(map, i, j);
  if (i - 1 >= 0 && map->up == true && map->left == false)
    map->map[i - 1][j] = '*';
  if (j - 1 >= 0 && map->up == true && map->left == false)
    map->map[i][j - 1] = '*';
  if (check_sides(map, i, j) == 1)
    {
      if (j - 1 >= 0 && k == 0)
	map->map[i][j - 1] = '*';
      else if (i - 1 >= 0 && k == 1)
	map->map[i - 1][j] = '*';
    }
}

void	resize_map(t_map *map)
{
  int	i;
  int	j;

  i = 0;
  while (i < map->h)
    {
      j = 0;
      while (j < map->w)
	j++;
      map->map[i][j] = '\0';
      i++;
    }
  map->map[i] = NULL;
}

void	create_exit(t_map *map)
{
  if (map->map[map->h - 1][map->w - 2] == 'X'
      && map->map[map->h - 2][map->w - 1] == 'X')
    map->map[map->h - 1][map->w - 2] = '*';
  map->map[map->h - 1][map->w - 1] = '*';
}

void	create_perfect_maze(t_map *map)
{
  int	i;
  int	j;
  int	x;

  i = 0;
  while (i < map->height)
    {
      j = 0;
      while (j < map->width)
	{
	  if (i == 0)
	    map->map[i][j] = '*';
	  break_walls(map, i, j);
	  j = j + 2;
	}
      i = i + 2;
    }
  resize_map(map);
  create_exit(map);
  finish_maze(map);
}
