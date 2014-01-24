/*
** client.h for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/headers
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:44:09 2013 antoine knockaert
** Last update Sun Jul 14 18:44:10 2013 antoine knockaert
*/

#ifndef			CLIENT_H_
# define		CLIENT_H_

# include		"object.h"
# include		"command.h"
# include		"team.h"

struct			s_server;

typedef enum		e_orientation
{
  NORTH=1,
  EST,
  SOUTH,
  WEST
}			t_orientation;

typedef struct		s_write_buffer
{
  char			*response;
  struct s_write_buffer	*next;
}			t_write_buffer;

typedef struct		s_client
{
  char			is_graphic;
  int			fd;
  t_team		*team;
  t_object		*player;
  t_command		*cmds;
  t_write_buffer	*write_buffer;
  t_object_list		*inventory;
  int			life;
  double		life_timeout;
  int			pos_x;
  int			pos_y;
  int			level;
  t_orientation		dir;
}			t_client;

typedef struct		s_client_list
{
  t_client		*item;
  struct s_client_list	*next;
  struct s_client_list	*prev;
}			t_client_list;

void			add_client_list(t_client *, t_client_list **);
void			add_client_response(t_client **, char *);
void			delete_client(t_client *, t_client_list **);
void			free_client(t_client *client);
void			close_client_connexion(struct s_server *, t_client *,
					       t_client_list **);
void			execute_actions_client(struct s_server *, t_client *);
void			graphic_initialization(struct s_server *, t_client *);
void			add_command_client(struct s_server *, t_client *,
					   char *);

#endif			/* !CLIENT_H_  */
