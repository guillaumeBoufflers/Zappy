/*
** handle_signal.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/core
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:43:10 2013 antoine knockaert
** Last update Sun Jul 14 18:43:10 2013 antoine knockaert
*/

#include		<signal.h>
#include		"server.h"
#include		"utils.h"

void			quit_ctrl(int sig)
{
  t_server		*server;

  (void) sig;
  server = g_server;
  printf("\n");
  server_log(2, 0, "Interrupt system called detected, Exiting server ...\n");
  close(server->sfd);
  exit(1);
}

void			handle_signal()
{
  signal(SIGINT, &quit_ctrl);
}
