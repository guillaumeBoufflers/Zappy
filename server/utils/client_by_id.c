/*
** client_by_id.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/utils
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:51:31 2013 antoine knockaert
** Last update Sun Jul 14 18:51:32 2013 antoine knockaert
*/

#include		"utils.h"

t_client		*client_by_id(t_server *server, int id)
{
  t_client_list		*tmp;

  tmp = server->clients;
  while (tmp)
    {
      if (tmp->item && tmp->item->fd == id)
	return (tmp->item);
      tmp = tmp->next;
    }
  return (NULL);
}
