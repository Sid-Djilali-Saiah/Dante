/*
** my_reader.c for my read in /home/abdel/dante/algo1
**
** Made by abdel cherkaoui
** Login   <abdel@epitech.net>
**
** Started on  Wed Apr 19 15:39:18 2017 abdel cherkaoui
** Last update Sun May 14 14:01:13 2017 abdel cherkaoui
*/

#include "my.h"

void		my_reader(t_info *info, char *filepath)
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
