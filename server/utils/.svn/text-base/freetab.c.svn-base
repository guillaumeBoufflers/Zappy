/*
** freetab.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/utils
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:51:45 2013 antoine knockaert
** Last update Sun Jul 14 18:51:50 2013 antoine knockaert
*/

#include		"utils.h"

void			freetab(char **t)
{
  int			i;

  i = 0;
  while (t && t[i])
    {
      free(t[i]);
      i++;
    }
  if (t)
    free(t);
}
