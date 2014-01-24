/*
** expulse.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/ia
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:33:02 2013 antoine knockaert
** Last update Sun Jul 14 18:33:12 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"

static void		pulse_mvm(int *x, int *y, t_orientation dir,
				  t_server *serv)
{
  int			tmpx;
  int			tmpy;

  tmpx = *x;
  tmpy = *y;
  if (dir == SOUTH)
    *y = (*y + 1) % serv->game_infos.size_y;
  else if (dir == NORTH)
    *y = (*y - 1 >= 0) ? (*y - 1) :
      (serv->game_infos.size_y - 1);
  else if (dir == EST)
    *x = (*x + 1) % serv->game_infos.size_x;
  else
    *x = (*x - 1 >= 0) ? (*x - 1) :
      (serv->game_infos.size_x - 1);
  move_object(PLAYER, &serv->map[tmpy][tmpx], &serv->map[*y][*x]);
}

static void		execute_pulse(t_server *serv, t_client *cl)
{
  t_client_list		*tmp;
  char			*str;

  tmp = serv->clients;
  while (tmp)
    {
      if (tmp->item && tmp->item->pos_x == cl->pos_x &&
	  tmp->item->pos_y == cl->pos_y && tmp->item != cl)
	{
	  notification_graphical(serv, "ppo %d %d %d %d\n", tmp->item->fd,
				 tmp->item->pos_x, tmp->item->pos_y,
				 tmp->item->dir);
	  pulse_mvm(&tmp->item->pos_x, &tmp->item->pos_y, cl->dir, serv);
	  str = my_sprintf("pulse %d\n", val_dir(tmp->item, cl, serv));
	  del_command_list(tmp->item);
	  add_client_response(&tmp->item, str);
	}
      tmp = tmp->next;
    }
}

void			pulse(t_server *serv, t_client *cl,
			    char *cmd, char **command)
{
  (void) cmd;
  if (command[1])
    {
      add_client_response(&cl, "sbp\n");
      return ;
    }
  notification_graphical(serv, "pex %d\n", cl->fd);
  execute_pulse(serv, cl);
 add_client_response(&cl, "ok\n");
}
