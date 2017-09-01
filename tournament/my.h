/*
** my.h for opti in /home/abdel/CPE/dante/astar
** 
** Made by abdel cherkaoui
** Login   <abdel@epitech.net>
** 
** Started on  Sun May 14 14:02:56 2017 abdel cherkaoui
** Last update Sun May 14 23:25:20 2017 abdel cherkaoui
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
# define UP	0b0001
# define DOWN	0b0010
# define LEFT	0b0100
# define RIGHT	0b1000
# define ENDY   info->sizeY - 1
# define ENDX	info->sizeX - 2
# define R	info->str[pos.y * info->sizeX +  pos.x + 1] == '*'
# define ALW_R	pos.x + 1 < info->sizeX && R
# define D	info->str[(pos.y + 1) * info->sizeX + pos.x] == '*'
# define ALW_D	pos.y + 1 < info->sizeY  && D
# define L	info->str[(pos.y * info->sizeX) + pos.x - 1] == '*'
# define ALW_L  pos.x - 1 >= 0 && L
# define U	info->str[(pos.y - 1) * info->sizeX + pos.x] == '*'
# define ALW_U  pos.y - 1 >= 0 && U
# define MISS	'V'
# define PATH	'o'
# define WALL	'X'
# define STREET	'*'

typedef struct	s_info
{
  char	*str;
  int	sizeX;
  int	sizeY;
}		t_info;

typedef struct	s_pos
{
  int	x;
  int	y;
}		t_pos;

void    my_reader(t_info *info, char *filepath);
#endif /*!_DANTE_H*/
