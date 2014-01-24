/*
** command.h for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/headers
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:44:16 2013 antoine knockaert
** Last update Sun Jul 14 18:44:17 2013 antoine knockaert
*/

#ifndef			COMMAND_H_
# define		COMMAND_H_

typedef struct		s_command
{
  char			*command;
  char			**split_command;
  int			index;
  double		time_exec;
  double		duration;
  struct s_command	*next;
}			t_command;

t_command		*create_tcommand(t_command **list, char *command);
void			delete_command(t_command *, t_command **);

#endif			/* !COMMAND_H_ */
