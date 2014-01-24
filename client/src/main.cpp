#include  <iostream>
#include "Network.hh"
#include "Game.hh"
#include "tools.hh"

void  handle_game(const std::string &ip, const int &port, const std::string &team)
{
  std::string id(intToString(time(NULL)  + getpid() + rand() % 424242));

  Network *network = new Network(ip, port, id);
  Game *game = new Game(network, team);
  if (game->connection())
    game->launch(id);
  else
    {
      std::cout << "Connexion failed !" << std::endl;
      return ;
    }
}

bool		check_arguments(char **av, int args)
{
  std::string	tmp;
  std::string	sip("127.0.0.1");
  int		ip;
  int		port;
  int		name;
  int		i = 1;

  while (i < args)
    {
      if (i % 2 != 0)
	{
	  tmp = av[i];
	  if (tmp == "-n")
	    name = i + 1;
	  else if (tmp == "-h")
	    ip = i + 1;
	  else if (tmp == "-p")
	    port = i + 1;
	  else
	    return (true);
	}
      i++;
    }
  if (args == 7)
    handle_game(av[ip], atoi(av[port]), av[name]);
  else
    handle_game(sip, atoi(av[port]), av[name]);
  return (false);
}

int main(int ac, char **av)
{
  srand((time(NULL) + getpid()));
  if (check_arguments(av, ac) == true)
    {
      std::cout << "Usage: " << av[0] << " -n team -h ip -p port" << std::endl;
      return (1);
    }
  return (0);
}
