/*
** perfect_tools.c for map in /home/sid/Projet/map/map/sources/generateur/genrator/
**
** Made by Sid Djilali Saiah
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Thu Apr 27 23:39:55 2017 Sid Djilali Saiah
** Last update Sun May 14 22:23:24 2017 Sid
*/

#include "generator.h"

void	finish_maze(t_map *map)
{
  int	i;
  int	j;

  i = -1;
  j = -1;
  while (++j < map->w)
    map->map[0][j] = '*';
  while (++i < map->h)
    map->map[i][0] = '*';
}

void	print_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i + 1])
    {
      printf("%s\n", tab[i]);
      i++;
    }
  printf("%s", tab[i]);
}

void	fill_line(t_map *map, int i, int j)
{
  if (j % 2 == 0 && i % 2 == 0)
    map->map[i][j] = '*';
  else if (j % 2 != 0 && i % 2 == 0)
    map->map[i][j] = 'X';
  else if (i % 2 != 0)
    map->map[i][j] = 'X';
}

int	create_map(t_map *map)
{
  int	i;
  int	j;

  i = 0;
  if (map->height == 0 || map->width == 0)
    return (-1);
  if (!(map->map = malloc(sizeof(char *) * (map->height + 1))))
    return (-1);
  while (i < map->height)
    {
      if (!(map->map[i] = malloc(sizeof(char) * (map->width + 1))))
	return (-1);
      j = 0;
      while (j < map->width)
	{
	  fill_line(map, i, j);
	  j++;
	}
      map->map[i][j] = '\0';
      i++;
    }
  map->map[i] = NULL;
  return (0);
}

int	init_struct(t_map *map, int height, int width)
{
  map->h = height;
  map->w = width;
  map->height = (2 * height) - 1;
  map->width = (2 * width) - 1;
  if ((create_map(map)))
    return (-1);
  map->up = false;
  map->left = false;
  return (0);
}
