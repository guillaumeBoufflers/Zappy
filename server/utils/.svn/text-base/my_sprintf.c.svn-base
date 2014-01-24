/*
** my_sprintf.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/utils
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:53:16 2013 antoine knockaert
** Last update Sun Jul 14 18:53:16 2013 antoine knockaert
*/

#include		"utils.h"

#define			_GNU_SOURCE

char			*my_sprintf(char *format, ...)
{
  va_list		ap;
  char			*str;

  va_start(ap, format);
  vasprintf(&str, format, ap);
  if (!str)
    {
      perror("Error on malloc");
      exit(1);
    }
  va_end(ap);
  return (str);
}
