/*
** base_init.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/init
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:45:34 2013 antoine knockaert
** Last update Sun Jul 14 18:45:35 2013 antoine knockaert
*/

#include		"init.h"
#include		"utils.h"

void			base_argc(t_server *server)
{
  server->game_infos.size_x = 20;
  server->game_infos.size_y = 20;
  server->game_infos.port = 4242;
  server->game_infos.time = 100;
  server->game_infos.nb_player_team = 20;
}

int			check_options_secu(t_server *server)
{
  if (server->game_infos.size_x < 3 || server->game_infos.size_y < 3 ||
      server->game_infos.port < 1024 || server->game_infos.time < 1 ||
      server->game_infos.nb_player_team < 1)
    {
      return (0);
    }
  return (1);
}
