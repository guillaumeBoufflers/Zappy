/*
** log.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/utils
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:53:08 2013 antoine knockaert
** Last update Sun Jul 14 18:53:09 2013 antoine knockaert
*/

#include		"server.h"
#include		"utils.h"

void			init_logs(t_server *server)
{
  int			fd;

  (void) server;
  fd = open("server.log", O_WRONLY | O_CREAT, 0644);
  if (fd == -1)
    {
      perror("Cannot init log files");
      xwrite(2, "[Info] : Logs will not be reported anymore\n", 43);
    }
}

static void		get_date(char *str)
{
  time_t		now;
  struct tm		*tm;

  bzero(str, 128);
  now = time(NULL);
  tm = localtime(&now);
  strftime(str, 128, "[%d/%m/%Y - %H:%M:%S] - ", tm);
}

static void		write_level(int fd, char level)
{
  if (level == 1)
    xwrite(fd, "[Info] - ", 9);
  if (level == 2)
    xwrite(fd, "[Warning] - ", 12);
  if (level == 3)
    xwrite(fd, "[Error] - ", 10);
  if (level == 4)
    xwrite(fd, "[Fatal-error] - ", 16);
}

static void		write_log(char *str, char level)
{
  if (level == 1)
    printf("\033[36m");
  else if (level == 2)
    printf("\033[33m");
  else if (level > 2)
    printf("\033[31m");
  else
    printf("\033[0m");
  fflush(stdout);
  write_level(1, level);
  printf("%s", str);
  printf("\033[0m");
  fflush(stdout);
  if (str)
    free(str);
}

void			server_log(char level, char nexit, char *format, ...)
{
  va_list		ap;
  char			*str;
  char			date[128];
  int			fd;

  va_start(ap, format);
  vasprintf(&str, format, ap);
  if (!str)
    {
      perror("Error on malloc");
      exit(1);
    }
  va_end(ap);
  get_date(date);
  fd = open("server.log", O_WRONLY | O_APPEND);
  if (fd != -1)
    {
      xwrite(fd, date, strlen(date));
      write_level(fd, level);
      xwrite(fd, str, strlen(str));
      close(fd);
    }
  write_log(str, level);
  if (nexit)
    exit(1);
}
