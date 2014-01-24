/*
** init_argc.c for zappy in /home/knocka_a/rendu-epitech/git-repositories/zappy/server/init
**
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
**
** Started on  Sun Jul 14 18:45:40 2013 antoine knockaert
** Last update Sun Jul 14 18:45:41 2013 antoine knockaert
*/

#include		"init.h"
#include		"utils.h"

static int		count_teams(int ac, char **av)
{
  int			i;
  int			size;

  i = 1;
  size = 0;
  while (i < ac && strcmp(av[i], "-n") != 0)
    i++;
  i++;
  while (i < ac && av[i][0] != '-')
    {
      size++;
      i++;
    }
  return (size);
}

static int		parse_teams(t_server *server, int ac, char **av)
{
  int			size;
  int			i;
  int			j;

  i = 1;
  j = 0;
  size = count_teams(ac, av);
  if (!size)
    exit(fprintf(stderr, "Please add one team before starting.\n"));
  server->game_infos.teams = xmalloc((size + 1) * sizeof(char *));
  while (i < ac && strcmp(av[i], "-n") != 0)
    i++;
  i++;
  while (i < ac && av[i][0] != '-')
    {
      server->game_infos.teams[j] = strdup(av[i]);
      i++;
      j++;
    }
  server->game_infos.teams[j] = NULL;
  return (1);
}

static int		check_options(t_server *server)
{
  if (server->game_infos.cport && !is_num(server->game_infos.cport))
    return (fprintf(stderr, "Port must be a integer > 1024.\n"));
  if (server->game_infos.cport)
    server->game_infos.port = atoi(server->game_infos.cport);
  if (server->game_infos.csize_x && !is_num(server->game_infos.csize_x))
    return (fprintf(stderr, "X size must be a positive integer.\n"));
  if (server->game_infos.csize_x)
    server->game_infos.size_x = atoi(server->game_infos.csize_x);
  if (server->game_infos.csize_y && !is_num(server->game_infos.csize_y))
    return (fprintf(stderr, "Y size must be a positive integer.\n"));
  if (server->game_infos.csize_y)
    server->game_infos.size_y = atoi(server->game_infos.csize_y);
  if (server->game_infos.cnb_player_team &&
      !is_num(server->game_infos.cnb_player_team))
    return (fprintf(stderr, "Nb. Players/team must be a positive integer.\n"));
  if (server->game_infos.cnb_player_team)
    server->game_infos.nb_player_team =
      atoi(server->game_infos.cnb_player_team);
  if (server->game_infos.ctime && !is_num(server->game_infos.ctime))
    return (fprintf(stderr, "Time must be a positive integer.\n"));
  if (server->game_infos.ctime)
    server->game_infos.time = atoi(server->game_infos.ctime);
  return (0);
}

static void		parse_options(t_server *server, int ac, char **av)
{
  char			c;

  while ((c = getopt(ac, av, "p:x:y:c:t:n:")) != -1)
    {
      if (c == 'p')
	server->game_infos.cport = optarg;
      else if (c == 'x')
	server->game_infos.csize_x = optarg;
      else if (c == 'y')
	server->game_infos.csize_y = optarg;
      else if (c == 'c')
	server->game_infos.cnb_player_team = optarg;
      else if (c == 't')
	server->game_infos.ctime = optarg;
      else if (c == '?')
	{
	  if (optopt != 'p' && optopt != 'x' && optopt != 'y' && optopt != 'c'
	      && optopt != 't')
	    exit(fprintf(stderr, "Unknown option '-%c'.\n", optopt));
	}
    }
}

int			init_argc(t_server *server, int ac, char **av)
{
  bzero(&(server->game_infos), sizeof(t_infos));
  base_argc(server);
  if (!parse_teams(server, ac, av))
    return (0);
  parse_options(server, ac, av);
  if (check_options(server) != 0)
    return (0);
  if (check_options_secu(server) == 0)
    return (0);
  return (1);
}
