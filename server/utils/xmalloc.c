/*
** xmalloc.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/utils
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:54:04 2013 antoine knockaert
** Last update Sun Jul 14 18:54:05 2013 antoine knockaert
*/

#include		"utils.h"

void			*xmalloc(int size)
{
  void			*ptr;

  ptr = malloc(size);
  if (ptr)
    {
      bzero(ptr, size);
      return (ptr);
    }
  else
    {
      perror("Error on malloc");
      exit(1);
    }
}
