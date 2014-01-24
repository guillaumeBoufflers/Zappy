/*
** avance.c for avance in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/ia
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:31:00 2013 antoine knockaert
** Last update Sun Jul 14 18:31:43 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"

void			move_bis(t_server *serv, t_client *client, int x, int y)
{
  move_object(PLAYER, &serv->map[y][x],
	      &serv->map[client->pos_y][client->pos_x]);
  notification_graphical(serv, "ppo %d %d %d %d\n", client->fd,
			 client->pos_x, client->pos_y, client->dir);
}

void			move(t_server *serv, t_client *client, char *cmd,
			     char **command)
{
  int			x;
  int			y;

  (void) cmd;
  x = client->pos_x;
  y = client->pos_y;
  if (tablen(command) > 1)
    {
      add_client_response(&client, "sbp\n");
      return ;
    }
  if (client->dir == SOUTH)
    client->pos_y = (client->pos_y + 1) % serv->game_infos.size_y;
  else if (client->dir == NORTH)
    client->pos_y = (client->pos_y - 1 >= 0) ? (client->pos_y - 1) :
      (serv->game_infos.size_y - 1);
  else if (client->dir == EST)
    client->pos_x = (client->pos_x + 1) % serv->game_infos.size_x;
  else
    client->pos_x = (client->pos_x - 1 >= 0) ? (client->pos_x - 1) :
      (serv->game_infos.size_x - 1);
  add_client_response(&client, "ok\n");
  move_bis(serv, client, x, y);
}
