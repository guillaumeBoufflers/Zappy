/*
** prend.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/ia
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:34:15 2013 antoine knockaert
** Last update Sun Jul 14 18:34:16 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"

void			take_object_bis(t_server *serv, t_client *cl, int num)
{
  t_object_list		*tmp_ptr;

  tmp_ptr = NULL;
  if (num == FOOD)
    {
      move_object(num, &serv->map[cl->pos_y][cl->pos_x], &tmp_ptr);
      cl->life += 1;
      handle_food_pop(serv);
      free(tmp_ptr->item);
      free(tmp_ptr);
    }
  else
    move_object(num, &serv->map[cl->pos_y][cl->pos_x], &cl->inventory);
  notification_graphical(serv, "pgt %d %d\n", cl->fd, num);
  take_end(serv, cl);
  add_client_response(&cl, "ok\n");
}

void			take_object(t_server *serv, t_client *cl,
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
      content_case(FOOD, serv->map[cl->pos_y][cl->pos_x], &tb[0]);
      if (tb[tmp] == 0)
	add_client_response(&cl, "ko\n");
      else
	take_object_bis(serv, cl, tmp);
    }
}
