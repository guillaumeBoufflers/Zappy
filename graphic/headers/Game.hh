#ifndef __GAME_HH__
#define __GAME_HH__

#include <unistd.h>
#include "common.hh"
#include "GameMap.hh"
#include "Network.hh"
#include "Parser.hh"
#include "tools.hh"
#include "Hud.hh"

class GameMap;

class Game
{
public:
	Game(int sizeX, int sizeY, int idTeam, Network *network);
	~Game();
	void madeRequest();
	void launch();
	void draw();
	void setNewMap(int sizeX, int sizeY);
	GameMap &getMap();
	Hud 	&getHud();
	void refreshDisplay();
	void setUnity(unsigned int);
private:
	sf::RenderWindow window;
	sf::Event event;
	sf::Mutex	mapMutex;
	sf::Thread requestThread;
	GameMap map;
	Hud		hud;
	Network *network;
	Parser parser;
	int posCamX;
	int posCamY;
	int frameNb;
	int lastRefreshSince;
	float zoomLevel;
	unsigned int	_unity;
	bool			_add;
	bool			_less;
};

#endif
