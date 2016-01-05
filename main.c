/*
** main.c for main in /home/peau_c/rendu/CPE/GNL/CPE_2015_getnextline
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Tue Dec 29 13:17:32 2015
** Last update Mon Jan  4 14:29:28 2016 
*/

#include "get_next_line.h"

int	   main()
{
  char   *s;
  int	fd = open("test", O_RDONLY);

  s = get_next_line(fd);
  printf("fin = %s\n",s);
  free(s);
  return(0);
}
