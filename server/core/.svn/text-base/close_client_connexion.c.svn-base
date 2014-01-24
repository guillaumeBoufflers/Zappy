/*
** close_client_connexion.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/core
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:40:58 2013 antoine knockaert
** Last update Sun Jul 14 18:40:59 2013 antoine knockaert
*/

#include		<stdio.h>
#include		"client.h"
#include		"team.h"
#include		"server.h"
#include		"utils.h"

void			close_client_connexion(t_server *server,
					       t_client *client,
					       t_client_list **list)
{
  t_object_list		*tmp;

  tmp = NULL;
  server_log(2, 0, "Connexion closed with client %d\n", client->fd);
  handle_client_write(client);
  if (!client->is_graphic)
    {
      notification_graphical(server, "pdi %d\n", client->fd);
      move_object(PLAYER, &server->map[client->pos_y][client->pos_x], &tmp);
    }
  close(client->fd);
  delete_client(client, list);
  if (client->is_graphic)
    delete_client(client, &(server->graphical_clients));
  if (client->team)
    client->team->slots_available++;
  free_client(client);
}
