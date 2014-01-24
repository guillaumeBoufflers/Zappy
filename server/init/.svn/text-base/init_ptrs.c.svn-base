/*
** init_ptrs.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/init
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:46:10 2013 antoine knockaert
** Last update Sun Jul 14 18:46:10 2013 antoine knockaert
*/

#include		"server.h"
#include		"init.h"

static void		init_ptrs_ia(t_server *server)
{
  server->ptrs_cli[0] = &move;
  server->ptrs_cli[1] = &right;
  server->ptrs_cli[2] = &left;
  server->ptrs_cli[3] = &see;
  server->ptrs_cli[4] = &content_inventory;
  server->ptrs_cli[5] = &take_object;
  server->ptrs_cli[6] = &put_object;
  server->ptrs_cli[7] = &pulse;
  server->ptrs_cli[8] = &broadcast;
  server->ptrs_cli[9] = &elevation_beg;
  server->ptrs_cli[10] = &fork_c;
  server->ptrs_cli[11] = NULL;
  server->ptrs_cli[12] = &elevation_end;
  server->ptrs_cli[13] = NULL;
}

static void		init_ptrs_graphic(t_server *server)
{
  server->ptrs_gra[0] = &msz;
  server->ptrs_gra[1] = &bct;
  server->ptrs_gra[2] = &mct;
  server->ptrs_gra[3] = &tna;
  server->ptrs_gra[4] = &ppo;
  server->ptrs_gra[5] = &plv;
  server->ptrs_gra[6] = &pin;
  server->ptrs_gra[7] = &sgt;
  server->ptrs_gra[8] = &sst;
  server->ptrs_gra[9] = &pnwa;
  server->ptrs_gra[10] = NULL;
}

int			init_ptrs(t_server *server)
{
  init_ptrs_ia(server);
  init_ptrs_graphic(server);
  return (1);
}
