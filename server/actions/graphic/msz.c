/*
** msz.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/graphic
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:28:03 2013 antoine knockaert
** Last update Sun Jul 14 18:28:04 2013 antoine knockaert
*/

#include		"server.h"
#include		"client.h"
#include		"utils.h"

void			msz(t_server *server, t_client *client,
			    char *cmd, char **av)
{
  char			*str;

  (void) cmd;
  if (tablen(av) != 1)
    {
      add_client_response(&(client), "sbp\n");
      return ;
    }
  str = my_sprintf("msz %d %d\n", server->game_infos.size_x,
		   server->game_infos.size_y);
  add_client_response(&(client), str);
  if (str)
    free(str);
}
