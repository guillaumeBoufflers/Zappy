/*
** take_end.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/ia
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:34:29 2013 antoine knockaert
** Last update Sun Jul 14 18:34:29 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"

void			take_end(t_server *server, t_client *client)
{
  t_client_list		*tmp;

  tmp = server->graphical_clients;
  while (tmp)
    {
      if (tmp->item && tmp->item->is_graphic)
	{
	  send_inventory(tmp->item, client);
	  content_case_bct(server, tmp->item, client->pos_x, client->pos_y);
	}
      tmp = tmp->next;
    }
}
