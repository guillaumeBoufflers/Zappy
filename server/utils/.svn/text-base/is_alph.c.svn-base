/*
** is_alph.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/utils
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:52:47 2013 antoine knockaert
** Last update Sun Jul 14 18:52:47 2013 antoine knockaert
*/

#include		"utils.h"

int			is_alph(char *str)
{
  int			i;

  i = 0;
  while (str && str[i])
    {
      if (!((str[i] >= 'A' && str[i] <= 'Z') ||
	    (str[i] >= 'a' && str[i] <= 'z')))
	return (0);
      i++;
    }
  return (1);
}
