#include "IA.hh"
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <utility>

IA::IA(const std::string &team) :_team(team), _action("broadcast"), _message("lol"), _id(""), _dest(""), _objetToFind("nourriture") , _chief(""),
_level(1),  _mustSee(0), _mustUpdateInventory(1),  _isAvailable(true),
_isChief(false), _hasReceivedBroad(true), _hadSee(false), _canTakeObj(false), _isSearchingSomething(false),
_hasToUpdateInventory(false), _hasToBroadcastInventory(false), _isSearchingForMe(true), _hasEnoughItemsForLevel(false),
_canEventuallyEvolve(false), _isAtRightPlace(false), _needToClearPlace(false),
_needToTakeFood(false), _needToFillList(false), _hasFilledList(false), _needToBreakGroup(false),
_direction(FRONT), _rejoinCase(-1), _timeSinceFollow(0), _chiefError(0), _isTimeToTake(0), _etapeDeath(0)
{
	this->levelDef(2, 0, 1, 0, 0, 0, 0, 0, 1);
	this->levelDef(3, 0, 1, 1, 1, 0, 0, 0, 2);
	this->levelDef(4, 0, 2, 0, 1, 0, 2, 0, 2);
	this->levelDef(5, 0, 1, 1, 2, 0, 1, 0, 4);
	this->levelDef(6, 0, 1, 2, 1, 3, 0, 0, 4);
	this->levelDef(7, 0, 1, 2, 3, 0, 1, 0, 6);
	this->levelDef(8, 0, 2, 2, 2, 2, 2, 1, 6);
}

IA::~IA() {}

void IA::levelDef(int n, int a, int b, int c, int d, int e, int f, int g, int h)
{
	// this->_levelDef[n].push_back(n);
	this->_levelDef[n].push_back(a);
	this->_levelDef[n].push_back(b);
	this->_levelDef[n].push_back(c);
	this->_levelDef[n].push_back(d);
	this->_levelDef[n].push_back(e);
	this->_levelDef[n].push_back(f);
	this->_levelDef[n].push_back(g);
	this->_levelDef[n].push_back(h);
}

bool IA::checkValidId(const std::string &val)
{
	std::vector<std::string>::iterator it;

	it = find(this->_blackList.begin(), this->_blackList.end(), val);
	if (it == this->_blackList.end())
	{
		this->_blackList.push_back(val);
		return (true);
	}
	return (false);
}

int IA::getScore(PlayerInfo &info, std::vector<int> needs)
{
	int score = 0;
	std::vector<int> inv = info.getInventaire();

	for (unsigned int i = 0 ; i < inv.size() && i < needs.size() ; ++i)
	{
		if (needs[i] > 0 && inv[i] > 0)
		{
			if (inv[i] > needs[i])
				inv[i] = needs[i];
			score += (inv[i]);
		}
	}
	return (score);
}

bool IA::minusInv(PlayerInfo &info, std::vector<int> &needs)
{
	bool ret = false;
	std::vector<int> inv = info.getInventaire();

	for (unsigned int i = 0 ; i < inv.size() && i < needs.size() ; ++i)
	{
		if (needs[i] > 0 && inv[i] > 0)
		{
			if (inv[i] > needs[i])
				inv[i] = needs[i];
			needs[i] -= (inv[i]);
			ret = true;
		}
	}
	return (ret);
}

std::vector<PlayerInfo> IA::getBestPlayerSet(int level)
{
	std::vector<PlayerInfo> ret;
	std::vector<PlayerInfo> bests;
	std::vector<int> needs = this->_levelDef[level + 1];
	std::vector<int> scores;
	std::vector<std::string> indexs;
	std::map<std::string, PlayerInfo>::iterator it;
	int max, maxi;

	ret.clear();
	// needs.erase(needs.begin());
	for (it = _infos.begin() ; it != _infos.end() ; ++it)
		if (it->second.getId() != _id && it->second._isAvailable && it->second.getLevel() == level)
			scores.push_back(getScore(it->second, needs));
		else
			scores.push_back(-1);
	for (int i = 0 ; i < 13 ; ++i)
	{
		max = 0;
		maxi = -1;
		for (unsigned int y = 0 ; y < scores.size() ; ++y)
		{
			if (scores[y] > max)
			{
				max = scores[y];
				maxi = y;
			}
		}
		if (maxi != -1)
		{
			it = _infos.begin();
			std::advance(it, maxi);
			indexs.push_back((it->second).getId());
			scores[maxi] = -1;
		}
		else
			i = 9999;
	}
	bool needMorePeople = false;
	ret.push_back(_infos[_id]);
	for (unsigned int i = 0 ; i < indexs.size() ; ++i)
	{
		for (unsigned int y = 0 ; y < needs.size() - 1 && needs[y] == 0 ; ++y)
		{
			if (y == needs.size() - 2 && (int)ret.size() == needs[7])
				return (ret);
			else if (y == needs.size() - 2 && (int)ret.size() == needs[7])
				needMorePeople = true;
		}
		if (minusInv(_infos[indexs[i]], needs))
			ret.push_back(_infos[indexs[i]]);
		else if (needMorePeople)
			ret.push_back(_infos[indexs[i]]);
	}
	for (unsigned int y = 0 ; y < needs.size() - 1 && needs[y] == 0 ; ++y)
		if (y == needs.size() - 2 && (int)ret.size() == needs[7])
			return (ret);
	ret.clear();
	return (ret);
}

void IA::updateView(std::vector<std::vector<std::string> > &val)
{
	if (val.size() > this->_view.size())
		return ;
	std::vector<std::vector<std::string> >::iterator it, it2;

	it = val.begin();
	it2 = this->_view.begin();
	for( ; it != val.end() && it2 != this->_view.end(); it++, it2++)
	{
		(*it2).clear();
		(*it2) = (*it);
	}
}

void IA::updateInventory(const std::string &id, std::vector<std::string> stock)
{
	_infos[id].setInventaire(stock);

	_infos[id].setId(id);


	this->tryToSocialize();
}

bool		IA::isChef(std::vector<std::string> &tmp)
{
	if (tmp.size() < 1)
		return (false);
	for (std::vector<std::string>::iterator it = tmp.begin() ; it != tmp.end() ; ++it)
	{
		if ((*it)!= this->_id)
			if (stringToInt((*it)) < stringToInt(this->_id))
				return (false);
	}
	return (true);
}

void 		IA::tryToSocialize()
{
	std::vector<PlayerInfo> tmp;
	std::string tmp1;

	if (this->_isAvailable == false)
		return ;
	if (this->_level == 1 && this->_hasEnoughItemsForLevel)
	{
		this->_isAvailable = false;
		this->_canEventuallyEvolve = true;
		this->_isChief = true;
		this->_isAtRightPlace = true;
		this->_needToClearPlace = true;
		this->_hasToBroadcastInventory = true;
		return ;
	}
	if (this->_level == 1)
		return ;
	tmp = this->getBestPlayerSet(this->_level);
	if (tmp.size() <= 1)
		return ;
	for (std::vector<PlayerInfo>::iterator it = tmp.begin() ; it != tmp.end() ; ++it)
	{
		if ((*it).getId() != this->_id)
		{
			tmp1 = (*it).getId();
			this->_group.push_back(tmp1);
		}
	}
	if (isChef(this->_group))
	{
		this->_isAvailable = false;
		this->_needToClearPlace	= true;

	}
	return ;
}

void		IA::getItemPos(std::string &obj)
{
	int level = 0;
	int dx = 0;
	int dy = 0;

	_direction = FRONT;
	for (unsigned int y = 0 ; y < _view.size() ; ++y)
	{
		for (unsigned int x = 0 ; x < _view[y].size() ; ++x)
		{
			if (_view[y][x] == obj)
			{
				this->_pos->x = dx;
				this->_pos->y = dy;
				return ;
			}
		}
		++dx;
		if (dx > level)
		{
			++level;
			dx = -level;
			++dy;
		}
	}
	this->_pos->x = this->_pos->y = -1;
	return ;
}

bool	IA::goToPos()
{
	if (this->_pos->y > 0) {
		--this->_pos->y;
		_action = "avance";
	}
	else if (this->_pos->x > 0) {
		if (_direction != RIGHT) {
			_action = "droite";
			_direction = RIGHT;
		}
		else {
			--this->_pos->x;
			_action = "avance";
		}
	}
	else if (this->_pos->x < 0) {
		if (_direction != LEFT) {
			_action = "gauche";
			_direction = LEFT;
		}
		else {
			++this->_pos->x;
			_action = "avance";
		}
	}
	else
		return (false);
	return (true);
}

bool	IA::goToCase(int &n)
{
	if (n == 1 || n == 2 || n == 8)
		_action = "avance";
	else if (n >= 3 && n <= 4)
		_action = "gauche";
	else if (n == 5 || n == 6 || n == 7)
		_action = "droite";
	else
		return (false);
	if (n == 5)
		n = 7;
	else if (_action == "droite")
		n -= 2;
	else if (_action == "gauche")
		n += 2;
	if (n > 8)
		n -= 8;
	else if (n < 1)
		n += 8;
	++_timeSinceFollow;
	return (true);
}

void 				IA::handleAnswer(Task task)
{
	std::string tmp;
	std::string answer;

	tmp = task.getCommandType();
	if (this->_tabActions.find(tmp) == this->_tabActions.end())
	{
		return ;
	}
	answer = task.getAnswer();
	(this->*_tabActions[tmp])(answer);
}

void 				IA::handleAnswerVoir(std::string &val)
{
	this->updateView(this->_parser->parseView(val));
}

void 				IA::handleAnswerPrendre(std::string &val)
{
	if (val == "ok")
	{
		if (this->_isAvailable == true)
			this->_hasToUpdateInventory = true;
	}
	this->_isSearchingSomething = false;

}

void 				IA::handleAnswerPoser(std::string &val)
{
	if (val == "ok")
	{
		if (this->_isAvailable == true || this->_needToTakeFood)
		this->_hasToUpdateInventory = true;
	}
}

void 				IA::handleAnswerInventaire(std::string &val)
{
	std::vector<std::string> tmp;

	tmp = this->_parser->parseInventory(val);
	tmp.push_back(intToString(this->_level));
	tmp.push_back(intToString(this->_isAvailable));

	this->updateInventory(this->_id, tmp);
}

void 				IA::handleAnswerIncantation(std::string &val)
{
	const char *tmp;

	tmp = val.c_str();
	if (tmp[0] && tmp[0] == 'n')
	{
		this->_level++;
		this->_isAvailable = true;
		this->_hasToBroadcastInventory = true;
		this->_canEventuallyEvolve = false;
		this->_isChief = false;
		this->_isAtRightPlace = false;
		this->_needToClearPlace = false;
		this->_group.clear();
	}
}

void 				IA::handleAnswerBroadcast(std::string &val)
{
	if (val == "ok")
	{
		this->_hasToBroadcastInventory = false;
	}
}

void				IA::handleNoAnswer(std::string &val)
{
	(void)val;
}

bool 				IA::needFood(const int nbr)
{
	if ((this->_infos[this->_id].getInventaire())[0] < nbr)
	{
		return (true);
	}
	return (false);
}

void 			IA::findObject(std::string &val)
{
	this->getItemPos(val);
	if (this->_pos->y == -1 && this->_pos->y == -1)
	{
		this->_action = "avance";
	}
	else
	{
		this->_isSearchingSomething = true;
	}
}

void 				IA::moveToObject()
{
	if (!this->goToPos())
	{
		this->_canTakeObj = true;
	}
}

std::string 		&IA::takeObj(const std::string &obj)
{
	this->_action = "prendObjet";
	this->_message = "prend " + obj + "\n";
	this->_canTakeObj = false;
	return (this->_action);
}

void 				IA::poseObj(const std::string &obj)
{
	this->_action = "poseObjet";
	this->_message = "pose " + obj + "\n";
	this->_canTakeObj = false;
}

void 				IA::chooseObjectForLevel(int level)
{
	std::vector<int> tmp;
	unsigned int a = 0;

	tmp = this->_infos[this->_id].getInventaire();
	for (std::vector<int>::iterator it = this->_levelDef[level].begin() ; it != this->_levelDef[level].end() ; ++it)
	{
		if ((*it) != 0)
		{
			if (a < tmp.size() && tmp[a] < (*it))
			{
				this->_objetToFind = this->_correspondanceIntString[a];
				return ;
			}
		}
		a++;
	}
	this->_hasEnoughItemsForLevel = true;
	this->_objetToFind = "nourriture";
}

bool 				IA::checkNumberPersonForIncant()
{
	int 			a = 0;
	std::vector<std::string> tmp = this->_view[0];

	for (std::vector<std::string>::iterator it = tmp.begin(); it != tmp.end() ; ++it)
	{
		if ((*it) == "joueur")
			a++;
	}
	if (a == this->_levelDef[this->_level + 1][7])
		return (true);
	else
		return (false);
}


void 				IA::chooseObjectToFind()
{
	int b = this->_level + 1;

	if (b == 9)
		b = 8;
	if (this->_isSearchingForMe)
	{
		this->chooseObjectForLevel(b);
	}
	else
	{
		this->chooseObjectForLevel(b);
	}
}

void 				IA::checkSearching()
{
	if (!this->_isSearchingSomething)
	{
		if (this->_needToTakeFood == false)
		{
			this->chooseObjectToFind();
		}
		this->findObject(this->_objetToFind);
	}
	else
	{
		this->moveToObject();
	}
}

bool					IA::checkCaseForIncant(int level)
{
	if (level == 9)
		level = 8;
	std::vector<int> tmp;
	for (unsigned int i = 0; i < 8 ; ++i)
		tmp.push_back(0);
	for (unsigned int i = 0; i < this->_view[0].size() ; ++i)
	{
		if (this->_view[0][i] != "joueur")
		{
			int a;
			a = this->_correspondanceStringInt[this->_view[0][i]];
			tmp[a] += 1;
		}
	}
	for (unsigned int i = 0; i < this->_levelDef[level].size() - 1 && i < tmp.size() ; ++i)
	{
		if (this->_levelDef[level][i] != tmp[i])
		{
			return (false);
		}
	}
	return (true);
}

void 		IA::handleAvailable()
{
	if (this->_canTakeObj)
	{
		this->_action = this->takeObj(this->_objetToFind);
		return ;
	}
	this->checkSearching();
	return ;
}

void 		IA::handlePreparationLevelOne()
{
	if (this->_isAtRightPlace)
	{
		if (this->_canEventuallyEvolve)
		{
			if (this->_level == 1 && this->_needToClearPlace == false)
			{
				bool lol = this->checkCaseForIncant(this->_level + 1);
				if (!lol)
				{
					std::string pute("linemate");
					this->poseObj(pute);
				}
				else
				{
					this->_action = "incantation";
				}
				return ;
			}
			if (this->_needToClearPlace)
			{
				if (this->lookCaseChief())
					return ;
				this->_needToClearPlace = false;
			}
		}
	}
}

bool		IA::lookCaseChief()
{
	std::string tmp1("");

	std::vector<std::string> tmp = this->_view[0];
	for (unsigned int i = 0;  i < tmp.size() ; ++i)
	{
		tmp1 = tmp[i];
		if (tmp1 != "joueur")
		{
			this->takeObj(tmp1);
			return (true);
		}
	}
	return (false);
}

bool 		IA::deposeObj(std::vector<std::string> & val)
{
	std::string tmp1("");

	if (val.empty() == false)
	{
		this->poseObj(val.back());
		val.pop_back();
		return (true);
	}
	return (false);
}

void 		IA::handlePreparationLevelSup()
{
	std::string tmp("");

	if (this->isChef(this->_group))
	{
		if (checkNumberPersonForIncant())
		{
			this->_isTimeToTake++;
			if (this->_isTimeToTake >= 2)
			{
				this->_isTimeToTake = 2;
				if (this->_needToClearPlace)
				{
					if (lookCaseChief())
						return ;
					else
						this->_needToClearPlace = false;
				}
				else
				{
					if (this->_hasFilledList == false && this->_listToPut.empty())
						this->_needToFillList = true;
					if (this->_listToPut.empty() && this->_needToFillList)
						{
							this->_hasFilledList = true;
							this->_needToFillList = false;
							this->fillListToPutChief();
						}
					if (this->deposeObj(this->_listToPut))
						return ;
					else
					{
						this->_action = "incantation";
						return ;
					}
				}
			}
		}
	}
	else
	{
		if (this->_hasFilledList == false && this->_listToPute.empty())
			this->_needToFillList = true;
		if (this->_listToPute.empty() && this->_needToFillList)
		{
			this->_hasFilledList = true;
			this->_needToFillList = false;
			this->fillListToPoseNormal();
		}
		if (this->deposeObj(this->_listToPute) == false)
		{
			this->_action = "rien";
			return ;
		}

	}
}

void 		IA::fillListToPutChief()
{
	std::vector<int> tmp = this->_levelDef[this->_level + 1];
	std::string tmp1;

	for (unsigned int i = 0 ; i < tmp.size() - 1; ++i)
	{
		for (unsigned int y = tmp[i] ; y > 0 ; --y)
		{
			tmp1 = this->_correspondanceIntString[i];
			this->_listToPut.push_back(tmp1);
		}
	}
}

void 		IA::fillListToPoseNormal()
{
	std::vector<int> tmp = this->_infos[this->_id].getInventaire();
	std::string tmp1;

	for (unsigned int i = 1 ; i < tmp.size(); ++i)
	{
		for (unsigned int y = tmp[i] ; y > 0 ; --y)
		{
			tmp1 = this->_correspondanceIntString[i];
			this->_listToPute.push_back(tmp1);
		}
	}
}

bool 				IA::isAloneOnCase()
{
	int 			a = 0;
	std::vector<std::string> tmp = this->_view[0];

	for (std::vector<std::string>::iterator it = tmp.begin(); it != tmp.end() ; ++it)
	{
		if ((*it) == "joueur")
			a++;
		if (a >= 2)
			return (false);
	}
	return (true);
}

void 		IA::handleUnavailable()
{
	if (this->_level == 1)
	{
		this->handlePreparationLevelOne();
	}
	else
	{
		std::string t;

		if (this->isChef(this->_group))
		{
			if (this->checkNumberPersonForIncant() == false)
			{
				if (isAloneOnCase() && this->_rejoinCase != 0 && this->_infos[this->_id].getInventaire()[0] < 15 && (rand() % 2 == 0))
				{
					handleAvailable();
				}
				else
				{
					unsigned int a = 0;
					std::string tmp("");
					for (std::vector<std::string>::iterator it = this->_group.begin() ; it != this->_group.end() ; ++it)
					{
						if ((*it) != this->_id)
						{
							tmp.append((*it));
							this->_action = "broadcast";
							a++;
						}
						if (a != this->_group.size())
							tmp.append("_");
					}
					this->constructBroadcastDeplacement(tmp);
					}
				return ;
			}
			else
			{
				this->handlePreparationLevelSup();
			}

		}
		else
		{
			if (_rejoinCase > 0 && _timeSinceFollow <= 2)
				goToCase(_rejoinCase);
			if (this->_rejoinCase == 0)
			{
				this->handlePreparationLevelSup();
			}
			else
			{
				_rejoinCase = -1;
			}
		}
	}
	return ;
}

std::string				&IA::askForInventoryUpdate()
{
	this->_mustUpdateInventory = 7;
	this->_hasToUpdateInventory = false;
	this->_hasToBroadcastInventory = true;
	this->_action = "inventaire";
	return (this->_action);
}

std::string 			&IA::broadcastInventory()
{
	std::string tmp("");
	std::vector<int> tmpTab;

	tmpTab = this->_infos[this->_id].getInventaire();
	for (unsigned int i = 0 ; i < tmpTab.size() ; ++i)
	{
		tmp += intToString(tmpTab[i]);
		tmp += ",";
	}
	tmp += intToString(this->_infos[this->_id].getLevel());
	tmp += ",";
	if (this->_needToDeclareDeath)
		tmp += intToString(0);
	else
		tmp += intToString(this->_infos[this->_id].isAvailable());
	this->_action = "broadcast";
	this->constructBroadcastInventaire(tmp);
	return (this->_action);
}

void				IA::checkFood()
{
	if (this->needFood(NORMAL_FOOD))
	{
		if (this->needFood(URGENCE_FOOD) && !this->_needToTakeFood)
		{
			this->_needToTakeFood = true;
		}
		if (this->_needToTakeFood == true)
		{
			this->_objetToFind = "nourriture";
		}
		return ;
	}
	else
	{
		this->_needToTakeFood = false;
	}
}

bool  				IA::recupereFoodOnCase()
{
	std::vector<std::string> tmp = this->_view[0];

	for (unsigned int a  = 0 ; a < tmp.size() ; ++a)
	{
		if (tmp[a] == "nourriture")
			return (true);
	}
	return (false);
}

void 						IA::casseGroup()
{
	unsigned int a = 0;
	std::string tmp;
	for (std::vector<std::string>::iterator it = this->_group.begin() ; it != this->_group.end() ; ++it)
		{
			if (this->_id != (*it))
			{
				tmp.append((*it));
				this->_action = "broadcast";
				a++;
			}
			if (a != this->_group.size())
			tmp.append("_");
		}
	this->constructBroadcastCasse(tmp);
}

std::string 			 	&IA::declareDeath()
{
	if (this->_etapeDeath == 0)
	{
		this->_action ="broadcast";
		this->constructBroadcastDead();
		this->_etapeDeath++;
	}
	else
		this->_action = "rien";
	return (this->_action);
}

const std::string &IA::chooseAction()
{
	if (this->_needToDeclareDeath)
		{
			return (this->declareDeath());
		}
	this->checkFood();


	if (this->_mustUpdateInventory < 0)
		this->_mustUpdateInventory = 0;
	if (this->_mustSee < 0)
		this->_mustSee = 0;
	if (this->_mustSee == 0)
	{
		this->_action = "voir";
		this->_mustSee = 1;
		return (this->_action);
	}


	this->_mustSee--;
	this->_mustUpdateInventory--;
	if (recupereFoodOnCase() && this->_mustSee == 0)
		return (this->takeObj("nourriture"));
	if (this->_hasToUpdateInventory || this->_mustUpdateInventory == 0)
		return (this->askForInventoryUpdate());
	// if (this->_needToTakeFood)
	// {
	// 	this->handleAvailable();
	// 	return (this->_action);
	// }
	if (this->_infos[this->_id].getInventaire()[0] == 1)
	{
		this->_needToDeclareDeath = true;
	}
	if (this->_hasToBroadcastInventory)
		return (this->broadcastInventory());
	if (!this->_isAvailable)
	{
		this->handleUnavailable();
	}
	else
	{
		this->handleAvailable();
	}
	return (this->_action);
}

bool				IA::belongToGroup(const std::string &val)
{
	for (std::vector<std::string>::iterator it = this->_group.begin() ; it != this->_group.end() ; ++it)
	{
		if ((*it) != this->_id && (*it) == val)
			return (true);
	}
	return (false);
}

const std::string &IA::getTexte() const
{
	return (this->_message);
}

const std::string &IA::getTeam() const
{
	return (this->_team);
}

void 				IA::hasReceivedBroad()
{
	this->_hasReceivedBroad = true;
}

void 				IA::setBroad(Broadcast *val)
{
	if (!val)
	{
		return ;
	}
	this->_hasReceivedBroad = true;
	this->_broad = val;
	this->handleBroadcast();
}

void 				IA::handleBroadcast()
{
	(this->*_tabBroadcast[this->_broad->getType()])();
}

void  IA::constructBroadcastInventaire(std::string &inventaire)
{
	this->_message = "broadcast " + randString() + "-" + this->_team + "-" + this->_id + "-" + "ALL" + "-" + "inventaire" + "-" + inventaire;
}

void  IA::constructBroadcastDeplacement(std::string &dest)
{
	this->_message = "broadcast " + randString() + "-" + this->_team + "-" + this->_id + "-" + dest + "-" + "deplacement" + "-" + "EMPTY";
}

void IA::constructBroadcastDead()
{
	this->_message = "broadcast " + randString() + "-" + this->_team + "-" + this->_id + "-" + "ALL" + "-" + "dead" + "-" + "EMPTY";
}

void IA::constructBroadcastCasse(std::string &dest)
{
	this->_message = "broadcast " + randString() + "-" + this->_team + "-" + this->_id + "-" + dest + "-" + "casse" + "-" + "EMPTY";
}

void IA::handleBroadcastInventaire()
{
	std::string val("");

	val = this->_broad->getData();
	this->updateInventory(this->_broad->getFrom(), this->_parser->parseInventory(val));
}

void IA::handleBroadcastCasse()
{
	this->_isAvailable = true;
	this->_hasToBroadcastInventory = true;
	this->_canEventuallyEvolve = false;
	this->_isChief = false;
	this->_isAtRightPlace = false;
	this->_needToClearPlace = false;
	this->_group.clear();
}

void IA::handleBroadcastDead()
{
	std::string tmp = this->_broad->getFrom();
	this->_infos.erase(tmp);
	if (tmp == this->_chief)
	{
		this->handleBroadcastCasse();
		return ;
	}
	if (this->_isChief && this->belongToGroup(tmp))
	{
		this->casseGroup();
		return ;
	}

}

void IA::handleBroadcastDeplacement()
{
	std::string val("");

	_timeSinceFollow = 0;
	val = this->_broad->getData();
	_rejoinCase = this->_broad->getCase();
	if (this->_isAvailable == true)
		this->_hasToBroadcastInventory = true;
	if (this->_isChief == false)
		this->_isAvailable = false;
	this->_chief = this->_broad->getFrom();
}

void				IA::init(const std::string &id)
{
	this->_parser = new Parse();
	this->_broad = new Broadcast();
	this->initView();
	this->_id = id;
	this->initTabFunc();
	this->initCorrespondance();
	this->_pos = new Pos(-1, -1);
}

void				IA::initCorrespondance()
{
	this->_correspondanceStringInt["nourriture"] = 0;
	this->_correspondanceStringInt["linemate"] = 1;
	this->_correspondanceStringInt["deraumere"] = 2;
	this->_correspondanceStringInt["sibur"] = 3;
	this->_correspondanceStringInt["mendiane"] = 4;
	this->_correspondanceStringInt["phiras"] = 5;
	this->_correspondanceStringInt["thystame"] = 6;

	this->_correspondanceIntString[0] = "nourriture";
	this->_correspondanceIntString[1] = "linemate";
	this->_correspondanceIntString[2] = "deraumere";
	this->_correspondanceIntString[3] = "sibur";
	this->_correspondanceIntString[4] = "mendiane";
	this->_correspondanceIntString[5] = "phiras";
	this->_correspondanceIntString[6] = "thystame";
}

void 				IA::initTabFunc()
{
	this->_tabActions["avance"] = &IA::handleNoAnswer;
	this->_tabActions["droite"] = &IA::handleNoAnswer;
	this->_tabActions["gauche"] = &IA::handleNoAnswer;
	this->_tabActions["voir"] = &IA::handleAnswerVoir;
	this->_tabActions["inventaire"] = &IA::handleAnswerInventaire;
	this->_tabActions["prend"] = &IA::handleAnswerPrendre;
	this->_tabActions["incantation"] = &IA::handleAnswerIncantation;
	this->_tabActions["pose"] = &IA::handleAnswerPoser;
	this->_tabActions["broadcast"] = &IA::handleAnswerBroadcast;
	this->_tabBroadcast["inventaire"] = &IA::handleBroadcastInventaire;
	this->_tabBroadcast["deplacement"] = &IA::handleBroadcastDeplacement;
	this->_tabBroadcast["casse"] = &IA::handleBroadcastCasse;
	this->_tabBroadcast["dead"] = &IA::handleBroadcastDead;
	// this->_tabActions["fork"] = &Game::fork;
}

void 				IA::initView()
{
	std::vector<std::string> tmpTab;
	std::string 			 tmpString("");

	tmpTab.push_back(tmpString);
	for (int i = 0 ; i < 81 ; i++)
	{
		this->_view.push_back(tmpTab);
	}
}
