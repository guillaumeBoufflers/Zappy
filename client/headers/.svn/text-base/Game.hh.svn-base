#ifndef __GAME_HH__
#define __GAME_HH__

#include	<utility>
#include  	<map>
#include	"Network.hh"
#include 	"IA.hh"

class Game
{
public:
	Game(Network *network, const std::string &team);
	~Game();
	void launch(const std::string &);
	bool connection();
	void initTabActions();
	void loop();
private:
	Network *_network;
	std::string _team;
	std::map<std::string, void(Game::*)(void)> _tabActions;
	IA 		*_IA;
	bool _isRunning;
private:
	void avance();
	void droite();
	void gauche();
	void voir();
	void inventaire();
	void poseObjet();
	void prendObjet();
	void expulse();
	void broadcast();
	void incantation();
	void fork();
	void endGame();
public:
};

#endif
