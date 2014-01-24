/*
** xwrite.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/utils
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:54:12 2013 antoine knockaert
** Last update Sun Jul 14 18:54:13 2013 antoine knockaert
*/

#include		"utils.h"

void			xwrite(int fd, char *str, int size)
{
  if (write(fd, str, size) == -1)
    {
      perror("Fatal-Error on write");
      exit(1);
    }
}
