#ifndef __PARSER_HH__
#define __PARSER_HH__

#include <vector>
#include <string>

#include "common.hh"
#include "tools.hh"

class Game;

class Parser
{
private:
	std::vector<std::string>			_arg;
	std::vector<int>					_param;
	std::map<const std::string, int> 	_countArg;
	Game &game;
	void	(Parser::*_tab[NB_FUNC])(const std::vector<std::string> &);
	std::map<const std::string, void(Parser::*)(const std::vector<std::string> &)> _dofunc;
	std::map<const std::string, sf::Color> 	_teamColor;
	bool						checkOnlyNb(const std::string &, const std::string &) const;
public:
	Parser(Game &_game);
	~Parser();
	void						init();
	void						initMap();
	std::vector<int> 			convertVectorInt(std::vector<std::string> &args) const;
	void						parse(const std::string &order);

	//function
	void						sizeMap(const std::vector<std::string> &);
	void						contentMap(const std::vector<std::string> &);
	void						nameEquipe(const std::vector<std::string> &);
	void						coPlayer(const std::vector<std::string> &);
	void						posPlayer(const std::vector<std::string> &);
	void						levelPlayer(const std::vector<std::string> &);
	void						stockPlayer(const std::vector<std::string> &);
	void						expulsePlayer(const std::vector<std::string> &);
	void						broadcastPlayer(const std::vector<std::string> &);
	void						startIncantation(const std::vector<std::string> &);
	void						endIncantation(const std::vector<std::string> &);
	void						playerLey(const std::vector<std::string> &);
	void						dropRessource(const std::vector<std::string> &);
	void						takeRessource(const std::vector<std::string> &);
	void						deadPlayer(const std::vector<std::string> &);
	void						eggLey(const std::vector<std::string> &);
	void						eclosion(const std::vector<std::string> &);
	void						coForEgg(const std::vector<std::string> &);
	void						eggDead(const std::vector<std::string> &);
	void						sawUnity(const std::vector<std::string> &);
	void						endGame(const std::vector<std::string> &);
	void						msgServer(const std::vector<std::string> &);
	void						unknowCommand(const std::vector<std::string> &);
	void						wrongParam(const std::vector<std::string> &);
};

#endif