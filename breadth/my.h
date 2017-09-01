/*
** my.h for ok in /home/abdel/lem-in
**
** Made by abdel cherkaoui
** Login   <abderrahim.cherkaoui@epitech.net>
**
** Started on  Wed Apr 12 13:42:58 2017 abdel cherkaoui
** Last update Sun May 14 23:24:21 2017 abdel cherkaoui
*/

#ifndef _DANTE_H_
#define _DANTE_H_
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "gnl.h"

# define UP	    0b0001
# define DOWN	0b0010
# define LEFT	0b0100
# define RIGHT	0b1000
# define ENDY   info->sizeY - 1
# define ENDX	info->sizeX - 1
# define ALW_R	pos.x + 1 < info->sizeX && info->txt[pos.y][pos.x + 1] == '*'
# define ALW_D	pos.y + 1 < info->sizeY && info->txt[pos.y + 1][pos.x] == '*'
# define ALW_L  pos.x - 1 >= 0 && info->txt[pos.y][pos.x - 1] == '*'
# define ALW_U  pos.y - 1 >= 0 && info->txt[pos.y - 1][pos.x] == '*'
# define MISS	'V'
# define PATH	'o'
# define WALL	'X'
# define STREET	'*'

typedef struct	s_info
{
  char	**txt;
  int	**imap;
  int	sizeX;
  int	sizeY;
}		t_info;

typedef struct	s_pos
{
  int	x;
  int	y;
  int	t;
}		t_pos;

void    my_reader(t_info *info, char *filepath);
#endif /*!_DANTE_H*/
