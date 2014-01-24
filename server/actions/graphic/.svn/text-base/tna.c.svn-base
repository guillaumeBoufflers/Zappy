/*
** tna.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/graphic
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:28:55 2013 antoine knockaert
** Last update Sun Jul 14 18:28:55 2013 antoine knockaert
*/

#include		"server.h"
#include		"client.h"
#include		"utils.h"

void			tna(t_server *server, t_client *client,
			    char *cmd, char **av)
{
  char			*str;
  t_team		*tmp;

  (void) cmd;
  if (tablen(av) != 1)
    {
      add_client_response(&(client), "sbp\n");
      return ;
    }
  tmp = server->teams;
  while (tmp)
    {
      str = my_sprintf("tna %s\n", tmp->name);
      add_client_response(&(client), str);
      if (str)
	free(str);
      tmp = tmp->next;
    }
}
