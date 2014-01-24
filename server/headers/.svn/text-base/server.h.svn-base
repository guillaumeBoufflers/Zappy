/*
** server.h for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/headers
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:44:37 2013 antoine knockaert
** Last update Sun Jul 14 18:44:38 2013 antoine knockaert
*/

#ifndef			SERVER_H_
# define		SERVER_H_

# include		<sys/types.h>
# include		<sys/time.h>
# include		<sys/select.h>
# include		<sys/socket.h>
# include		<netinet/in.h>
# include		<arpa/inet.h>
# include		<netinet/in.h>
# include		<arpa/inet.h>
# include		<unistd.h>
# include		"team.h"
# include		"client.h"
# include		"buffer.h"

# define		NB_COMMANDS_SERVER_CLI	14
# define		NB_COMMANDS_SERVER_GRA  11
# define		M_PI			3.14159265358979323846

typedef struct		s_infos
{
  char			*cport;
  char			*csize_x;
  char			*csize_y;
  char			*cnb_player_team;
  char			*ctime;
  int			port;
  int			size_x;
  int			size_y;
  int			nb_player_team;
  int			time;
  char			**teams;
}			t_infos;

typedef struct		s_server
{
  t_infos		game_infos;
  char			is_running;
  int			sfd;
  struct sockaddr_in	sin;
  int			cfd;
  struct sockaddr_in	cin;
  int			maxfd;
  double		stimeout;
  fd_set		rfds;
  fd_set		wfds;
  t_team		*teams;
  t_client_list		*clients;
  t_client_list		*awaiting_clients;
  t_client_list		*graphical_clients;
  t_buffer		*buffer;
  char			*commands_cli[NB_COMMANDS_SERVER_CLI];
  void			(*ptrs_cli[NB_COMMANDS_SERVER_CLI])(struct s_server
							    *server,
							    t_client *client,
							    char *command,
							    char **cmd);
  char			*commands_gra[NB_COMMANDS_SERVER_GRA];
  void			(*ptrs_gra[NB_COMMANDS_SERVER_GRA])(struct s_server
							    *server,
							    t_client *client,
							    char *command,
							    char **cmd);
  t_object_list		***map;
  int			tab_elev[7][8];
}			t_server;

t_server		*g_server;

void			reset_fdset(t_server *);
void			server_loop(t_server *);
void			handle_signal();
void			handle_new_connexion(t_server *);
void			handle_clients_awaiting(t_server *);
void			handle_clients(t_server *);
int			handle_client_write(t_client *);
void			content_case(t_object_types t, t_object_list *l,
				     int *tb);
char			*content_case_str(t_object_list *);
void			execute_action_client(t_server *, t_client *);
void			move_object(t_object_types type, t_object_list **list,
				    t_object_list **list2);
char                    *content_level(t_client *cl, int lvl, t_server *srv);
void			init_pos(t_client *cl, int *x, int *y, int lvl);
void			next_case(int *x, int *y, t_orientation dir);
void			replace_pos(int *x, int *y, t_server *srv);
char			*obj_to_str(t_object_types o);
t_object_list		***create_map(int sizex, int sizey);
void			see(t_server *serv, t_client *cl,
			    char *cmd, char **command);
int			val_dir(t_client *rc, t_client *sd, t_server *sv);
void			del_command_list(t_client *cl);
void			delete_client(t_client *client, t_client_list **list);
void			init_elev(t_server *serv);
void			send_inventory(t_client *, t_client *);
void			content_case_bct(t_server *, t_client *, int, int);
void			take_end(t_server *, t_client *);
void			quit_ctrl(int sig);
double			get_time_command(t_server *, char **);
void			handle_food_pop(t_server *server);

/*
 * Commandes du client IA
 */
void			move(t_server *serv, t_client *client, char *cmd,
			     char **command);
void			broadcast(t_server *serv, t_client *cl,
				  char *cmd, char **command);
void			right(t_server *serv, t_client *client, char *cmd,
			      char **command);
void			elevation_beg(t_server *serv, t_client *cl, char *cmd,
				      char **command);
void			elevation_end(t_server *serv, t_client *cl, char *cmd,
				      char **command);
void			pulse(t_server *serv, t_client *cl,
			      char *cmd, char **command);
void			left(t_server *serv, t_client *client, char *cmd,
			     char **command);
void			content_inventory(t_server *serv, t_client *cl,
					  char *cmd, char **command);
void			put_object(t_server *serv, t_client *cl,
				   char *cmd, char **command);
void			take_object(t_server *serv, t_client *cl,
				    char *cmd, char **command);
void			slot_available(t_server *serv, t_client *cl,
				       char *cmd, char **command);
void			fork_c(t_server *serv, t_client *cl,
			       char *cmd, char **command);



/*
 * Commandes de client graphique
 */
void			bct(t_server *server, t_client *client,
			    char *command, char **cmd);
void			mct(t_server *server, t_client *client,
			    char *command, char **cmd);
void			pin(t_server *server, t_client *client,
			    char *command, char **cmd);
void			msz(t_server *server, t_client *client,
			    char *command, char **cmd);
void			tna(t_server *server, t_client *client,
			    char *command, char **cmd);
void			ppo(t_server *server, t_client *client,
			    char *command, char **cmd);
void			plv(t_server *server, t_client *client,
			    char *command, char **cmd);
void			sgt(t_server *server, t_client *client,
			    char *command, char **cmd);
void			sst(t_server *server, t_client *client,
			    char *command, char **cmd);
void			pnwa(t_server *server, t_client *client,
			     char *command, char **cmd);




#endif			/* !SERVER_H_  */
