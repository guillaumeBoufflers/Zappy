/*
** calc_pos.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/utils
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:51:25 2013 antoine knockaert
** Last update Sun Jul 14 18:51:25 2013 antoine knockaert
*/

#include		<math.h>
#include		"server.h"

void			next_case(int *x, int *y, t_orientation dir)
{
  if (dir == SOUTH)
    *x = *x + 1;
  else if (dir == NORTH)
    *x = *x - 1;
  else if (dir == EST)
    *y = *y - 1;
  else
    *y = *y + 1;
}

void			replace_pos(int *x, int *y, t_server *srv)
{
  if (srv->game_infos.size_x - 1 < *x)
    *x = 0;
  if (0 > *x)
    *x = srv->game_infos.size_x - 1;
  if (srv->game_infos.size_y - 1 < *y)
    *y = 0;
  if (0 > *y)
    *y = srv->game_infos.size_y - 1;
}
