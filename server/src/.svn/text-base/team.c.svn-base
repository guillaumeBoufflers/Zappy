/*
** team.c for toto in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/src
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:49:48 2013 antoine knockaert
** Last update Sun Jul 14 18:49:52 2013 antoine knockaert
*/

#include		"team.h"
#include		"server.h"

int			get_available_slots_team(t_server *server, char *team)
{
  t_team		*tmp;

  tmp = server->teams;
  while (tmp)
    {
      if (tmp && tmp->name && strcmp(team, tmp->name) == 0)
	return (tmp->slots_available);
      tmp = tmp->next;
    }
  return (-1);
}

void			remove_slot_team(t_server *server, char *team)
{
  t_team		*tmp;

  tmp = server->teams;
  while (tmp)
    {
      if (tmp && tmp->name && strcmp(team, tmp->name) == 0)
	if (tmp->slots_available > 0)
	  tmp->slots_available--;
      tmp = tmp->next;
    }
}

t_team			*get_team(t_server *server, char *team)
{
  t_team		*tmp;

  tmp = server->teams;
  while (tmp)
    {
      if (tmp && tmp->name && strcmp(team, tmp->name) == 0)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

void			add_slot_team(t_server *server, char *team)
{
  t_team		*tmp;

  tmp = server->teams;
  while (tmp)
    {
      if (tmp && tmp->name && strcmp(team, tmp->name) == 0)
	if (tmp->slots_available > 0)
	  tmp->slots_available++;
      tmp = tmp->next;
    }
}
