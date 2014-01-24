#include "PlayerInfo.hh"

PlayerInfo::PlayerInfo() : _isAvailable(true)
{ 
	this->initInventaire(); 
}

PlayerInfo::PlayerInfo(std::string _id, int l) : id(_id), _level(l), _isAvailable(true)
{
	this->initInventaire();
	this->_inventaire.push_back(0);
}

PlayerInfo::~PlayerInfo()
{

}

void PlayerInfo::initInventaire()
{
	for (int i = 0 ; i < (int)END ; ++i)
		this->_inventaire.push_back(0);
}

void PlayerInfo::setInventaire(std::vector<std::string> inventaire)
{
	unsigned int i = 0;

	if (inventaire.size() < 7)
		return ;
	for (; i < inventaire.size() && i < this->_inventaire.size() ; ++i)
	{
		this->_inventaire[i] = stringToInt(inventaire[i]);				
	}
	if (inventaire[i] != "")
		this->_level = stringToInt(inventaire[i++]);
	if (inventaire[i] != "")
		this->_isAvailable = stringToInt(inventaire[i]);

}

void PlayerInfo::setId(const std::string &_id)
{
	id = _id;
}

std::vector<int> PlayerInfo::getInventaire() const
{
	return (this->_inventaire);
}

int PlayerInfo::getLevel() const
{
	return (this->_level);
}

bool PlayerInfo::isAvailable() const
{
	return (this->_isAvailable);
}

void PlayerInfo::setLevel(int l)
{
	this->_level = l;
}

void PlayerInfo::setIsAvailable(bool val)
{
	this->_isAvailable = val;
}

std::string PlayerInfo::getId() const
{
	return (id);
}
