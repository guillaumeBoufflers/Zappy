#include "common.hh"
#include "Game.hh"
#include "Network.hh"
#include "gtk/gtk.h"
#include <cstdlib>
#include <X11/Xlib.h>

bool connection(Network *network)
{
  std::string ret = "";

  if (!network->init())
    return (false);
  std::cout << "Connected to server." << std::endl;
  if (network->getAnswerWithTimeout(ret) && ret == "BIENVENUE")
  {
    std::cout << "~~ Le serveur vous dis bienvenue ~~" << std::endl;
    network->addCmd("GRAPHIC\n");
    return (true);
  }
  return (false);
}

int main(int argc, char **argv)
{
  int port;

  gtk_init(&argc, &argv);
  if (argc < 3 || argc > 3)
  {
    std::cerr << "Error, the argument are ip and port\nUsage :./zappy_graphic ip port" << std::endl;
    return (0);
  }
  std::string ip(argv[1]);
  port = atoi(argv[2]);
  XInitThreads();
  Network *network = new Network(ip, port, "0");
  srand(time(NULL));
  if (connection(network))
    {
      Game game(10, 10, 1, network);
      game.launch();
    }
  return (0);
}


