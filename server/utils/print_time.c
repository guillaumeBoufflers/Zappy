/*
** print_time.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/utils
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:53:31 2013 antoine knockaert
** Last update Sun Jul 14 18:53:31 2013 antoine knockaert
*/

#include		"utils.h"

void			print_time(double time)
{
  time_t		sec;
  struct tm		*nowtm;
  char			buffer[512];

  sec = (time_t) time;
  nowtm = localtime(&sec);
  strftime(buffer, 512, "%Y-%m-%d %H:%M:%S", nowtm);
  puts(buffer);
}
