/*
** main.c for main in /home/peau_c/rendu/CPE/GNL/CPE_2015_getnextline
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Fri Jan  8 09:56:17 2016
** Last update Thu Jan 14 09:44:56 2016 
*/

#include "get_next_line.h"

int	main(int ac, char **av)
{
  char	*str;
  int	fd = open("test", O_RDONLY);

  str = get_next_line(fd);
  printf("str = %s\n", str);
  str = get_next_line(fd);
  printf("str = %s\n", str);
  str = get_next_line(fd);
  printf("str = %s\n", str);
  str = get_next_line(fd);
  printf("str = %s\n", str);
  str = get_next_line(fd);
  printf("str = %s\n", str);
  str = get_next_line(fd);
  printf("str = %s\n", str);
  str = get_next_line(fd);
  printf("str = %s\n", str);
  str = get_next_line(fd);
  printf("str = %s\n", str);
}