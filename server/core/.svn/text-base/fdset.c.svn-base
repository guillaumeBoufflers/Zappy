/*
** fdset.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/core
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:41:37 2013 antoine knockaert
** Last update Sun Jul 14 18:41:37 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"

static void		add_fds_client_list(t_server *server,
					    t_client_list *list)
{
  t_client_list		*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp && tmp->item)
	{
	  FD_SET(tmp->item->fd, &(server->rfds));
	  if (tmp->item->write_buffer)
	    FD_SET(tmp->item->fd, &(server->wfds));
	}
      tmp = tmp->next;
    }
}

void			reset_fdset(t_server *server)
{
  FD_ZERO(&(server->rfds));
  FD_ZERO(&(server->wfds));
  FD_SET(server->sfd, &(server->rfds));
  add_fds_client_list(server, server->awaiting_clients);
  add_fds_client_list(server, server->clients);
}
