/*
** handle_clients_awaiting.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/core
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:41:59 2013 antoine knockaert
** Last update Sun Jul 14 18:41:59 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"
#include		"buffer.h"
#include		"command.h"
#include		"client.h"

static void		initialize_player(t_server *server, t_client *client,
					  t_team *team)
{
  t_object		*player;

  player = new_object(PLAYER);
  client->team = team;
  client->player = player;
  client->life = 10;
  client->life_timeout = -1;
  client->pos_x = rand() % server->game_infos.size_x;
  client->pos_y = rand() % server->game_infos.size_y;
  client->level = 1;
  client->dir = NORTH;
  new_object_list(player, &(server->map[client->pos_y][client->pos_x]));
  notification_graphical(server, "pnw %d %d %d %d %d %s\n",
			 client->fd, client->pos_x, client->pos_y,
			 client->dir, client->level, client->team->name);
}

static void		accept_client(t_server *server, t_client *client,
				      t_team *team)
{
  char			*str;

  if (team)
    {
      server_log(1, 0, "Client %d was accepted by server\n", client->fd);
      delete_client(client, &(server->awaiting_clients));
      str = my_sprintf("%d\n%d %d\n", team->slots_available,
		       server->game_infos.size_x,
		       server->game_infos.size_y);
      add_client_response(&(client), str);
      free(str);
      add_client_list(client, &(server->clients));
      if (team)
	team->slots_available--;
      initialize_player(server, client, team);
    }
}

static void		reject_client(t_server *server, t_client *client)
{
  server_log(1, 0, "Client %d was rejected by server\n", client->fd);
  add_client_response(&(client), "0\n");
  close_client_connexion(server, client, &(server->awaiting_clients));
}

static void		handle_client_awaiting_command(t_server *server,
						       t_client *client,
						       char *command)
{
  int			slots;

  if (command && strcmp("GRAPHIC", command) == 0)
    {
      server_log(1, 0, "Client %d is a graphical interface\n", client->fd);
      client->is_graphic = 1;
      delete_client(client, &(server->awaiting_clients));
      add_client_list(client, &(server->clients));
      add_client_list(client, &(server->graphical_clients));
      graphic_initialization(server, client);
    }
  else
    {
      server_log(1, 0, "Client %d wants to join team \"%s\"\n",
		 client->fd, command);
      client->is_graphic = 0;
      if ((slots = get_available_slots_team(server, command)) > 0)
	accept_client(server, client, get_team(server, command));
      else
	reject_client(server, client);
    }
}

void			handle_clients_awaiting(t_server *server)
{
  t_client_list		*tmp;
  char			to_delete;

  tmp = server->awaiting_clients;
  while (tmp)
    {
      to_delete = 0;
      if (tmp->item && FD_ISSET(tmp->item->fd, &(server->rfds)))
	{
	  if (stock_in_buff(tmp->item->fd, server->buffer) == -1)
	    to_delete = 1;
	  else
	    handle_client_awaiting_command(server, tmp->item,
					   build_buff_command(&(server->buffer
								)));
	}
      if (tmp->item && FD_ISSET(tmp->item->fd, &(server->wfds)))
	if (handle_client_write(tmp->item) != 0)
	  to_delete = 1;
      if (to_delete && tmp->item)
	close_client_connexion(server, tmp->item, &(server->awaiting_clients));
      tmp = tmp->next;
    }
}
