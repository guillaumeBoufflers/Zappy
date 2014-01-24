/*
** handle_new_connexion.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/core
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:43:01 2013 antoine knockaert
** Last update Sun Jul 14 20:05:06 2013 antoine knockaert
*/

#include	"server.h"
#include	"utils.h"

static void	create_client(t_server *server)
{
  t_client	*cli;

  cli = xmalloc(sizeof(t_client));
  cli->fd = server->cfd;
  cli->is_graphic = 0;
  cli->team = NULL;
  add_client_list(cli, &(server->awaiting_clients));
  add_client_response(&cli, "BIENVENUE\n");
}

void		handle_new_connexion(t_server *server)
{
  socklen_t	socklen;

  if (FD_ISSET(server->sfd, &(server->rfds)))
    {
      socklen = sizeof(struct sockaddr_in);
      server->cfd = accept(server->sfd, (struct sockaddr *) &(server->cin),
			   &socklen);
      if (server->cfd != -1)
	create_client(server);
      else
	server_log(4, 1, "Error on accept");
      server_log(1, 0, "New connexion accepted\n");
    }
}
