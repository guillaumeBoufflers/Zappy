/*
** slot.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/ia
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:34:22 2013 antoine knockaert
** Last update Sun Jul 14 18:34:23 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"

void			slot_available(t_server *serv, t_client *cl,
				    char *cmd, char **command)
{
  (void) serv;
  (void) cmd;
  if (!command[1])
    add_client_response(&cl, "sbp\n");
  add_client_response(&cl, my_sprintf("%d\n", cl->team->slots_available));
}
