/*
** solver.c for ok in /home/abdel/dante
** 
** Made by abdel cherkaoui
** Login   <abdel@epitech.net>
** 
** Started on  Wed Apr 19 15:04:32 2017 abdel cherkaoui
** Last update Sun May 14 13:54:58 2017 abdel cherkaoui
*/

#include "my.h"

void	print(char *txt, int sizeX, int sizeY)
{
  int	i;
  i = -1;
  while (txt[++i] != '\0')
    if (txt[i] == 'V')
      txt[i] = '*';
  write(1, txt, sizeY * sizeX);
}

int	rec(t_info *info, t_pos pos, int offsetx, int offsety)
{
  pos.x = pos.x + offsetx;
  pos.y = pos.y + offsety;
  info->str[pos.y * info->sizeX + pos.x] = PATH;
  if (pos.x == ENDX && pos.y == ENDY)
    return (0);
  if (ALW_D)
    if (rec(info, pos, 0, 1) == 0)
      return (0);
  if (ALW_R)
    if (rec(info, pos, 1, 0) == 0)
      return (0);
  if (ALW_L)
    if (rec(info, pos, -1, 0) == 0)
      return (0);
  if (ALW_U)
    if (rec(info, pos, 0, -1) == 0)
      return (0);
  info->str[pos.y * info->sizeX + pos.x] = 'V';
  return (84);
}

int		main(int ac, char **av)
{
  t_info	info;
  t_pos		pos;

  pos.x = 0;
  pos.y = 0;
  pos.t = 0;
  info.sizeX = 1;
  if (ac == 2)
    {
      my_reader(&info, av[1]);
      if (rec(&info, pos, 0, 0) == 84)
	{
	  printf("no solution found\n");
	  return (84);
	}
      print(info.str, info.sizeX, info.sizeY);
    }
  return (0);
}
