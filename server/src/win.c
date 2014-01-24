/*
** win.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/src
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:50:10 2013 antoine knockaert
** Last update Sun Jul 14 18:50:11 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"

void			end_game(t_server *serv, t_team *team)
{
  t_client_list		*cl;

  cl = serv->clients;
  while (cl)
    {
      add_client_response(&cl->item, "mort\n");
      close_client_connexion(serv, cl->item, &cl);
      cl = cl->next;
    }
  cl = serv->graphical_clients;
  while (cl)
    {
      add_client_response(&cl->item, my_sprintf("seg %s\n", team->name));
      close_client_connexion(serv, cl->item, &cl);
      cl = cl->next;
    }
}

void			equip_win(t_server *serv)
{
  t_team		*tmp;
  t_client_list		*tmp2;
  int			max_level;

  tmp = serv->teams;
  while (tmp)
    {
      max_level = 0;
      tmp2 = serv->clients;
      while (tmp2)
	{
	  if (tmp2->item->team == tmp && tmp2->item->level == 8)
	    max_level++;
	  tmp2 = tmp2->next;
	}
      if (max_level == 6)
	{
	  end_game(serv, tmp);
	  return ;
	}
      tmp = tmp->next;
    }
}
