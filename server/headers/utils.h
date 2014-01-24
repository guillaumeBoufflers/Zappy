/*
** utils.h for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/headers
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:44:52 2013 antoine knockaert
** Last update Sun Jul 14 18:44:52 2013 antoine knockaert
*/

#ifndef			UTILS_H_
# define		UTILS_H_

# include		<stdio.h>
# include		<stdarg.h>
# include		<stdlib.h>
# include		<sys/stat.h>
# include		<time.h>
# include		<fcntl.h>
# include		<errno.h>
# include		<strings.h>
# include		<string.h>
# include		"server.h"
# include		"buffer.h"

void			xwrite(int fd, char *str, int size);
char			*my_sprintf(char *format, ...);
void			init_logs(t_server *server);
void			server_log(char level, char exit, char *format, ...);
t_buffer		*create_list();
int			stock_in_buff(int fd, t_buffer *list);
int			write_socket(int fd, char *str);
int			is_alphnum(char *str);
int			is_alph(char *str);
int			is_num(char *str);
int			tablen(char **t);
char			**str_to_wordtab(char *str);
void			afftab(char **t);
char			*strdup(char *s);
int			vasprintf(char **strp, const char *fmt, va_list ap);
void			*xmalloc(int size);
int			enum_ret(char *str);
double			get_time_micro();
void			print_time(double time);
void			freetab(char **t);
void			notification_graphical(t_server *, char *, ...);
t_client		*client_by_id(t_server *, int);

#endif			/* !UTILS_H_ */
