#ifndef	__EGG_HH__
#define	__EGG_HH__

#include "IObject.hh"
#include "AObject.hh"
#include "common.hh"

class Egg : public AObject
{
private:
	unsigned int	_id;
	int				_posX;
	int				_posY;
	objectType		_type;
	sf::Color		_color;
	unsigned int	_eclosion;
public:
	Egg(int, int, int, objectType, const sf::Color &color);
	~Egg();
	void	setPosX(int);
	void	setPosY(int);
	void 	setColor(const sf::Color &);
	void	setEclosion(unsigned int);
	int		getPosX() const;
	int		getPosY() const;
	unsigned int		getId() const;
	unsigned int 	getEclosion() const;
	const sf::Color 	&getColor() const;

	/* data */
};
#endif