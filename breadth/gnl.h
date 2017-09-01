/*
** get_next_line.h for ok in /home/abdel/CPE_2016_getnextline
** 
** Made by Abderrahim CHERKAOUI
** Login   <abdel@epitech.net>
** 
** Started on  Sat Jan 14 18:08:43 2017 Abderrahim CHERKAOUI
** Last update Wed Apr 19 16:07:33 2017 abdel cherkaoui
*/

#ifndef GNL_H_
# define GNL_H_
#ifndef READ_SIZE
# define READ_SIZE 4096
#endif

#include "my.h"

typedef struct	s_my_gnl
{
  int           treat;
  char          *line;
}		t_my_gnl;

char            *get_next_line(const int fd);
static int      my_static_strlen(char *str);
static char     *my_copy(char *d, char *src, int n);
static char     *plus(char *l, int t, char *b, int *s);

#endif /* !GNL */
