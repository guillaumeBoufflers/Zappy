/*
** buffer.h for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/headers
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:44:04 2013 antoine knockaert
** Last update Sun Jul 14 18:44:04 2013 antoine knockaert
*/

#ifndef			BUFFER_H_
# define		BUFFER_H_

# include		<unistd.h>
# include		<stdlib.h>
# include		<strings.h>
# include		<string.h>

typedef struct		s_buffer
{
  char			buff[512];
  struct s_buffer	*next;
}			t_buffer;

t_buffer		*create_buffer_list();
int			stock_in_buff();
char			*build_buff_command(t_buffer **);
int			write_socket(int, char *);

#endif			/* !BUFFER_H_ */
