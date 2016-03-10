/*
** get_next_line.c for get_next_line.h in /home/peau_c/rendu/CPE/GNL/CPE_
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar  8 18:40:35 2016 Clement Peau
** Last update Thu Mar 10 15:58:54 2016 Clement Peau
*/

#include "get_next_line.h"

int	push_back(char *str)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (str[i] != 0 && str[i] != 10)
      i++;
  if (str[i] == 0)
    {
      str[0] = 0;
      return (1);
    }
  if (str[i] == 10)
    {
      i++;
      while (str[i] != 0)
	str[j++] = str[i++];
      return (0);
    }
}

void	my_strcpy(char *dest, char *src, int j, int mode)
{
  int	i;

  i = 0;
  while (src[j])
    {
      dest[i] = src[j];
      i++;
      j++;
    }
  dest[i] = 0;
}

int	is_there_a_n(char *str, char *tmp, char *buff)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == 10)
	{
	  my_strcpy(buff, str + i + 1, 0, 0);
	  str[i] = 0;
	  return (1);
	}
      i++;
    }
  return (0);
}

char	*my_realloc(char *str, char *buffer)
{
  int	i;
  char	*new_str;
  int	j;

  j = 0;
  i = -1;
  while (str[++i] != 0);
  if ((new_str = malloc(i + READ_SIZE + 2)) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      new_str[i] = str[i];
      i++;
    }
  while (buffer[j])
      new_str[i++] = buffer[j++];
  new_str[i] = 0;
  free(str);
  return (new_str);
}

char	*get_next_line(const int fd)
{
  char		*str;
  static char	*buff = NULL;
  char		tmp[READ_SIZE + 1];
  int		readed;

  if (!(tmp[READ_SIZE] = 0) && buff == NULL)
      if ((buff = malloc((READ_SIZE + 1) * sizeof(char))) == NULL ||
	  (buff[READ_SIZE] = 0) || (buff[0] = 0))
	return (NULL);
  if ((str = malloc(READ_SIZE + 1)) == NULL || (str[0] = 0))
    return (NULL);
  my_strcpy(str, buff, 0, 1);
  if (push_back(buff) == 0)
    return (str);
  while (!is_there_a_n(str, tmp, buff))
    {
      readed = read(fd, tmp, READ_SIZE);
      tmp[readed] = 0;
      str = my_realloc(str, tmp);
      if (readed < 1 && str[0] != 0)
	{
	  return (str);
	}
      if (readed < 1 && str[0] == 0)
	return (NULL);
    }
  return (str);
}
