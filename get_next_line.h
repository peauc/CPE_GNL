/*
** get_next_line.h for gnlh in /home/peau_c/rendu/CPE/GNL/CPE_2015_getnextline
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Tue Dec 29 13:11:46 2015
** Last update Mon Mar  7 12:32:00 2016 Clement Peau
*/


#ifndef _GET_NEXT_LINE_
# define _GET_NEXT_LINE_

# ifndef READ_SIZE
#  define READ_SIZE 10
# endif /* _READ_SIZE_ */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

char *get_next_line(const int );

#endif /* _GET_NEXT_LINE_ */
