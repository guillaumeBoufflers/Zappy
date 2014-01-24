/*
** time.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/utils
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:53:58 2013 antoine knockaert
** Last update Sun Jul 14 18:53:58 2013 antoine knockaert
*/

#include		<time.h>
#include		<sys/time.h>
#include		<sys/types.h>
#include		"utils.h"

double			get_time_micro()
{
  struct timeval	tv;
  double		time;

  if (gettimeofday(&(tv), NULL) == 0)
    {
      time = (double) tv.tv_sec + (0.000001f * tv.tv_usec);
      return (time);
    }
  else
    return (0);
}
