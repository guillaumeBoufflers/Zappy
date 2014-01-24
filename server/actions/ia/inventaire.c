/*
** inventaire.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/ia
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:34:01 2013 antoine knockaert
** Last update Sun Jul 14 18:34:57 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"

void			content_inventory(t_server *serv, t_client *cl,
					  char *cmd, char **command)
{
  int			tb[8];
  char			*str;

  (void) cmd;
  (void) command;
  (void) serv;
  bzero(tb, sizeof(int) * 8);
  content_case(LINEMATE, cl->inventory, &tb[0]);
  str = my_sprintf("nourriture %d, linemate %d, deraumere %d, sibur %d,",
		   cl->life, tb[1], tb[2], tb[3]);
  str = my_sprintf("%s mendiane %d, phiras %d, thystame %d\n",
		   str, tb[4], tb[5], tb[6]);
  add_client_response(&cl, str);
  if (str)
    free(str);
}
