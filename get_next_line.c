/*
** get_next_line.c for gnlc in /home/peau_c/rendu/CPE/GNL/CPE_2015_getnextline
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Tue Dec 29 13:19:17 2015
** Last update Sun Jan 17 23:03:21 2016 Clement Peau
*/

#include "get_next_line.h"

int			my_strncat(char *dest, char *src)
{
  int			i;
  int			j;

  j = -1;
  i = 0;
  while (dest[++j] != 0);
    while (src[i] != 0)
    dest[j++] = src[i++];
  dest[j] = 0;
  return (0);
}

char			*my_realloc(char *str, int nbr)
{
  char			*tmp;
  int			i;

  i = -1;
  if ((tmp = malloc(READ_SIZE * nbr + 1)) == NULL)
    return (NULL);
  tmp[0] = 0;
  if (nbr > 1)
    {
      my_strncat(tmp, str);
      free(str);
    }
  tmp[READ_SIZE * nbr] = 0;
  return (tmp);
}

static char		*check_n(char *str, char* stat)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (str[i++] != 0)
    if (str[i] == 10)
      while (str[i] != 0)
	{
	  if (str[i] != 10)
	    {
	      stat[j++] = str[i];
	      str[i] = 0;
	    }
	  str[i++] = 0;
	}
  stat[j] = 0;
  return (NULL);
}

char			*get_next_line(const int fd)
{
  static char		buff[READ_SIZE + 1];
  char			*str;
  int			i;
  static int		readed;

  i = 1;
  buff[READ_SIZE] = 0;
  if ((str = my_realloc(str, i)) == NULL)
    return (NULL);
  if (buff[0] != 0 && (i++) && (i++) && my_strncat(str, buff));
  while ((readed = read(fd, buff, READ_SIZE)) != 0)
    {
      if (readed < READ_SIZE && (buff[readed] = 0));
	my_strncat(str, buff);
      if ((str = my_realloc(str, ++i)) == NULL)
	return (NULL);
      if ((check_n(str, buff) != NULL) || buff[0] != 0)
      	return (str);
    }
  if (str[0] != 0)
    return (str);
  if (readed == 0 && buff[0] == 0)
    return (NULL);
}
