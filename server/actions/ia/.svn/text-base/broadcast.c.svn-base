/*
** broadcast.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/ia
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:31:53 2013 antoine knockaert
** Last update Sun Jul 14 18:35:56 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"

void			broadcast(t_server *serv, t_client *cl,
				  char *cmd, char **command)
{
  t_client_list		*tmp;
  char			*tmp2;

  (void) cmd;
  if (!command[1])
    add_client_response(&cl, "sbp\n");
  tmp = serv->clients;
  while (tmp)
    {
      if (tmp->item != cl)
	{
	  if (cl->pos_x == tmp->item->pos_x && cl->pos_y == tmp->item->pos_y)
	    tmp2 = my_sprintf("message 0, %s\n", &cmd[10]);
	  else
	    tmp2 = my_sprintf("message %d, %s\n", val_dir(tmp->item, cl, serv),
			      &cmd[10]);
	  add_client_response(&tmp->item, tmp2);
	  if (tmp2)
	    free(tmp2);
	}
      tmp = tmp->next;
    }
  add_client_response(&cl, "ok\n");
  notification_graphical(serv, "pbc %d %s\n", cl->fd, &cmd[10]);
}
