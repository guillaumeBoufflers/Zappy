/*
** ppo.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/graphic
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:28:36 2013 antoine knockaert
** Last update Sun Jul 14 18:28:37 2013 antoine knockaert
*/

#include		"server.h"
#include		"client.h"
#include		"utils.h"

static void		send_position(t_client *client, t_client *cl)
{
  char			*str;

  if (cl)
    {
      str = my_sprintf("ppo %d %d %d %d\n",
		       cl->fd, cl->pos_x, cl->pos_y,
		       (int) cl->dir);
      add_client_response(&(client), str);
      if (str)
	free(str);
    }
}

void			ppo(t_server *server, t_client *client,
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
  send_position(client, cl);
}
