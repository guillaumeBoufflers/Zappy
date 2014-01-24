#ifndef __HUD_HH__
#define __HUD_HH__

#include "common.hh"
#include "Object.hh"

class Hud
{
private:
	int				_width;
	int				_height;
	std::string 	_level;
	std::string		_unity;
	std::string 	_team;
	std::string		_name;
	std::string		_msg;
	bool			_drawInventory;
	std::map<objectType, sf::Sprite*> objectSprites;
	std::vector<std::string>		  _inventaires;
public:
	Hud();
	~Hud();
	void draw(sf::RenderWindow &window);
	void loadOneBitmap(objectType type, const char *file);
	void setPositionSprite();
	void drawText(const sf::Font &font, sf::RenderWindow &window) const;
	void fillInventory(const std::vector<std::string> & arg);
	void drawInventory(const sf::Font &font, sf::RenderWindow &window) const;	
	void setLevel(const std::string &);
	void setUnity(const std::string &);
	void setTeam(const std::string &);
	void setName(const std::string &);
	void setMsg(const std::string &);
};

#endif