/*
** calc.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/utils
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:51:16 2013 antoine knockaert
** Last update Sun Jul 14 18:51:17 2013 antoine knockaert
*/

#include		<math.h>
#include		"server.h"

int			val_incidence(double a, int sign)
{
  double		b;

  b = (int)((180 / M_PI) * acos(a));
  b = b * sign;
  if (b > -45 && b < 45)
    return (1);
  else if (b > 45 && b < 135)
    return (7);
  else if (b > 135 && b < -135)
    return (5);
  else if (b < -45 && b > -135)
    return (3);
  else if (b == 45)
    return (8);
  else if (b == 135)
    return (6);
  else if (b == -45)
    return (2);
  else if (b == -135)
    return (4);
  else
    return (1);
}

int			calc_dist(int d1, int d2, int size)
{
  if (abs(d1 - d2) > abs(d1 - (-size + 1 + d2)))
    return (-size + 1 + d2);
  else if (abs(d1 - d2) > abs(d1 - (size - 1 + d2)))
    return (size - 1 + d2);
  else
    return (d2);
}

int			val_dir(t_client *rc, t_client *sd, t_server *sv)
{
  int			x;
  int			y;
  int			x1;
  int			y1;
  double		a;
  double		ux;
  double		uy;
  double		vx;
  double		vy;

  x = calc_dist(rc->pos_x, sd->pos_x, sv->game_infos.size_x);
  y = calc_dist(rc->pos_y, sd->pos_y, sv->game_infos.size_y);
  y1 = (rc->dir == SOUTH) ? (rc->pos_y + 1) : ((rc->dir == NORTH) ?
					       (rc->pos_y - 1) : (rc->pos_y));
  x1 = (rc->dir == EST) ? (rc->pos_x + 1) : ((rc->dir == WEST) ? (rc->pos_x - 1)
					   : (rc->pos_x));
  ux = x - rc->pos_x;
  uy = y - rc->pos_y;
  vx = x1 - rc->pos_x;
  vy = y1 - rc->pos_y;
  a = (double)((ux * vx + uy * vy) /
	       (sqrt(fabs(ux * ux + uy * uy)) * sqrt(fabs(vx * vx + vy * vy))));
  return (val_incidence(a, ((ux * vy - uy * vx) > 0) ? (1) : (-1)));
}

void			init_pos(t_client *cl, int *x, int *y, int lvl)
{
  *x = cl->pos_x;
  *y = cl->pos_y;
  if (cl->dir == SOUTH)
    {
      *y = *y + lvl;
      *x = *x - lvl;
    }
  else if (cl->dir == NORTH)
    {
      *y = *y - lvl;
      *x = *x + lvl;
    }
  else if (cl->dir == EST)
    {
      *x = *x + lvl;
      *y = *y + lvl;
    }
  else
    {
      *x = *x - lvl;
      *y = *y - lvl;
    }
}

