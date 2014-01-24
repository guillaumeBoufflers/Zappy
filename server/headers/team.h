/*
** team.h for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/headers
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:44:43 2013 antoine knockaert
** Last update Sun Jul 14 18:44:44 2013 antoine knockaert
*/

#ifndef			TEAM_H_
# define		TEAM_H_

struct			s_server;

typedef struct		s_team
{
  char			*name;
  int			slots_available;
  struct s_team		*next;
}			t_team;

int			get_available_slots_team(struct s_server *, char *);
void			remove_slot_team(struct s_server *, char *);
t_team			*get_team(struct s_server *, char *);
void			add_slot_team(struct s_server *, char *);
void			create_tteam(t_team **, char *, int);

#endif			/* !TEAM_H_ */
