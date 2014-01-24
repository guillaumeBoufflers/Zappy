#include "APlayer.hh"

APlayer::APlayer(objectType _type) : AObject(_type)
{

}

APlayer::APlayer(objectType _type, int _id, int _x, int _y, int _level, const std::string &_equipe) : AObject(_type), id(_id), posX(_x), posY(_y), level(_level), team(_equipe)
{

}

APlayer::~APlayer() {}

int APlayer::getPosX() const
{
	return (posX);
}

int APlayer::getPosY() const
{
	return (posY);
}

void APlayer::setPos(int x, int y)
{
	posX = x;
	posY = y;
}

unsigned int APlayer::getId() const
{
	return (id);
}

int APlayer::getLevel() const
{
	return (level);
}

void APlayer::setLevel(int trueLevel)
{
	level = trueLevel;
}

const std::string &APlayer::getTeamName() const
{
	return (team);
}

bool APlayer::getIncanting() const
{
	return (_isIncanting);
}

void APlayer::setIncanting(bool i)
{
	_isIncanting = i;
}
