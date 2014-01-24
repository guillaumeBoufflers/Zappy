#ifndef __IA__HH__
#define __IA__HH__

#include    <map>
#include 	<utility>
#include 	<string>
#include    "tools.hh"
#include	"Pos.hh"
#include    "Task.hh"
#include    "Parse.hh"
#include	"PlayerInfo.hh"
#include	"Broadcast.hh"

class IA
{
enum direction
{ 
	FRONT,
	RIGHT,
	BEHIND,
	LEFT
};

public:
	IA(const std::string &team);
	~IA();
	const std::string &chooseAction();
	const std::string &getTexte() const;
	const std::string &getTeam() const;

	void  	setBroad(Broadcast *);
	void  	hasReceivedBroad();
	
	void 	updateInventory(const std::string &, std::vector<std::string> );
	void 	updateView(std::vector<std::vector<std::string> > &val);
	bool 	checkValidId(const std::string &val);
	void	getItemPos(std::string &obj);
	bool	goToPos();
	bool 	needFood(const int);
	void 	findObject(std::string &);
	void 	moveToObject();
	void 	checkSearching();
	void 	tryToSocialize();
	bool	checkNumberPersonForIncant();
	bool 	lookCaseChief();
	void 	checkFood();
	bool	recupereFoodOnCase();
	void 	fillListToPutChief();
	void 	fillListToPoseNormal();
	bool	deposeObj(std::vector<std::string> &);
	std::string	&declareDeath();
	void 	casseGroup();
	bool	belongToGroup(const std::string &);

	void 	chooseObjectToFind();
	void 	chooseObjectForLevel(int);
	bool 	checkCaseForIncant(int );

	std::string &askForInventoryUpdate();
	std::string &takeObj(const std::string &);
	void 		 poseObj(const std::string &);
	std::string &broadcastInventory();

	void    handleAnswer(Task );
	void 	handleAnswerVoir(std::string &);
	void 	handleAnswerInventaire(std::string &);
	void 	handleAnswerPrendre(std::string &);
	void 	handleAnswerPoser(std::string &);
	void    handleAnswerBroadcast(std::string &);
	void 	handleAnswerIncantation(std::string &);
	void    handleNoAnswer(std::string &);

	void    affView();
	void   	initView();
	void 	initTabFunc();
	void    initCorrespondance();
	void  	init(const std::string &);	

	void 	constructBroadcastInventaire(std::string &);
	void 	constructBroadcastDeplacement(std::string &);
	void 	constructBroadcastCasse(std::string &);
	void 	constructBroadcastDead();

	void 	handleBroadcast();
	void 	handleBroadcastInventaire();
	void 	handleBroadcastDeplacement();
	void 	handleBroadcastCasse();
	void	handleBroadcastDead();

	void 	handleUnavailable();
	void 	handleAvailable();

	void 	handlePreparationLevelOne();
	void 	handlePreparationLevelSup();

	int getScore(PlayerInfo &info, std::vector<int> needs);
	std::vector<PlayerInfo> getBestPlayerSet(int level);
	bool minusInv(PlayerInfo &info, std::vector<int> &needs);
	bool goToCase(int &n);
	bool isChef(std::vector<std::string> &tmp);
	void levelDef(int n, int a, int b, int c, int d, int e, int f, int g, int h);
	bool isAloneOnCase();


private:
	Parse  		*_parser;
	std::string _team;
	std::string _action;
	std::string _message;
	std::string _id;
	std::string _dest;

	std::string _objetToFind;
	//std::string _objetToTake;
	std::string 	_chief;

	int  		_level;
	int 		_mustSee;
	int 		_mustUpdateInventory;
	bool 		_isAvailable;
	bool 		_isChief;
	bool 		_hasReceivedBroad;
	bool		_hadSee;
	bool	 	_canTakeObj;
	bool		_isSearchingSomething;
	bool		_hasToUpdateInventory;
	bool 		_hasToBroadcastInventory;
	bool		_isSearchingForMe;
	bool		_hasEnoughItemsForLevel;
	bool		_canEventuallyEvolve;
	bool 		_isAtRightPlace;
	bool 		_needToClearPlace;
	bool 		_needToTakeFood;
	bool 		_needToFillList;
	bool		_hasFilledList;
	bool	 	_needToBreakGroup;
	bool		_needToDeclareDeath;

	direction 	_direction;
	int			_rejoinCase;
	int			_timeSinceFollow;
	int 		_chiefError;
	int 		_isTimeToTake;
	int 		_etapeDeath;

	std::vector<std::vector<std::string> > _view;
	std::map<std::string, PlayerInfo> _infos;
	std::map<int, std::vector<int> > _levelDef;

	std::map<std::string, int> _correspondanceStringInt;
	std::map<int, std::string> _correspondanceIntString;
	std::vector<std::string>	_blackList;
	Pos 						*_pos;

	std::vector<std::string> _group;
	Broadcast 		*_broad;

	std::map<std::string, void(IA::*)(std::string &)> _tabActions;
	std::map<std::string, void(IA::*)()> _tabBroadcast;
	std::vector<std::string> 					_listToPut;
	std::vector<std::string>					_listToPute;

};

#endif
