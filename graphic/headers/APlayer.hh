#ifndef __APLAYER_HH__
#define __APLAYER_HH__

#include <string>
#include "IPlayer.hh"
#include "AObject.hh"
#include "common.hh"

class APlayer : public AObject
{
private:
	unsigned int	id;
	int				posX;
	int				posY;
	int				level;
	bool			_isIncanting;
	std::string		team;

public:
	APlayer(objectType _type);
	APlayer(objectType _type, int _id, int _x, int _y, int _level, const std::string &_equipe);
	~APlayer();

	virtual int getPosX() const;
	virtual int getPosY() const;
	virtual void setPos(int x, int y);
	virtual unsigned int getId() const;
	virtual int getLevel() const;
	virtual void setLevel(int);
	virtual const std::string &getTeamName() const;
	virtual bool getIncanting() const;
	virtual void setIncanting(bool i);
};

#endif
