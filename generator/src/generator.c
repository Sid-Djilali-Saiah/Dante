/*
** generator.c for map in /home/sid/map/generateur/
**
** Made by Sid Djilali Saiah
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Fri Apr 28 20:03:43 2017 Sid Djilali Saiah
** Last update Sat Apr 29 16:58:54 2017 Sid Djilali Saiah
*/

#include "generator.h"

int     check_is_num(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
        i++;
      else
        return (1);
    }
  return (0);
}

void	perfect_to_imperfect(t_map *map)
{
  int	i;
  int	j;
  int	broken;
  int	to_break;

  broken = 0;
  to_break = (map->h * map->w) / 2;
  while (broken < to_break)
    {
      i = rand()%map->h;
      j = rand()%map->w;
      map->map[i][j] = '*';
      broken++;
    }
}

int		imperfect_maze(int height, int width)
{
  t_map	map;

  if (init_struct(&map, height, width))
    return (-1);
  create_perfect_maze(&map);
  perfect_to_imperfect(&map);
  print_tab(map.map);
  return (0);
}

int		perfect_maze(int height, int width)
{
  t_map	map;

  if (init_struct(&map, height, width))
    return (-1);
  create_perfect_maze(&map);
  print_tab(map.map);
  return (0);
}
