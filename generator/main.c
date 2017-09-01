/*
** main.c for dante in /home/sid/Projet/dante/dante/sources/generateur/genrator/
**
** Made by Sid Djilali Saiah
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Thu Apr 27 19:10:42 2017 Sid Djilali Saiah
** Last update Sun May 14 20:41:05 2017 Sid
*/

#include "include/generator.h"

int	main(int ac, char **av)
{
  srand(getpid() * time(NULL));
  if (ac == 3)
    {
      if (check_is_num(av[1]) || check_is_num(av[2]))
	return (-1);
      if (imperfect_maze(atoi(av[1]), atoi(av[2])))
	return (-1);
    }
  else if (ac == 4)
    {
      if (check_is_num(av[1]) || check_is_num(av[2])
	  || strcmp("perfect", av[3]))
	return (-1);
      if (perfect_maze(atoi(av[1]), atoi(av[2])))
	return (-1);
    }
  return (0);
}
