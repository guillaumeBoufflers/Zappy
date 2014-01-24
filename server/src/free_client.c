/*
** free_client.c for free_client in /home/knocka_a/rendu-epitech/git-repositories/zappy/server
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Wed Jun 19 17:47:11 2013 antoine knockaert
** Last update Sat Jul 13 11:34:49 2013 antoine knockaert
*/

#include		<stdlib.h>
#include		"client.h"

static void		free_client_commands(t_client *client)
{
  t_command		*tmp;
  t_command		*tmp2;

  tmp = client->cmds;
  while (tmp)
    {
      tmp2 = tmp;
      tmp = tmp->next;
      if (tmp2)
	free(tmp2);
    }
}

static void		free_write_buffer(t_client *client)
{
  t_write_buffer	*tmp;
  t_write_buffer	*tmp2;

  tmp = client->write_buffer;
  while (tmp)
    {
      tmp2 = tmp;
      tmp = tmp->next;
      if (tmp2)
	free(tmp2);
    }
}

static void		free_inventory(t_client *client)
{
  t_object_list		*tmp;
  t_object_list		*tmp2;

  tmp = client->inventory;
  while (tmp)
    {
      tmp2 = tmp;
      tmp = tmp->next;
      if (tmp2)
	{
	  free(tmp2->item);
	  free(tmp2);
	}
    }
}

void			free_client(t_client *client)
{
  if (client)
    {
      free_client_commands(client);
      free_write_buffer(client);
      free_inventory(client);
      free(client);
    }
}
