#include <iostream>
#include <unistd.h>
#include "Game.hh"

Game::Game(Network *network, const std::string &team) : _network(network), _team(team), _isRunning(true)
{

}

Game::~Game() {}

void Game::loop()
{
	std::string action;

	(this->*_tabActions["inventaire"])();
	while (this->_isRunning)
	{
		if (this->_network->canPush())
		{
			this->_IA->handleAnswer(this->_network->getTask());
			action = this->_IA->chooseAction();
			if (this->_tabActions.find(action) != this->_tabActions.end())
			{
		 	(this->*_tabActions[action])();				
			}
		}
		if (this->_network->getBroadcastSize() >= 1)
		{
			this->_IA->hasReceivedBroad();
			this->_IA->setBroad(this->_network->popBroadcast());
		}
		usleep(100);
	}
}

void Game::launch(const std::string &id)
{
	std::string action;
	std::string tmp;

	this->_IA = new IA(this->_team);
	this->_IA->init(id);
	this->loop();
}

bool Game::connection()
{
	std::string ret("");
	if (!this->_network->init())
		return (false);
	if (this->_network->getAnswerWithTimeout(ret) && ret == "BIENVENUE")
	{
		this->_network->addCmd(_team + "\n");
		if (this->_network->getAnswerWithTimeout(ret))
		{
			if (stringToInt(ret) < 1)
				return (false);
		}
	}
	this->initTabActions();
	return (true);
}

void Game::initTabActions()
{
	this->_tabActions["avance"] = &Game::avance;
	this->_tabActions["droite"] = &Game::droite;
	this->_tabActions["gauche"] = &Game::gauche;
	this->_tabActions["voir"] = &Game::voir;
	this->_tabActions["inventaire"] = &Game::inventaire;
	this->_tabActions["prendObjet"] = &Game::prendObjet;
	this->_tabActions["poseObjet"] = &Game::poseObjet;
	this->_tabActions["expulse"] = &Game::expulse;
	this->_tabActions["broadcast"] = &Game::broadcast;
	this->_tabActions["incantation"] = &Game::incantation;
	this->_tabActions["fork"] = &Game::fork;
}

void Game::avance()
{
	this->_network->addCmd("avance\n");
}

void Game::gauche()
{
	this->_network->addCmd("gauche\n");
}

void Game::droite()
{
	this->_network->addCmd("droite\n");
}

void Game::voir()
{
	this->_network->addCmd("voir\n");
}

void Game::inventaire()
{
	this->_network->addCmd("inventaire\n");
}

void Game::poseObjet()
{
	std::string tmp;

	tmp = this->_IA->getTexte();
	this->_network->addCmd(tmp);
}

void Game::prendObjet()
{
	std::string tmp;

	tmp = this->_IA->getTexte();
	this->_network->addCmd(tmp);
}

void Game::expulse()
{
	this->_network->addCmd("expulse\n");
}

void Game::broadcast()
{
	std::string tmp;

	tmp = this->_IA->getTexte();
	tmp += "\n";
	this->_network->addCmd(tmp);
}

void Game::incantation()
{
	this->_network->addCmd("incantation\n");
}

void Game::fork()
{
	this->_network->addCmd("fork\n");
}

void Game::endGame()
{
	this->_isRunning = false;
}
