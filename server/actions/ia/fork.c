/*
** fork.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/ia
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:33:48 2013 antoine knockaert
** Last update Sun Jul 14 18:33:49 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"

void			fork_c(t_server *server, t_client *client,
			     char *cmd, char **av)
{
  (void) server;
  (void) cmd;
  if (tablen(av) != 1)
    {
      add_client_response(&(client), "sbp\n");
      return ;
    }
  if (client->team)
    client->team->slots_available++;
  add_client_response(&(client), "ok\n");
}
