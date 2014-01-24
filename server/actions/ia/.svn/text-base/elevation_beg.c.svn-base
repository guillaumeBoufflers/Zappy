/*
** elevation_beg.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/ia
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:32:09 2013 antoine knockaert
** Last update Sun Jul 14 18:32:09 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"

static int		verif_level(t_client_list *list, int level,
				    int x, int y)
{
  t_client_list		*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->item->pos_x == x && tmp->item->pos_y == y)
	if (tmp->item->level != level)
	  return (0);
      tmp = tmp->next;
    }
  return (1);
}

static char		*create_notification(t_server *serv, t_client *cl)
{
  char			*notif;
  char			*tmp;
  t_client_list		*list;

  notif = my_sprintf("pic %d %d %d %d", cl->pos_x, cl->pos_y,
		     cl->level + 1, cl->fd);
  list = serv->clients;
  while (list)
    {
      if (list->item && list->item->pos_x == cl->pos_x &&
	  list->item->pos_y == cl->pos_y && list->item != cl)
	{
	  tmp = notif;
	  notif = my_sprintf("%s %d", notif, list->item->fd);
	  if (tmp)
	    free(tmp);
	}
      list = list->next;
    }
  tmp = notif;
  notif = my_sprintf("%s\n", notif);
  if (tmp)
    free(tmp);
  return (notif);
}

static void		create_elevation_command(t_server *server,
						 t_client *cl)
{
  t_command		*cmd;
  t_command		*tmp;

  cmd = xmalloc(sizeof(t_command));
  cmd->command = strdup("incantation_end");
  cmd->split_command = str_to_wordtab(cmd->command);
  cmd->index = 12;
  cmd->time_exec = 0;
  cmd->duration = get_time_command(server, cmd->split_command);
  tmp = cl->cmds;
  if (tmp)
    {
      cmd->next = tmp->next;
      tmp->next = cmd;
    }
  else
    cl->cmds = cmd;
}

static void		elevation_bis(t_server *serv, t_client *cl)
{
  char			*tmp;
  char			*notif;

  if (verif_level(serv->clients, cl->level, cl->pos_x, cl->pos_y))
    {
      tmp = my_sprintf("elevation en cours\n");
      add_client_response(&cl, tmp);
      free(tmp);
      notif = create_notification(serv, cl);
      notification_graphical(serv, notif);
      create_elevation_command(serv, cl);
    }
  else
    add_client_response(&cl, "ko\n");
}

void			elevation_beg(t_server *serv, t_client *cl, char *cmd,
				      char **command)
{
  int			tb[8];
  int			i;

  i = 0;
  bzero(tb, sizeof(int) * 8);
  if (tablen(command) > 1 || cmd == NULL)
    {
      add_client_response(&cl, "sbp\n");
      return ;
    }
  content_case(FOOD, serv->map[cl->pos_y][cl->pos_x], &tb[0]);
  while (i < 8)
    {
      if (serv->tab_elev[cl->level - 1][i] != tb[i])
	{
	  add_client_response(&cl, "ko\n");
	  return ;
	}
      i++;
    }
  elevation_bis(serv, cl);
}
