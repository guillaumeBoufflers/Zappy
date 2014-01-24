#ifndef __PLAYER_HH__
#define __PLAYER_HH__

#include "APlayer.hh"

class Player : public APlayer
{
	sf::Color   	_color;
	int		_xPixel;
	int		_yPixel;
	bool	_isIncanting;
public:
	Player(objectType _type, int id, int x, int y, int level, const std::string &equipe, const sf::Color &color, int xPixel, int yPixel);
	~Player();
	int getXPixel() const;
	int getYPixel() const;
	void setXPixel(int);
	void setYPixel(int);
	void setColor(const sf::Color &);
	const sf::Color &getColor() const;
	bool getIncanting() const;
	void setIncanting(bool i);

};

#endif
