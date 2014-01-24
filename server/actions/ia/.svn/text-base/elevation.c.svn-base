
#include		"server.h"
#include		"utils.h"

int			verif_level(t_client_list *list, int level,
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

void			clear_objet(t_object_list **list)
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

void			elevation_bis(t_server *serv, t_client *cl)
{
  char			*tmp;
  t_client_list		*list;

  tmp = my_sprintf("elevation en cours\nniveau actuel : %d\n",
		   cl->level);
  if (verif_level(serv->clients, cl->level, cl->pos_x, cl->pos_y))
    {
      list = serv->clients;
      while (list)
	{
	  if (list->item->pos_x == cl->pos_x && list->item->pos_y == cl->pos_y)
	    {
	      add_client_response(&list->item, tmp);
	      list->item->level++;
	    }
	  list = list->next;
	}
      clear_objet(&serv->map[cl->pos_y][cl->pos_x]);
    }
  else
    add_client_response(&cl, "ko\n");
  free(tmp);
}

void			elevation(t_server *serv, t_client *cl, char *cmd,
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
