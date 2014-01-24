/*
** del_list.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/src
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:48:56 2013 antoine knockaert
** Last update Sun Jul 14 18:49:02 2013 antoine knockaert
*/

#include	"utils.h"
#include	"server.h"

void		delete_command(t_command *command, t_command **list)
{
  t_command	*tmp;
  t_command	*tfree;

  if (command && command->command)
    free(command->command);
  if (command && command->split_command)
    freetab(command->split_command);
  if ((*list) && command && (*list) == command)
    (*list) = (*list)->next;
  else
    {
      tmp = (*list);
      while (tmp && tmp->next != command)
	tmp = tmp->next;
      if (tmp && tmp->next)
	{
	  tfree = tmp->next;
	  tmp->next = tmp->next->next;
	  free(tfree);
	}
    }
}

void		move_object(t_object_types type, t_object_list **list,
			    t_object_list **list2)
{
  t_object_list	*tmp;

  while ((*list) && (*list)->prev)
    (*list) = (*list)->prev;
  tmp = (*list);
  while ((*list) && (*list)->item->type != type)
    (*list) = (*list)->next;
  if (tmp && (*list) == tmp && tmp->prev)
    tmp = tmp->prev;
  if (tmp && (*list) == tmp)
    tmp = tmp->next;
  if ((*list) && (*list)->item->type == type)
    {
      if ((*list)->prev)
	(*list)->prev->next = (*list)->next;
      if ((*list)->next)
	(*list)->next->prev = (*list)->prev;
      (*list)->next = (*list2);
      (*list)->prev = NULL;
      if (*list2)
	(*list2)->prev = (*list);
      (*list2) = (*list);
    }
  (*list) = tmp;
}

void		del_command_list(t_client *cl)
{
  t_command	*tmp;

  tmp = cl->cmds;
  while (tmp)
    {
      if (strcmp("ok\n", tmp->command) == 0)
	{
	  delete_command(tmp, &cl->cmds);
	  add_client_response(&cl, "ko\n");
	}
      tmp = tmp->next;
    }
}

void		delete_client(t_client *client, t_client_list **list)
{
  t_client_list	*tmp;

  tmp = (*list);
  while (tmp && tmp->item != client)
    tmp = tmp->next;
  if (tmp && tmp == (*list) && (*list)->prev)
    (*list) = (*list)->prev;
  if (tmp && tmp == (*list))
    (*list) = (*list)->next;
  if (tmp && tmp->prev)
    tmp->prev->next = tmp->next;
  if (tmp && tmp->next)
    tmp->next->prev = tmp->prev;
}
