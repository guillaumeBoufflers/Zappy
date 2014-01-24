/*
** graphic_initialization.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/core
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:41:48 2013 antoine knockaert
** Last update Sun Jul 14 18:41:49 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"
#include		"client.h"

void			graphic_initialization(t_server *server,
					       t_client *client)
{
  if (client->is_graphic)
    {
      add_command_client(server, client, "msz");
      add_command_client(server, client, "sgt");
      add_command_client(server, client, "mct");
      add_command_client(server, client, "tna");
      add_command_client(server, client, "pnwa");
    }
}
