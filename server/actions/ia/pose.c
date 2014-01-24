/*
** pose.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/ia
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:34:09 2013 antoine knockaert
** Last update Sun Jul 14 18:34:10 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"

void			put_object(t_server *serv, t_client *cl,
				    char *cmd, char **command)
{
  int			tb[8];
  int			tmp;

  (void) cmd;
  bzero(tb, sizeof(int) * 8);
  if (!command[1] || (tmp = enum_ret(command[1])) == -1)
    add_client_response(&cl, "sbp\n");
  else
    {
      content_case(LINEMATE, cl->inventory, &tb[0]);
      if (tb[tmp] == -1)
	add_client_response(&cl, "ko\n");
      else
	{
	  move_object(tmp,
		      &cl->inventory,
		      &serv->map[cl->pos_y][cl->pos_x]);
	  notification_graphical(serv, "pdr %d %d\n", cl->fd, tmp);
	  add_client_response(&cl, "ok\n");
	}
    }
}
