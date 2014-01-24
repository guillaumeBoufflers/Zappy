/*
** sst.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/graphic
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:30:26 2013 antoine knockaert
** Last update Sun Jul 14 18:30:26 2013 antoine knockaert
*/

#include		"server.h"
#include		"client.h"
#include		"utils.h"

void			sst(t_server *server, t_client *client,
			    char *cmd, char **av)
{
  int			time;
  char			*str;

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
  time = atoi(av[1]);
  if (time <= 0)
    {
      add_client_response(&(client), "sbp\n");
      return ;
    }
  server->game_infos.time = time;
  str = my_sprintf("sgt %d\n", server->game_infos.time);
  add_client_response(&(client), str);
  if (str)
    free(str);
}
