#ifndef __GAMEMAP_HH__
#define __GAMEMAP_HH__

#include <vector>
#include <map>
#include "Object.hh"
#include "Player.hh"
#include "common.hh"
#include "Egg.hh"

class GameMap
{
public:
	GameMap(int sizeX, int sizeY);
	~GameMap();
	int getSizeX() const;
	int getSizeY() const;
	void draw(int posCamX, int posCamY, float zoomLevel, sf::RenderWindow &window);
	void loadOneBitmap(objectType type, const char *file);
	bool isValidPos(int x, int y) const;
	void setCase(int x, int y, std::vector<int> &objs);
	const Player &getPlayer(unsigned int id) const;
	int  getPlayerNb() const;
	void addPlayer(int id, int x, int y, int level, const std::string &equipe, const sf::Color &color, int xPixel, int yPixel);
	void addResource(int x, int y, objectType type);
	void remPlayer(unsigned int id);
	void remEgg(unsigned int id);
	bool checkEgg(unsigned int id) const;
	bool checkPlayers(unsigned int id) const;
	void setPosPlayer(unsigned int id, int x, int y);
	void setLevelPlayer(unsigned int id, int level);
	void addEgg(int id, int x ,int y, const sf::Color &color);
	void setEclosionEgg(unsigned int id, int eclosion);
	int checkPosMouse(int x, int y) const;
	void setType(int id, objectType newType);
	void enableInvoc(std::vector<int> &args);
	void remResource(int x, int y, objectType type);
	void disableInvoc(int x, int y);
private:
	std::vector<std::vector<std::vector<IObject *> > > data;
	std::vector<Player> players;
	std::vector<Egg>	_egg;
	std::map<objectType, sf::Sprite*> objectSprites;
	int sizeX;
	int sizeY;
};

#endif
