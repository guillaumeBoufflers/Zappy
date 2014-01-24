#include "GameMap.hh"

GameMap::GameMap(int _sizeX, int _sizeY)
{
	if (_sizeX <= 0 || _sizeY <= 0) {
		std::cerr << ">> Invalid map size." << std::endl;
		exit(0);
	}
	sizeX = _sizeX;
	sizeY = _sizeY;

	std::vector<IObject *> pileObj;
	std::vector<std::vector<IObject *> > tmp2;
	pileObj.clear();
	tmp2.clear();

	for (int y  = 0 ; y < sizeY ; ++y)
	{
		data.push_back(tmp2);
		for (int x  = 0 ; x < sizeX ; ++x)
		{
			data[y].push_back(pileObj);			
		}		
	}
	tmp2.push_back(pileObj);
	data.push_back(tmp2);
	loadOneBitmap(GROUND, "images/grass-low.png");
	loadOneBitmap(FOOD, "images/food.png");
	loadOneBitmap(LINEMATE, "images/linemate.png");
	loadOneBitmap(DERAUMERE, "images/deraumere.png");
	loadOneBitmap(SIBUR, "images/sibur.png");
	loadOneBitmap(MENDIANE, "images/mendiane.png");
	loadOneBitmap(PHIRAS, "images/phiras.png");
	loadOneBitmap(THYSTAME, "images/thystame.png");
	loadOneBitmap(PLAYER_N, "images/perso_top.png");
	loadOneBitmap(PLAYER_E, "images/perso_right.png");
	loadOneBitmap(PLAYER_S, "images/perso_bottom.png");
	loadOneBitmap(PLAYER_O, "images/perso_left.png");
	loadOneBitmap(EGG, "images/egg.png");
}


GameMap::~GameMap() {}

void GameMap::loadOneBitmap(objectType type, const char *file)
{
	sf::Texture *texture = new sf::Texture();
	sf::Sprite *sprite;
	if (texture->loadFromFile(file))
	{
		texture->setSmooth(true);
		sprite = new sf::Sprite();
		sprite->setTexture(*texture);
		objectSprites[type] = sprite;
	}
	else
	{
		std::cerr << "Error : bitmap non loaded." << std::endl;
		exit(0);
	}
}

bool GameMap::isValidPos(int x, int y) const 
{
	if (x < 0 || y < 0)
		return (false);
	if (x >= sizeX || y >= sizeY)
		return (false);
	return (true);
}

void GameMap::setCase(int x, int y, std::vector<int> &nbs)
{
	std::vector<IObject *> pileObj;

	if (!isValidPos(x, y))
		return ;
	data[y][x].clear();
	for (unsigned int i = 0 ; i < data[y][x].size() ; ++i)
		delete data[y][x][i];
	for (int i = 2 ; i <= 8 ; ++i)
	{
		for (int n = 0 ; nbs[i] - n > 0 ; ++n)
			data[y][x].push_back(new Object((objectType)(i - 2)));
	}
}


void GameMap::draw(int camPosX, int camPosY, float zoomLevel, sf::RenderWindow &window)
{
	int diffX = 101 * zoomLevel;
	int diffY = 48 * zoomLevel;
	int posX;
	int posY;
	unsigned int nbOnThisCase;

	for (int y = 0 ; y < sizeY ; ++y)
	{
		for (int x = 0 ; x < sizeX ; ++x)
		{
			posX = camPosX - (y * (diffX / 2)) + (x * (diffX / 2)) - (diffX / 2);
			posY = camPosY + (y * (diffY / 2)) + (x * (diffY / 2));
			if (isValidPos(x, y) && posX >= 0 - diffX && posX <= W_WIDTH + diffX && posY >= 0 - diffX && posY <= W_HEIGHT + diffX)
			{
				objectSprites[GROUND]->setPosition(sf::Vector2f(posX, posY));
				objectSprites[GROUND]->setScale(zoomLevel, zoomLevel);
				window.draw(*(objectSprites[GROUND]));
				nbOnThisCase = data[y][x].size();
				for (unsigned int i = 0 ; i < nbOnThisCase ; ++i)
				{
					if (nbOnThisCase % 2 == 1 && nbOnThisCase > 1)
						objectSprites[data[y][x][i]->getType()]->setPosition(sf::Vector2f(posX 
							+ ((i + 1) * (diffX / (nbOnThisCase) / 2)) 
							- (((nbOnThisCase) / 2) * (diffX / (nbOnThisCase) / 2)), posY));
					else
						objectSprites[data[y][x][i]->getType()]->setPosition(sf::Vector2f(posX 
							+ ((i + (nbOnThisCase > 1)) * (diffX / (nbOnThisCase) / 2)) 
							- (((nbOnThisCase) / 2) * (diffX / (nbOnThisCase) / 2)), posY));
					objectSprites[data[y][x][i]->getType()]->setScale(zoomLevel, zoomLevel);
					window.draw(*(objectSprites[data[y][x][i]->getType()]));
				}
			}
		}
	}
	for (unsigned int i = 0 ; i < players.size() ; ++i)
	{
		posX = camPosX - (players[i].getPosY() * (diffX / 2)) + (players[i].getPosX() * (diffX / 2)) - (diffX / 2);
		posY = camPosY + (players[i].getPosY() * (diffY / 2)) + (players[i].getPosX() * (diffY / 2));
		if (isValidPos(players[i].getPosX(), players[i].getPosY()) && posX >= 0 - diffX && posX <= W_WIDTH + diffX && posY >= 0 - diffX && posY <= W_HEIGHT + diffX)
		{
			objectSprites[players[i].getType()]->setPosition(sf::Vector2f(posX + ((diffX / 3)), posY - (diffY / 2))); // nice logic boell 0 * QUELQUE CHOSE //tg c'est pour garder qd meme ce quil y a apres histoire detre sur 
			players[i].setXPixel(posX);
			players[i].setYPixel(posY - (diffY / 2));
			objectSprites[players[i].getType()]->setScale(zoomLevel, zoomLevel);
			if (!players[i].getIncanting())
				objectSprites[players[i].getType()]->setColor(players[i].getColor());
			else
				objectSprites[players[i].getType()]->setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
			window.draw(*(objectSprites[players[i].getType()]));
		}
	}
	for (unsigned int i = 0; i < _egg.size() ; ++i)
	{
		posX = camPosX - (_egg[i].getPosY() * (diffX / 2)) + (_egg[i].getPosX() * (diffX / 2)) - (diffX / 2);
		posY = camPosY + (_egg[i].getPosY() * (diffY / 2)) + (_egg[i].getPosX() * (diffY / 2));
		if (isValidPos(_egg[i].getPosX(), _egg[i].getPosY()) && posX >= 0 - diffX && posX <= W_WIDTH + diffX && posY >= 0 - diffX && posY <= W_HEIGHT + diffX)
		{
				objectSprites[_egg[i].getType()]->setPosition(sf::Vector2f(posX + ((diffX / 3)), posY));
				objectSprites[_egg[i].getType()]->setScale(zoomLevel, zoomLevel);
				if (_egg[i].getEclosion() == 1)
					objectSprites[_egg[i].getType()]->setColor(_egg[i].getColor());
				else
					objectSprites[_egg[i].getType()]->setColor(sf::Color(255, 255, 255));
				window.draw(*(objectSprites[_egg[i].getType()]));
		}
	}
}

void GameMap::addPlayer(int id, int x, int y, int level, const std::string &equipe, const sf::Color &color, int xPixel, int yPixel)
{
	players.push_back(Player(PLAYER_N, id, x, y, level, equipe, color, xPixel, yPixel));
}

void GameMap::addResource(int x, int y, objectType type)
{
	if (isValidPos(x, y))
		data[y][x].push_back(new Object(type));
}

void GameMap::remResource(int x, int y, objectType type)
{
	if (!isValidPos(x, y))
		return ;
	for (unsigned int i = 0 ; i < data[y][x].size() ; ++i)
		if (data[y][x][i]->getType() == type)
		{
			data[y][x].erase(data[y][x].begin() + i);
			return ;
		}
}

void GameMap::addEgg(int id, int x, int y, const sf::Color &color)
{
	if (isValidPos(x, y))
		_egg.push_back(Egg(id, x, y, EGG, color));
}

void GameMap::setEclosionEgg(unsigned int id, int eclosion)
{
	for (unsigned int i = 0 ; i < _egg.size() ; ++i)
	{
		if (_egg[i].getId() == id)
			_egg[i].setEclosion(eclosion);
	}
}

void GameMap::setPosPlayer(unsigned int id, int x, int y)
{
	if (isValidPos(x, y))
		for (unsigned int i = 0 ; i < players.size() ; ++i)
			if (id == (players[i].getId()))
				players[i].setPos(x, y);
}

void GameMap::setType(int id, objectType newType)
{
	for (unsigned int i = 0 ; i < players.size(); ++i)
	{
		if (id == static_cast<int>((players[i].getId())))
			players[i].setType(newType);
	}
}

const Player &GameMap::getPlayer(unsigned int id) const 
{
	int j = 0;
	for (unsigned int i = 0; i < players.size(); ++i)
	{
		if (players[i].getId() == id)
			j = i;
	}
	return (players[j]);
}

bool GameMap::checkPlayers(unsigned int id) const
{
	for (unsigned int i = 0 ; i < players.size(); ++i)
	{
		if (players[i].getId() == id)
			return true;
	}
	return false;
}

bool GameMap::checkEgg(unsigned int id) const
{
	for (unsigned int i = 0; i < _egg.size(); ++i)
	{
		if (_egg[i].getId() == id)
			return true;
	}
	return false;
}

int GameMap::getPlayerNb() const
{
	return (players.size());
}

void GameMap::setLevelPlayer(unsigned int id, int level)
{
	for (unsigned int i = 0; i < players.size() ; ++i)
	{
		if (players[i].getId() == id)
		{
			players[i].setLevel(level);
			return;	
		}
	}
}

void GameMap::remPlayer(unsigned int id)
{
	for (unsigned int i = 0 ; i < players.size() ; ++i)
	{
		if (players[i].getId() == id)
		{
			players.erase(players.begin() += i);
			return ;
		}
	}
}

void 	GameMap::remEgg(unsigned int id)
{
	for (unsigned int i = 0; i < _egg.size() ; ++i)
	{
		if (_egg[i].getId() == id)
		{
			_egg.erase(_egg.begin() += i);
			return ;
		}
	}
}

int GameMap::getSizeX() const
{
	return (sizeX);
}

int GameMap::getSizeY() const
{
	return (sizeY);
}

int GameMap::checkPosMouse(int x, int y) const
{
	for (unsigned int i = 0 ; i < players.size() ; ++i)
	{
		if (x >= players[i].getXPixel() - 10 && x <= players[i].getXPixel() + 30 && y >= players[i].getYPixel() && y - 10 <= players[i].getYPixel() + 30)
			return (players[i].getId());
	}
	return (-1);
}

void GameMap::enableInvoc(std::vector<int> &args)
{
	if (args.size() > 3)
	{
		for (unsigned int i = 3 ; i < args.size() ; ++i)
		{
			for (unsigned int y = 0 ; y < players.size() ; ++y)
			{
				if (players[y].getId() == (unsigned int)args[i])
				{
					players[y].setIncanting(1);
					y = players.size() + 1;
				}
			}
		}
	}
}

void GameMap::disableInvoc(int x, int y)
{
	if (!isValidPos(x, y))
		return ;
	for (unsigned int i = 0 ; i < players.size() ; ++i)
	{
		if (players[i].getPosX() == x && players[i].getPosY() == y)
			players[i].setIncanting(0);
	}
}
