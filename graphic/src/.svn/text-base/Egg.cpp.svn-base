#include "Egg.hh"

Egg::Egg(int id, int x, int y, objectType type, const sf::Color &color):
	 AObject(type) , _id(id), _posX(x), _posY(y), _color(color), _eclosion(0)
{
}

Egg::~Egg()
{
}

void	Egg::setPosX(int x)
{
	_posX = x;
}

void	Egg::setPosY(int y)
{
	_posY = y;
}

void	Egg::setEclosion(unsigned int eclosion)
{
	_eclosion = eclosion;
}

int		Egg::getPosX() const
{
	return (_posX);
}

int		Egg::getPosY() const
{
	return (_posY);
}

unsigned int	Egg::getId() const
{
	return (_id);
}

void			Egg::setColor(const sf::Color &color)
{
	_color = color;
}

const sf::Color		&Egg::getColor() const
{
	return (_color);
}

unsigned int	Egg::getEclosion() const
{
	return (_eclosion);
}