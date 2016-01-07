/*
** get_next_line.c for gnlc in /home/peau_c/rendu/CPE/GNL/CPE_2015_getnextline
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Tue Dec 29 13:19:17 2015
** Last update Thu Jan  7 15:46:17 2016 
*/

#include "get_next_line.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i++] != 0);
  return (i - 1);
}

void	my_strncat(char *dest, char *src, int chars, int pos)
{
  int	i;
  int	tmp;

  tmp = pos;
  i = 0;
  while (tmp < chars + pos)
      dest[tmp++] = src[i++];
}

char	*my_realloc(char *str, int buffsize, int nbr)
{
  char	*tmp;
  int	i;

  i = -1;
  tmp = malloc(READ_SIZE * nbr + 1);
  while (++i != READ_SIZE * nbr)
    tmp[i] = 0;
  my_strncat(tmp, str, my_strlen(str), 0);
  return (tmp);
}

static char	*check_n(char *str, char* stat)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  stat[10] = 0;
  while (str[i] != 0)
    {
      if (str[i] == 10)
	while (str[i] != 0)
	  {
	    if (str[i] != 10)
	      stat[j++] = str[i];
	    str[i++] = 0;
	  }
      i++;
    }
  stat[j] = 0;
  return (stat);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE + 1];
  char		*str;
  int		i;
  int		readed;

  i = 1;
  buff[READ_SIZE] = 0;
  str = malloc(READ_SIZE + 1);
  str[0] = 0;
  str[READ_SIZE] = 0;
  if (buff[0] != 0 && (i++))
    my_strncat(str, buff, my_strlen(buff), 0);
  while ((readed = read(fd, buff, READ_SIZE)) != 0)
    {
      my_strncat(str, buff, readed, my_strlen(str));
      str = my_realloc(str, READ_SIZE, i++);
      if (check_n(str, buff) == NULL || buff[0] != 0)
      	return (str);
      }
  if (str[0] != 0)
    return (str);
  if (readed == 0 && buff[0] == 0)
    return (NULL);
}
