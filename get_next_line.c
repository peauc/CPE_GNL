/*
** get_next_line.c for getnextline in /home/peau_c/rendu/CPE/GNL/CPE_2015_getne
**
** Made by
** Login   <peau_c@epitech.net>
m**
** Started on  Thu Jan 14 19:21:38 2016
** Last update Sun Jan 17 15:43:46 2016 Clement Peau
*/

#include "get_next_line.h"

char	*my_strcat(char *dest, char *src, int l)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != 0)
  i++;
  while (src[j] != 0)
    {
      /* printf("--%d--dest[%d] = %c && src[%d] = %c\n", __LINE__, i, dest[i], j, src[j]); */
      dest[i] = src[j];
      if (l == 1)
	printf("--%d--dest[%d] = %c && src[%d] = %c\n", __LINE__, i, dest[i], j, src[j]);
      i++;
      j++;
    }
  if (l == 1)
    printf("--%d--i a la fin de la boucle = %d\n", __LINE__, i);
  dest[i] = 0;
  return (dest);
}

char	*my_realloc(char *str, int boucle)
{
  char	*new;

  printf("--%d-- Malloc = %d\n",  __LINE__, READ_SIZE * boucle);
  /* printf("--%d-- &str = %p\n",  __LINE__, str); */
  new = malloc(READ_SIZE * boucle + 1);
  new[0] = 0;
  if (boucle != 1)
    {
      new = my_strcat(new, str, 0);
      free(str);
    }
  return (new);
}

char	*check(char *str, char *buffer)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (str[i++] != 0)
    {
      if (str[i] == 10)
	while ((str[i] != 0) && (buffer[j++] = str[i]) && (str[i++] = 0));
    }
  buffer[j] = 0;
  printf("--%d");
}
char	*is_filled(char *str, char *buff)
{

}

char	*get_next_line(int fd)
{
  static	char	buff[READ_SIZE + 1];
  char		*str;
  int		i;

  i = 1;
  buff[READ_SIZE] = 0;
  while (read(fd, buff, READ_SIZE) != 0)
    {
      str = my_realloc(str, i++);
      printf("--%d--boucle str = %s\n", __LINE__, str);
      printf("--%d--boucle buff = %s\n", __LINE__, buff);
      my_strcat(str, buff, 1);
    }
  check(str, buff);
  printf("--%d--buff = %s", __LINE__, buff);
  return (str);
}
