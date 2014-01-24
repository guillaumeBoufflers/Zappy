/*
** init_ssocket.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/init
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:46:26 2013 antoine knockaert
** Last update Sun Jul 14 18:46:27 2013 antoine knockaert
*/

#include		"init.h"

int			init_ssocket(t_server *server)
{
  struct protoent	*pe;
  int			ret;

  if ((pe = getprotobyname("TCP")) == NULL)
    return (0);
  server->sfd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (server->sfd == -1)
    return (0);
  server->sin.sin_family = AF_INET;
  server->sin.sin_port = htons(server->game_infos.port);
  server->sin.sin_addr.s_addr = htonl(INADDR_ANY);
  ret = bind(server->sfd, (const struct sockaddr*) &(server->sin),
	     sizeof(struct sockaddr_in));
  if (ret == -1)
    return (0);
  if (listen(server->sfd, 100) == -1)
    return (0);
  server->maxfd = server->sfd;
  FD_ZERO(&(server->rfds));
  FD_ZERO(&(server->wfds));
  return (1);
}
