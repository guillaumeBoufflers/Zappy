#include "Player.hh"

Player::Player(objectType _type, int id, int x, int y, int level, const std::string &equipe, const sf::Color &color, int xPixel, int yPixel) : APlayer(_type, id, x, y, level, equipe), _color(color), _xPixel(xPixel), _yPixel(yPixel), _isIncanting(false)
{

}

Player::~Player() {}

int Player::getXPixel() const
{
	return (_xPixel);
}

int Player::getYPixel() const
{
	return (_yPixel);
}

void Player::setXPixel(int x)
{
	_xPixel = x;
}

void Player::setYPixel(int y)
{
	_yPixel = y;
}

void Player::setColor(const sf::Color & newColor)
{
	_color = newColor;
}

const sf::Color &Player::getColor() const
{
	return (_color);
}

bool Player::getIncanting() const
{
	return (_isIncanting);
}

void Player::setIncanting(bool i)
{
	_isIncanting = i;
}
