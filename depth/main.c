/*
** solver.c for ok in /home/abdel/dante
** 
** Made by abdel cherkaoui
** Login   <abdel@epitech.net>
** 
** Started on  Wed Apr 19 15:04:32 2017 abdel cherkaoui
** Last update Sun May 14 14:50:49 2017 abdel cherkaoui
*/

#include "my.h"

void	print(char **txt, int sizeX, int sizeY)
{
  int	y;
  int	x;

  y = 0;
  while (y != sizeY)
    {
      x = -1;
      while (++x != sizeX)
	if (txt[y][x] == 'V')
	  txt[y][x] = '*';
      write(1, txt[y], sizeX);
      write(1, "\n", 1);
      y++;
    }
}

int	rec(t_info *info, t_pos pos, int offsetx, int offsety)
{
  pos.x = pos.x + offsetx;
  pos.y = pos.y + offsety;
  info->txt[pos.y][pos.x] = PATH;
  if (pos.x == ENDX && pos.y == ENDY)
    return (0);
  if (ALW_R)
    if (rec(info, pos, 1, 0) == 0)
      return (0);
  if (ALW_D)
    if (rec(info, pos, 0, 1) == 0)
      return (0);
  if (ALW_L)
    if (rec(info, pos, -1, 0) == 0)
      return (0);
  if (ALW_U)
    if (rec(info, pos, 0, -1) == 0)
      return (0);
  info->txt[pos.y][pos.x] = 'V';
  return (84);
}

int		main(int ac, char **av)
{
  t_info	info;
  t_pos		pos;

  pos.x = 0;
  pos.y = 0;
  pos.t = 0;
  info.sizeY = 0;
  if (ac == 2)
    {
      my_reader(&info, av[1]);
      info.sizeX = strlen(info.txt[0]);
      if (rec(&info, pos, 0, 0) == 84)
	{
	  printf("no solution found\n");
	  return (84);
	}
      print(info.txt, info.sizeX, info.sizeY);
    }
  return (0);
}
