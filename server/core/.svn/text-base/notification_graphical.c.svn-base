/*
** notification_channel.c for notification in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/core
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul  7 14:58:19 2013 antoine knockaert
** Last update Sun Jul  7 15:03:30 2013 antoine knockaert
*/

#include		"server.h"
#include		"client.h"
#include		"utils.h"

#define			_GNU_SOURCE

static void		send_notification(t_server *server, char *str)
{
  t_client_list		*tmp;

  tmp = server->graphical_clients;
  while (tmp)
    {
      if (tmp && tmp->item && tmp->item->is_graphic)
	add_client_response(&(tmp->item), str);
      tmp = tmp->next;
    }
  free(str);
}

void			notification_graphical(t_server *server, char *format,
					       ...)
{
  va_list		ap;
  char			*str;

  va_start(ap, format);
  vasprintf(&str, format, ap);
  if (!str)
    {
      perror("Error on malloc");
      exit(1);
    }
  va_end(ap);
  send_notification(server, str);
}
