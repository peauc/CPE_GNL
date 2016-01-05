/*
** get_next_line.c for gnlc in /home/peau_c/rendu/CPE/GNL/CPE_2015_getnextline
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Tue Dec 29 13:19:17 2015
** Last update Tue Jan  5 22:58:38 2016 
*/

#include "get_next_line.h"

void	my_strncat(char *dest, char *src, int chars, int pos)
{
  int	i;

  i = 0;
  while (pos != chars + pos)
    {
      dest[pos++] = src[i++];
    }
}

char	*my_realloc(char *str, int buffsize, int nbr)
{
  char	*tmp;
  int	i;

  i = 0;
  tmp = malloc(READ_SIZE * nbr + 1);
  while (i != READ_SIZE * nbr + 1)
    tmp[i++] = 0;
  printf("%d\n", strlen(str));
  my_strncat(tmp, str, strlen(str), 0);
  return (tmp);
}

char	*get_next_line(const int fd)
{
  char	*buff;
  char	*str;
  int	i;
  int	readed;

  i = 1;
  buff = malloc(READ_SIZE + 1);
  buff[READ_SIZE] = 0;
  while ((readed = read(fd, buff, READ_SIZE)) != 0)
    {
      printf("buff = %s\n", buff);
      printf("str = %s\n", str);
      str = my_realloc(str, READ_SIZE, i);
      my_strncat(str, buff, strlen(str), readed);
      printf("strlen boucle %d\n", strlen(str));
    }
  free(buff);
  return (str);
}
