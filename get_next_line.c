/*
** get_next_line.c for get_next_line.h in /home/peau_c/rendu/CPE/GNL/CPE_
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Tue Mar  8 18:40:35 2016 Clement Peau
** Last update Wed Mar  9 14:30:49 2016 Clement Peau
*/

#include "get_next_line.h"

void	my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
}

int	is_there_a_n(char *str, char *buff)
{
  int	i;
  int	j;

  j = 0;
  while (str[j] && j++);
  i = 0;
  printf("%p -> %s\n", buff, buff);
  while (buff[i] != 0)
    {
      str[j] = buff[i];
      if (buff[i++] == 10)
      	{
	  str[j] = 0;
	  my_strcpy(buff, buff + i);
	  printf("is_there_a_n -> %s\n", str);
	  printf("is_there_a_n -> 1\n");
	  printf("sortie %s\n", buff);
      	  return (1);
      	}
      j++;
    }
  str[j] = 0;
  printf("sortie %s\n", buff);
  printf("is_there_a_n -> 0\n");
  return (0);
}

char	*my_realloc(char *str)
{
  int	i;
  char	*new_str;

  while (str[i++]);
  if ((new_str = malloc(i + READ_SIZE)) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      new_str[i] = str[i];
      i++;
    }
}

char	*get_next_line(const int fd)
{
  char		*str;
  static char	buff[READ_SIZE + 1];
  int		readed;

  buff[READ_SIZE] = 0;
  if ((str = malloc((READ_SIZE + 1) * sizeof(char))) == NULL)
    return (NULL);
  str[0] = 0;
  while ((readed = read(fd, buff, READ_SIZE)) > 1)
    {
      printf("buff = %s\n", buff);
      printf("je passe\n");
      if (is_there_a_n(str, buff) == 1)
	break ;
      my_realloc(str);
    }
  return (str);
}
