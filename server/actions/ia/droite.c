/*
** droite.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/ia
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:32:01 2013 antoine knockaert
** Last update Sun Jul 14 18:32:01 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"

void			right(t_server *serv, t_client *client, char *cmd,
			      char **command)
{
  (void) serv;
  (void) cmd;
  if (tablen(command) > 1)
    {
      add_client_response(&client, "sbp\n");
      return ;
    }
  if (client->dir == SOUTH)
    client->dir = EST;
  else if (client->dir == NORTH)
    client->dir = WEST;
  else if (client->dir == EST)
    client->dir = NORTH;
  else
    client->dir = SOUTH;
  add_client_response(&client, "ok\n");
  notification_graphical(serv, "ppo %d %d %d %d\n", client->fd,
			 client->pos_x, client->pos_y, client->dir);
}
