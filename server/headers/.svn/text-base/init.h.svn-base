/*
** init.h for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/headers
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:44:22 2013 antoine knockaert
** Last update Sun Jul 14 18:44:23 2013 antoine knockaert
*/

#ifndef		INIT_H_
# define	INIT_H_

# include	<ctype.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<getopt.h>
# include	<netdb.h>
# include	"server.h"

extern char	*optarg;
extern int	optind;
extern int	opterr;
extern int	optopt;

int		init_server(t_server *server);
int		init_commands(t_server *server);
int		init_ptrs(t_server *server);
int		init_argc(t_server *server, int ac, char **av);
int		init_ssocket(t_server *server);
int		check_options_secu(t_server *server);
void		base_argc(t_server *server);
char		*strdup(char *);

#endif		/* !INIT_H_ */
