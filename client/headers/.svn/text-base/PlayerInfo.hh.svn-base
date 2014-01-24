#ifndef __PLAYERINFO__
#define __PLAYERINFO__

#include <string>
#include <vector>
#include "tools.hh"

enum objectNames { 
	FOOD = 0,
	LINEMATE,
	DERAUMERE,
	SIBUR,
	MENDIANE,
	PHIRAS,
	THYSTAME,
	END
};

class PlayerInfo
{
public:
	PlayerInfo();
	PlayerInfo(std::string _id, int level);
	~PlayerInfo();
	
	void initInventaire();
	void setInventaire(std::vector<std::string>);
	void setId(const std::string &_id);
	void setLevel(int l);
	void setIsAvailable(bool);

	bool isAvailable() const;

	std::vector<int> getInventaire() const;
	std::string getId() const;
	int getLevel() const;

	std::string id;
	int _level;
	bool 	_isAvailable;
	std::vector<int> _inventaire;
};

#endif