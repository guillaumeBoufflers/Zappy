/*
** pnwa.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/graphic
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:28:29 2013 antoine knockaert
** Last update Sun Jul 14 18:29:25 2013 antoine knockaert
*/

#include		"server.h"
#include		"client.h"
#include		"utils.h"

void			pnwa(t_server *server, t_client *client,
			     char *cmd, char **av)
{
  t_client_list		*tmp;
  char			*str;
  t_client		*cl;

  (void) cmd;
  tmp = server->clients;
  if (tablen(av) != 1)
    {
      add_client_response(&(client), "sbp\n");
      return ;
    }
  while (tmp)
    {
      if (tmp->item && tmp->item->is_graphic == 0 && cl->team)
	{
	  cl = tmp->item;
	  str = my_sprintf("pnw %d %d %d %d %d %s\n",
			   cl->fd, cl->pos_x, cl->pos_y,
			   cl->dir, cl->level, cl->team->name);
	  add_client_response(&(client), str);
	  if (str)
	    free(str);
	}
      tmp = tmp->next;
    }
}
