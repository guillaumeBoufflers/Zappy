/*
** map.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/src
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:49:35 2013 antoine knockaert
** Last update Sun Jul 14 18:49:36 2013 antoine knockaert
*/

#include		<stdlib.h>
#include		"object.h"
#include		"utils.h"
#include		"server.h"

t_object_list		***create_map(int sizex, int sizey)
{
  t_object_list		***map;
  int			i;

  i = -1;
  map = xmalloc(sizeof(t_object_list **) * (sizey + 1));
  while (i++ < sizey)
    map[i] = xmalloc(sizeof(t_object_list *) * (sizex + 1));
  return (map);
}

void			content_case(t_object_types t, t_object_list *l,
				     int *tb)
{
  t_object_list		*tmp;

  tmp = l;
  if (!tb)
    server_log(4, 1, "An error occured with map.");
  while (tmp)
    {
      if (tmp->item->type == t)
	tb[t] = tb[t] + 1;
      tmp = tmp->next;
    }
  if (t < 8)
    content_case(t + 1, l, tb);
}

char			*content_case_str(t_object_list *list)
{
  t_object_list		*tmp;
  char			*str;

  tmp = list;
  str = NULL;
  while (tmp)
    {
      str = my_sprintf("%s %s", (str) ? (str) : (""),
		       obj_to_str(tmp->item->type));
      tmp = tmp->next;
    }
  return ((str) ? (str) : (""));
}

char			*content_level(t_client *cl, int lvl, t_server *srv)
{
  char			*str;
  int			x;
  int			y;
  int			i;

  str = NULL;
  i = -lvl;
  init_pos(cl, &x, &y, lvl);
  while (i <= lvl)
    {
      replace_pos(&x, &y, srv);
      str = my_sprintf("%s%s," , (str) ? (str) : (""),
		       content_case_str(srv->map[y][x]));
      next_case(&x, &y, cl->dir);
      i++;
    }
  return (str);
}

int			has_player(t_object_list *list)
{
  while (list)
    {
      if (list->item->type == PLAYER)
	return (1);
      list = list->next;
    }
  return (0);
}
