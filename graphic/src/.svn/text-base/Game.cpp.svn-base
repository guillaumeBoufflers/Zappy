#include "Game.hh"

Game::Game(int sizeX, int sizeY, int idTeam, Network *_network) : window(sf::VideoMode(W_WIDTH, W_HEIGHT), "Zappy Client"), requestThread(&Game::madeRequest, this), map(sizeX, sizeY), hud(), network(_network), parser(*this),posCamX(0), posCamY(0), frameNb(0), lastRefreshSince(0), zoomLevel(1), _unity(0), _add(false), _less(false)
{
	(void)idTeam;
}

Game::~Game() {}

void Game::setNewMap(int sizeX, int sizeY)
{
	map = GameMap(sizeX, sizeY);
}

GameMap &Game::getMap()
{
	return (map);
}

Hud 	&Game::getHud()
{
	return (hud);
}

void Game::launch()
{
	this->requestThread.launch();
	refreshDisplay();
	int 		xMouse;
	int 		yMouse;
	std::string	invent;

	while (window.isOpen())
	{
		sf::Event event;
		xMouse = event.mouseMove.x;
		yMouse = event.mouseMove.y;
		while (window.pollEvent(event))
		{
			switch (event.type)
    		{
    			case sf::Event::Closed:
    				window.close();
    				exit(0);
    			 	break;
    			case sf::Event::KeyPressed:
    				switch (event.key.code)
    			 	{
    					case sf::Keyboard::Left:
    			 			posCamX += MOVE_BY;
							refreshDisplay();
							break;
						case sf::Keyboard::Right:
							posCamX -= MOVE_BY;
							refreshDisplay();
							break;
						case sf::Keyboard::Up:
							posCamY += MOVE_BY;
						 	refreshDisplay();
						 	break;
						case sf::Keyboard::Down:
							posCamY -= MOVE_BY;
						 	refreshDisplay();
						 	break;
						case sf::Keyboard::P:
							if (_unity + 1 <= 500)
							{
								_unity += 1;
								_add = true;
							}
							break;
						case sf::Keyboard::M:
							if (_unity - 1 >= 1)
							{
								_less = true;
								_unity -= 1;
							}
							break;
						case sf::Keyboard::Add:
							if (zoomLevel <= 2.0)
								zoomLevel += 0.1;
							break;
						case sf::Keyboard::Subtract:
							if (zoomLevel >= 0.2)
								zoomLevel -= 0.1;
							break;
						case sf::Keyboard::Escape:
							window.close();
							exit(0);
							break;
    			 		default:
    			 			break;
    			 	}
    			 	break;
    			case sf::Event::MouseButtonPressed:
    				switch (event.mouseButton.button)
    				{
    					case sf::Mouse::Left:
    						invent = intToString(map.checkPosMouse(xMouse, yMouse));
							if (invent != "-1")
			 					network->addCmd("pin " + invent + "\n");
    						break;
    					default:
    						break;
    				}
    				break;
    			default:
    				break;
    		}
 		}
		if (lastRefreshSince >= 10)
			refreshDisplay();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) == false && sf::Keyboard::isKeyPressed(sf::Keyboard::M) == false)
		{
			if (_add == true || _less == true)
			{
				network->addCmd("sst " + intToString(static_cast<int>(_unity)) + "\n");
				_add = false;
				_less = false;
			}
		}
		window.display();
		++frameNb;
		++lastRefreshSince;
	}
}

void Game::refreshDisplay()
{
	lastRefreshSince = 0;
	window.clear();
	draw();
}

void Game::madeRequest()
{
	std::string ret;
	unsigned frameNb = 0;

	network->addCmd("mct\n");
	while (1)
	{
		while (network->getAnswerWithTimeout(ret))
		{
			this->mapMutex.lock();
			parser.parse(ret);
			this->mapMutex.unlock();
		}
		++frameNb;
		usleep(30);
	}
}

void Game::draw()
{
	this->mapMutex.lock();
	map.draw(posCamX, posCamY, zoomLevel, window);
	hud.draw(window);
	this->mapMutex.unlock();
}
void Game::setUnity(unsigned int unity)
{
	_unity = unity;
}
