/*
** execute_action_client.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/core
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:41:08 2013 antoine knockaert
** Last update Sun Jul 14 18:41:09 2013 antoine knockaert
*/

#include		"server.h"
#include		"client.h"
#include		"utils.h"
#include		"command.h"

static void		set_command_date(t_server *server, t_command *command)
{
  command->time_exec = get_time_micro() + (double) command->duration;
  if (server->stimeout == (double) -1 || command->time_exec < server->stimeout)
    server->stimeout = command->time_exec;
}

static void		handle_client_life(t_server *server, t_client *client)
{
  if (!client->is_graphic)
    {
      if (client->life_timeout == (double) -1)
	client->life_timeout = get_time_micro() +
	  ((double) 126 / (double) server->game_infos.time);
      if (client->life_timeout <= get_time_micro())
	{
	  server_log(2, 0, "Client %d lifes decreases. %d remain\n",
		     client->fd, client->life);
	  client->life--;
	  if (client->life == 0)
	    {
	      server_log(2, 0, "Client %d is dead.\n", client->fd);
	      add_client_response(&(client), "mort\n");
	      close_client_connexion(server, client, &(server->clients));
	      return ;
	    }
	  client->life_timeout = get_time_micro() +
	    ((double) 126 / (double) server->game_infos.time);
	}
      if (server->stimeout == (double) -1 ||
	  client->life_timeout <= server->stimeout)
	server->stimeout = client->life_timeout;
    }
}

void			execute_actions_client(t_server *server,
					       t_client *cl)
{
  if (cl->cmds && cl->fd && cl->fd != -1)
    {
      if (!cl->cmds->time_exec)
	set_command_date(server, cl->cmds);
      if (cl->cmds->time_exec &&
	  cl->cmds->time_exec <= get_time_micro())
	{
	  if (cl->is_graphic && cl->cmds->index >= 0 &&
	      cl->cmds->index < NB_COMMANDS_SERVER_GRA &&
	      server->ptrs_gra[cl->cmds->index])
	    server->ptrs_gra[cl->cmds->index](server, cl,
					      cl->cmds->command,
					      cl->cmds->split_command);
	  else if (!cl->is_graphic && cl->cmds->index >= 0 &&
		   cl->cmds->index < NB_COMMANDS_SERVER_CLI &&
		   server->ptrs_cli[cl->cmds->index])
	    server->ptrs_cli[cl->cmds->index](server, cl,
					      cl->cmds->command,
					      cl->cmds->split_command);
	  else
	    server_log(3, 0, "Command of client %d not executed.\n", cl->fd);
	  delete_command(cl->cmds, &(cl->cmds));
	}
    }
  handle_client_life(server, cl);
}
