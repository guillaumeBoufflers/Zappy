/*
** elevation_end.c for zappt in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/actions/ia
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:32:40 2013 antoine knockaert
** Last update Sun Jul 14 18:32:41 2013 antoine knockaert
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

static void		clear_objet(t_object_list **list)
{
  t_object_list		*tmp;
  t_object_list		*tmp_ptr;

  tmp = (*list);
  while (tmp)
    {
      if (tmp->item->type != PLAYER)
	{
	  tmp_ptr = NULL;
	  move_object(tmp->item->type, list, &tmp_ptr);
	  free(tmp_ptr->item);
	  free(tmp_ptr);
	}
      tmp = tmp->next;
    }
}

static void		notification_elevation_end(t_server *serv, t_client *cl,
						   int res)
{
  char			*str;

  str = my_sprintf("pie %d %d %d\n", cl->pos_x, cl->pos_y, res);
  notification_graphical(serv, str);
  if (str)
    free(str);
}

static void		elevation_bis(t_server *serv, t_client *cl)
{
  char			*tmp;
  t_client_list		*list;

  if (verif_level(serv->clients, cl->level, cl->pos_x, cl->pos_y))
    {
      notification_elevation_end(serv, cl, 1);
      list = serv->clients;
      while (list && list->item)
	{
	  if (list->item->pos_x == cl->pos_x && list->item->pos_y == cl->pos_y)
	    {
	      list->item->level++;
	      tmp = my_sprintf("niveau actuel : %d\n",
			       list->item->level);
	      add_client_response(&list->item, tmp);
	      notification_graphical(serv, "plv %d %d\n", list->item->fd,
				     list->item->level);
	      free(tmp);
	    }
	  list = list->next;
	}
      clear_objet(&serv->map[cl->pos_y][cl->pos_x]);
    }
  else
    add_client_response(&cl, "ko\n");
}

void			elevation_end(t_server *serv, t_client *cl, char *cmd,
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
	  notification_elevation_end(serv, cl, 0);
	  add_client_response(&cl, "ko\n");
	  return ;
	}
      i++;
    }
  elevation_bis(serv, cl);
}
