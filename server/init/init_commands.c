/*
** init_commands.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/init
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:45:52 2013 antoine knockaert
** Last update Sun Jul 14 18:45:53 2013 antoine knockaert
*/

#include		"init.h"

static void		init_commands_ia(t_server *server)
{
  server->commands_cli[0] = strdup("avance");
  server->commands_cli[1] = strdup("droite");
  server->commands_cli[2] = strdup("gauche");
  server->commands_cli[3] = strdup("voir");
  server->commands_cli[4] = strdup("inventaire");
  server->commands_cli[5] = strdup("prend");
  server->commands_cli[6] = strdup("pose");
  server->commands_cli[7] = strdup("expulse");
  server->commands_cli[8] = strdup("broadcast");
  server->commands_cli[9] = strdup("incantation");
  server->commands_cli[10] = strdup("fork");
  server->commands_cli[11] = strdup("connect_nbr");
  server->commands_cli[12] = NULL;
  server->commands_cli[13] = NULL;
}

static void		init_commands_graphic(t_server *server)
{
  server->commands_gra[0] = strdup("msz");
  server->commands_gra[1] = strdup("bct");
  server->commands_gra[2] = strdup("mct");
  server->commands_gra[3] = strdup("tna");
  server->commands_gra[4] = strdup("ppo");
  server->commands_gra[5] = strdup("plv");
  server->commands_gra[6] = strdup("pin");
  server->commands_gra[7] = strdup("sgt");
  server->commands_gra[8] = strdup("sst");
  server->commands_gra[9] = strdup("pnwa");
  server->commands_gra[10] = NULL;
}

int			init_commands(t_server *server)
{
  init_commands_ia(server);
  init_commands_graphic(server);
  return (1);
}
