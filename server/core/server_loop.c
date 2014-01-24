/*
** server_loop.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/core
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:43:32 2013 antoine knockaert
** Last update Sun Jul 14 18:43:32 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"

static int		find_highest(t_server *server)
{
  int			max;
  t_client_list		*tmp;

  max = server->sfd;
  tmp = server->clients;
  while (tmp)
    {
      if (tmp->item && tmp->item->fd > max)
	max = tmp->item->fd;
      tmp = tmp->next;
    }
  tmp = server->awaiting_clients;
  while (tmp)
    {
      if (tmp->item && tmp->item->fd > max)
	max = tmp->item->fd;
      tmp = tmp->next;
    }
  return (max);
}

static void		update_food_gra(t_server *server, int x, int y)
{
  t_client_list		*tmp;

  tmp = server->graphical_clients;
  while (tmp)
    {
      if (tmp->item)
	content_case_bct(server, tmp->item, x, y);
      tmp = tmp->next;
    }
}

void			handle_food_pop(t_server *server)
{
  int			i;
  int			x;
  int			y;

  i = 0;
  server_log(1, 0, "Don't worry, be happy ! Food pop !\n");
  x = rand() % server->game_infos.size_x;
  y = rand() % server->game_infos.size_y;
  new_object_list(new_object(FOOD), &(server->map[y][x]));
  update_food_gra(server, x, y);
  i++;
}

static void		set_timeout(t_server *server, struct timeval *tm)
{
  double		ct;
  int			sec;
  double		timeout;
  int			micro;

  ct = get_time_micro();
  if (server->stimeout != -1 && server->stimeout > ct)
    {
      timeout = server->stimeout - ct - 1;
      if (timeout < 0)
	timeout = 0;
      sec = (int) timeout;
      timeout = (timeout - (double) sec) * 1000000;
      micro = (int) timeout;
    }
  else
    {
      sec = 0;
      micro = 1000;
    }
  tm->tv_sec = sec;
  tm->tv_usec = micro;
}

void			server_loop(t_server *server)
{
  struct timeval	timeout;

  while (42)
    {
      handle_signal();
      reset_fdset(server);
      set_timeout(server, &timeout);
      if (select(find_highest(server) + 1, &(server->rfds), &(server->wfds),
		 NULL, &timeout) == -1)
	perror("Error on select");
      server->stimeout = -1;
      handle_new_connexion(server);
      handle_clients(server);
      handle_clients_awaiting(server);
    }
}
