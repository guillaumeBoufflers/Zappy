/*
** handle_client_write.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/core
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:42:51 2013 antoine knockaert
** Last update Sun Jul 14 18:42:52 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"
#include		"command.h"
#include		"client.h"

int			handle_client_write(t_client *client)
{
  t_write_buffer	*tmp;
  t_write_buffer	*tmp2;
  int			ret;

  ret = 0;
  if (client)
    {
      tmp = client->write_buffer;
      while (tmp)
	{
	  tmp2 = tmp;
	  ret += write_socket(client->fd, tmp->response);
	  tmp = tmp->next;
	  if (tmp2)
	    {
	      free(tmp2->response);
	      free(tmp2);
	    }
	}
      client->write_buffer = NULL;
    }
  return (ret);
}
