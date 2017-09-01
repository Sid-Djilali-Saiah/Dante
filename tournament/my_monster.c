/*
** solver.c for ok in /home/abdel/dante
** 
** Made by abdel cherkaoui
** Login   <abdel@epitech.net>
** 
** Started on  Wed Apr 19 15:04:32 2017 abdel cherkaoui
** Last update Sun May 14 15:31:49 2017 abdel cherkaoui
*/

#include "my.h"

void            my_reader(t_info *info, char *filepath)
{
  char          c;
  char          *str;
  int           fd;
  int           i;
  struct stat   buff;

  i = 0;
  if ((fd = open(filepath, O_RDONLY)) <= 0)
    exit(84);
  stat(filepath, &buff);
  if (buff.st_size == 0)
    exit(84);
  info->str = malloc(sizeof(char) * buff.st_size + 2);
  read(fd, info->str, buff.st_size);
  while (info->str[i++] != '\n')
    info->sizeX = info->sizeX + 1;
  info->str[buff.st_size] = '\0';
  info->sizeY = buff.st_size / (info->sizeX + 1) + 1;
  close(fd);
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
  info->str[pos.y * info->sizeX + pos.x] = '*';
  return (84);
}

int		main(int ac, char **av)
{
  t_info	info;
  t_pos		pos;

  pos.x = 0;
  pos.y = 0;
  info.sizeX = 1;
  if (ac == 2)
    {
      my_reader(&info, av[1]);
      if (rec(&info, pos, 0, 0) == 84)
	{
	  printf("no solution found\n");
	  return (84);
	}
      write(1, info.str, info.sizeY * info.sizeX);
    }
  return (0);
}
