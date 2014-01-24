/*
** add_list.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/src
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:48:39 2013 antoine knockaert
** Last update Sun Jul 14 18:48:40 2013 antoine knockaert
*/

#include	"utils.h"
#include	"server.h"

t_command	*create_tcommand(t_command **list, char *command)
{
  t_command	*newr;
  t_command	*tmp;

  newr = xmalloc(sizeof(t_command));
  newr->command = strdup(command);
  if ((*list) == NULL)
    (*list) = newr;
  else
    {
      tmp = (*list);
      while ((*list)->next)
	(*list) = (*list)->next;
      (*list)->next = newr;
      (*list) = tmp;
     }
  return (newr);
}

void		create_tteam(t_team **list, char *name_team, int nb_slot)
{
  t_team	*newr;
  t_team	*tmp;

  newr = xmalloc(sizeof(t_team));
  newr->name = strdup(name_team);
  newr->slots_available = nb_slot;
  if ((*list) == NULL)
    (*list) = newr;
  else
    {
      tmp = (*list);
      while ((*list)->next)
	(*list) = (*list)->next;
      (*list)->next = newr;
      (*list) = tmp;
     }
}

void		add_client_list(t_client *newcl, t_client_list **list)
{
  t_client_list	*newr;

  newr = xmalloc(sizeof(t_client_list));
  newr->item = newcl;
  if ((*list) == NULL)
    (*list) = newr;
  else
    {
      newr->next = (*list);
      if ((*list))
	(*list)->prev = newr;
      (*list) = newr;
    }
}

void		new_object_list(t_object *newcl, t_object_list **list)
{
  t_object_list	*new;

  new = xmalloc(sizeof(t_object_list));
  new->item = newcl;
  if ((*list) == NULL)
    (*list) = new;
  else
    {
      new->next = (*list);
      (*list)->prev = new;
      (*list) = new;
    }
}

t_object		*new_object(t_object_types type)
{
  t_object	*ret;

  ret = xmalloc(sizeof(t_object));
  ret->type = type;
  return (ret);
}
