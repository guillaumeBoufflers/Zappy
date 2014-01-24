/*
** handle_clients.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/core
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:42:20 2013 antoine knockaert
** Last update Sun Jul 14 18:42:20 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"
#include		"command.h"
#include		"client.h"

double			get_time_command(t_server *server, char **cmd)
{
  if (cmd && cmd[0])
    {
      if (strcmp(cmd[0], "connect_nbr") == 0)
	return ((double) 0);
      else if (strcmp(cmd[0], "fork") == 0)
	return ((double) ((double) 42) / ((double) server->game_infos.time));
      else if (strcmp(cmd[0], "incantation") == 0)
	return (0);
      else if (strcmp(cmd[0], "incantation_end") == 0)
	return ((double) ((double) 300) / ((double) server->game_infos.time));
      else if (strcmp(cmd[0], "inventaire") == 0)
	return ((double) ((double) 1) / ((double) server->game_infos.time));
      else
	return ((double) ((double) 7) / ((double) server->game_infos.time));
    }
  return (0);
}

static void		add_command_client_end(t_server *server,
					       t_client *client,
					       char *command,
					       int index)
{
  t_command		*tcommand;

  tcommand = create_tcommand(&(client->cmds), command);
  tcommand->split_command = str_to_wordtab(command);
  tcommand->index = index;
  tcommand->time_exec = 0;
  if (client->is_graphic)
    tcommand->duration = 0;
  else
    tcommand->duration = get_time_command(server, tcommand->split_command);
  server_log(1, 0, "New command for client %d : \"%s\"\n", client->fd, command);
  if (!(tcommand && tcommand->command && tcommand->split_command
	&& tcommand->split_command[0]))
    {
      server_log(3, 0, "Cannot create command for client %d\n", client->fd);
      delete_command(tcommand, &(client->cmds));
    }
}

void			add_command_client(t_server *server,
					   t_client *client,
					   char *command)
{
  int			i;
  char			**tmp;
  char			**cmd;

  i = 0;
  cmd = str_to_wordtab(command);
  if (client->is_graphic)
    tmp = server->commands_gra;
  else
    tmp = server->commands_cli;
  while (tmp && tmp[i])
    {
      if (cmd && cmd[0] && strcmp(cmd[0], tmp[i]) == 0)
	{
	  freetab(cmd);
	  add_command_client_end(server, client, command, i);
	  return ;
	}
      i++;
    }
  if (cmd)
    freetab(cmd);
  add_client_response(&(client), "suc\n");
}

void			handle_clients(t_server *server)
{
  t_client_list		*tmp;
  char			to_delete;

  tmp = server->clients;
  while (tmp)
    {
      to_delete = 0;
      if (tmp->item && FD_ISSET(tmp->item->fd, &(server->wfds)))
	if (handle_client_write(tmp->item) != 0)
	  to_delete = 1;
      if (tmp->item && FD_ISSET(tmp->item->fd, &(server->rfds)))
	{
	  if (stock_in_buff(tmp->item->fd, server->buffer) == -1)
	    to_delete = 1;
	  else
	    add_command_client(server, tmp->item,
			       build_buff_command(&(server->buffer)));
	}
      if (!to_delete && tmp->item)
	execute_actions_client(server, tmp->item);
      if (to_delete && tmp->item)
	close_client_connexion(server, tmp->item, &(server->clients));
      tmp = tmp->next;
    }
}
