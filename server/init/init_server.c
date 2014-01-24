/*
** init_server.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/init
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:46:17 2013 antoine knockaert
** Last update Sun Jul 14 18:46:18 2013 antoine knockaert
*/

#include		<time.h>
#include		"init.h"
#include		"server.h"
#include		"buffer.h"
#include		"utils.h"

static void		create_teams(t_server *server)
{
  int			i;

  i = 0;
  while (server->game_infos.teams && server->game_infos.teams[i])
    {
      server_log(1, 0, "Team %s initialized\n",
		 server->game_infos.teams[i]);
      create_tteam(&(server->teams),
		   server->game_infos.teams[i],
		   server->game_infos.nb_player_team);
      free(server->game_infos.teams[i]);
      i++;
    }
  if (server->game_infos.teams)
    free(server->game_infos.teams);
}

static void		init_map_case(t_server *server, int y, int x)
{
  if ((rand() % 3) != 0)
    new_object_list(new_object(FOOD), &(server->map[y][x]));
  if ((rand() % 3) == 0)
    new_object_list(new_object(LINEMATE), &(server->map[y][x]));
  if ((rand() % 4) == 0)
    new_object_list(new_object(DERAUMERE), &(server->map[y][x]));
  if ((rand() % 5) == 0)
    new_object_list(new_object(SIBUR), &(server->map[y][x]));
  if ((rand() % 6) == 0)
    new_object_list(new_object(MENDIANE), &(server->map[y][x]));
  if ((rand() % 6) == 0)
    new_object_list(new_object(PHIRAS), &(server->map[y][x]));
  if ((rand() % 7) == 0)
    new_object_list(new_object(THYSTAME), &(server->map[y][x]));
  if (server->map[y][x] == NULL)
    new_object_list(new_object(FOOD), &(server->map[y][x]));
}

static void		init_server_map(t_server *server)
{
  int			x;
  int			y;

  srand(time(NULL) + getpid());
  server->map = create_map(server->game_infos.size_x,
			   server->game_infos.size_y);
  y = 0;
  server_log(1, 0, "Generating world ...\n");
  while (y < server->game_infos.size_y)
    {
      x = 0;
      while (x < server->game_infos.size_x)
	{
	  server->map[y][x] = NULL;
	  init_map_case(server, y, x);
	  x++;
	}
      y++;
    }
  server_log(1, 0, "Done.\n");
}

int			init_server(t_server *server)
{
  server->stimeout = -1;
  server->teams = NULL;
  server->clients = NULL;
  server->awaiting_clients = NULL;
  server->graphical_clients = NULL;
  server->buffer = create_buffer_list();
  if (!init_ssocket(server))
    return (0);
  create_teams(server);
  init_elev(server);
  init_commands(server);
  init_ptrs(server);
  init_server_map(server);
  return (1);
}
