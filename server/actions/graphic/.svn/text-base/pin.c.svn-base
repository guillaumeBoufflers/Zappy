/*
** pin.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/graphic
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:28:09 2013 antoine knockaert
** Last update Sun Jul 14 18:28:10 2013 antoine knockaert
*/

#include		"server.h"
#include		"client.h"
#include		"utils.h"

void			send_inventory(t_client *client, t_client *cl)
{
  int			t[8];
  char			*s;

  bzero(&t, 8 * sizeof(int));
  if (cl)
    {
      content_case(LINEMATE, cl->inventory, t);
      t[0] = cl->life;
      s = my_sprintf("pin %d %d %d %d %d %d %d %d %d %d\n", cl->fd,
		     cl->pos_x, cl->pos_y, t[0], t[1], t[2], t[3],
		     t[4], t[5], t[6]);
      add_client_response(&(client), s);
      if (s)
	free(s);
    }
}

void			pin(t_server *server, t_client *client,
			    char *cmd, char **av)
{
  int			fd;
  t_client		*cl;

  (void) cmd;
  if (tablen(av) != 2)
    {
      add_client_response(&(client), "sbp\n");
      return ;
    }
  if (!is_num(av[1]))
    {
      add_client_response(&(client), "sbp\n");
      return ;
    }
  fd = atoi(av[1]);
  if (fd <= 0)
    {
      add_client_response(&(client), "sbp\n");
      return ;
    }
  cl = client_by_id(server, fd);
  send_inventory(client, cl);
}
