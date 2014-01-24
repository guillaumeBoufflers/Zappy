/*
** main.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/core
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:43:17 2013 antoine knockaert
** Last update Sun Jul 14 18:43:18 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"
#include		"buffer.h"
#include		"init.h"

int			main(int ac, char **av)
{
  t_server		server;

  if (ac >= 3)
    {
      g_server = &server;
      init_logs(&server);
      if (!init_argc(&server, ac, av))
	server_log(4, 1, "Usage: %s [-p port] [-x size_x > 3] [-y size_y > 3]\
[-c players_per_team] -n team1 team2 [team3] [-t time > 0]\n", av[0]);
      if (!init_server(&server))
	server_log(4, 0, "An error occured while initializing server.\n");
      server_loop(&server);
    }
  else
    server_log(4, 1, "Usage: %s [-p port] [-x size_x > 0] [-y size_y > 0]\
[-c players_per_team] -n team1 team2 [team3] [-t time > 0]\n", av[0]);
  return (0);
}
