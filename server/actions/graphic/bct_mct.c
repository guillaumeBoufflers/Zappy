/*
** bct_mct.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/graphic
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:27:42 2013 antoine knockaert
** Last update Sun Jul 14 18:27:43 2013 antoine knockaert
*/

#include		"server.h"
#include		"client.h"
#include		"utils.h"

void			content_case_bct(t_server *server, t_client *client,
					 int x, int y)
{
  int			t[8];
  char			*s;

  bzero(&t, 8 * sizeof(int));
  content_case(FOOD, server->map[y][x], t);
  s = my_sprintf("bct %d %d %d %d %d %d %d %d %d\n", x, y,
		 t[0], t[1], t[2], t[3], t[4], t[5], t[6]);
  add_client_response(&(client), s);
  if (s)
    free(s);
}

void			bct(t_server *server, t_client *client,
			    char *cmd, char **av)
{
  int			x;
  int			y;

  (void) cmd;
  if (tablen(av) != 3)
    {
      add_client_response(&(client), "sbp\n");
      return ;
    }
  if (!is_num(av[1]) || !is_num(av[2]))
    {
      add_client_response(&(client), "sbp\n");
      return ;
    }
  x = atoi(av[1]);
  y = atoi(av[2]);
  content_case_bct(server, client, x, y);
}

void			mct(t_server *server, t_client *client,
			    char *cmd, char **av)
{
  int			x;
  int			y;

  (void) cmd;
  if (tablen(av) != 1)
    {
      add_client_response(&(client), "sbp\n");
      return ;
    }
  y = 0;
  while (y < server->game_infos.size_y)
    {
      x = 0;
      while (x < server->game_infos.size_x)
	{
	  content_case_bct(server, client, x, y);
	  x++;
	}
      y++;
    }
}
