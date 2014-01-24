/*
** tablen.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/utils
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:53:45 2013 antoine knockaert
** Last update Sun Jul 14 18:53:46 2013 antoine knockaert
*/

#include		"utils.h"

int			tablen(char **t)
{
  int			i;

  i = 0;
  while (t && t[i])
    i++;
  return (i);
}
