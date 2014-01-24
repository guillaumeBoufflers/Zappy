/*
** is_num.c for zappt in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/utils
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:53:01 2013 antoine knockaert
** Last update Sun Jul 14 18:53:02 2013 antoine knockaert
*/

#include		"utils.h"

int			is_num(char *str)
{
  int			i;

  i = 0;
  while (str && str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i++;
    }
  return (1);
}
