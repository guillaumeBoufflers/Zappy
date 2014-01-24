/*
** gest_response.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/src
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:49:15 2013 antoine knockaert
** Last update Sun Jul 14 18:49:16 2013 antoine knockaert
*/

#include		"utils.h"
#include		"server.h"

void			add_client_response(t_client **client, char *response)
{
  t_write_buffer	*new;
  t_write_buffer	*tmp;

  new = xmalloc(sizeof(t_write_buffer));
  new->response = strdup(response);
  if ((*client)->write_buffer == NULL)
    (*client)->write_buffer = new;
  else
    {
      tmp = (*client)->write_buffer;
      while ((*client)->write_buffer->next)
	(*client)->write_buffer = (*client)->write_buffer->next;
      (*client)->write_buffer->next = new;
      (*client)->write_buffer = tmp;
    }
}

