/*
** my_reader.c for my read in /home/abdel/dante/algo1
**
** Made by abdel cherkaoui
** Login   <abdel@epitech.net>
**
** Started on  Wed Apr 19 15:39:18 2017 abdel cherkaoui
** Last update Sun May 14 14:44:57 2017 abdel cherkaoui
*/

#include "my.h"

void	fill_table(t_info *info, char *filepath)
{
  int	dir;
  int	i;
  char	*str;

  i = 0;
  dir = open(filepath, O_RDONLY);
  while ((info->txt[i] = get_next_line(dir)) != NULL)
    i++;
  info->txt[i] = NULL;
  close(dir);
}

void	my_reader(t_info *info, char *filepath)
{
  int   fd;

  info->sizeY = 0;
  fd = open(filepath, O_RDONLY);
  if (fd >= 0)
    {
      while (get_next_line(fd) != NULL)
	     info->sizeY++;
      close(fd);
      if (info->sizeY == 0)
	exit(84);
      if ((info->txt = malloc(sizeof(char *) * info->sizeY)) == NULL)
	exit(84);
      fill_table(info, filepath);
    }
  else
    exit(84);
}
