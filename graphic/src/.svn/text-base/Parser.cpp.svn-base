#include "Parser.hh"
#include "Game.hh"

Parser::Parser(Game &_game) : game(_game)
{
  this->init();
  this->initMap();
}

Parser::~Parser()
{}


void              Parser::init()
{
  this->_tab[0] = &Parser::sizeMap;
  this->_tab[1] = &Parser::contentMap;
  this->_tab[2] = &Parser::nameEquipe;
  this->_tab[3] = &Parser::coPlayer;
  this->_tab[4] = &Parser::posPlayer;
  this->_tab[5] = &Parser::levelPlayer;
  this->_tab[6] = &Parser::stockPlayer;
  this->_tab[7] = &Parser::expulsePlayer;
  this->_tab[8] = &Parser::broadcastPlayer;
  this->_tab[9] = &Parser::startIncantation;
  this->_tab[10] = &Parser::endIncantation;
  this->_tab[11] = &Parser::playerLey;
  this->_tab[12] = &Parser::dropRessource;
  this->_tab[13] = &Parser::takeRessource;
  this->_tab[14] = &Parser::deadPlayer;
  this->_tab[15] = &Parser::eggLey;
  this->_tab[16] = &Parser::eclosion;
  this->_tab[17] = &Parser::coForEgg;
  this->_tab[18] = &Parser::eggDead;
  this->_tab[19] = &Parser::sawUnity;
  this->_tab[20] = &Parser::endGame;
  this->_tab[21] = &Parser::msgServer;
  this->_tab[22] = &Parser::unknowCommand;
  this->_tab[23] = &Parser::wrongParam;
}

void              Parser::initMap()
{
  this->_dofunc["msz"] = &Parser::sizeMap;
  this->_dofunc["bct"] = &Parser::contentMap;
  this->_dofunc["tna"] = &Parser::nameEquipe;
  this->_dofunc["pnw"] = &Parser::coPlayer;
  this->_dofunc["ppo"] = &Parser::posPlayer;
  this->_dofunc["plv"] = &Parser::levelPlayer;
  this->_dofunc["pin"] = &Parser::stockPlayer;
  this->_dofunc["pex"] = &Parser::expulsePlayer;
  this->_dofunc["pbc"] = &Parser::broadcastPlayer;
  this->_dofunc["pic"] = &Parser::startIncantation;
  this->_dofunc["pie"] = &Parser::endIncantation;
  this->_dofunc["pfk"] = &Parser::playerLey;
  this->_dofunc["pdr"] = &Parser::dropRessource;
  this->_dofunc["pgt"] = &Parser::takeRessource;
  this->_dofunc["pdi"] = &Parser::deadPlayer;
  this->_dofunc["enw"] = &Parser::eggLey;
  this->_dofunc["eht"] = &Parser::eclosion;
  this->_dofunc["ebo"] = &Parser::coForEgg;
  this->_dofunc["edi"] = &Parser::eggDead;
  this->_dofunc["sgt"] = &Parser::sawUnity;
  this->_dofunc["seg"] = &Parser::endGame;
  this->_dofunc["smg"] = &Parser::msgServer;
  this->_dofunc["suc"] = &Parser::unknowCommand;
  this->_dofunc["sbp"] = &Parser::wrongParam;

  this->_countArg["msz"] = 2;
  this->_countArg["bct"] = 9;
  this->_countArg["tna"] = 1;
  this->_countArg["pnw"] = 6;
  this->_countArg["ppo"] = 4;
  this->_countArg["plv"] = 2;
  this->_countArg["pin"] = 10;
  this->_countArg["pex"] = 1;
  this->_countArg["pbc"] = 2;
  this->_countArg["pic"] = -4;
  this->_countArg["pie"] = 3;
  this->_countArg["pfk"] = 1;
  this->_countArg["pdr"] = 2;
  this->_countArg["pgt"] = 2;
  this->_countArg["pdi"] = 1;
  this->_countArg["enw"] = 4;
  this->_countArg["eht"] = 1;
  this->_countArg["ebo"] = 1;
  this->_countArg["edi"] = 1;
  this->_countArg["sgt"] = 1;
  this->_countArg["seg"] = 1;
  this->_countArg["smg"] = 1;
  this->_countArg["suc"] = 0;
  this->_countArg["sbp"] = 0;
}

bool              Parser::checkOnlyNb(const std::string & str, const std::string &commande) const
{
  if (commande == "tna" || commande == "pbc" || commande == "seg" || commande == "smg")
      return (true);
  if(str.find_first_of("0123456789")!= std::string::npos)
    return (true);
  return (false);
}

std::vector<int>  Parser::convertVectorInt(std::vector<std::string> &args) const
{
  std::vector<int>  _argInt;

  if (args.size() != 0)
  { 
    std::vector<std::string>::iterator it = args.begin();
    ++it;
    for (; it != args.end(); ++it)
    {
      if (checkOnlyNb((*it), args[0]) == true)
        _argInt.push_back(stringToInt((*it)));  
    }
  }
  return (_argInt);
}

void              Parser::parse(const std::string &str)
{
  this->_arg = cutString(str, ' ');
  this->_param = this->convertVectorInt(this->_arg);
  if (this->_arg.size() != 0 && this->_dofunc[this->_arg[0]] != NULL)
  {
    if (this->_countArg[this->_arg[0].c_str()] < 0)
    {
      if ((int)this->_param.size() >= this->_countArg[this->_arg[0].c_str()] * -1)
      {
        (this->*_dofunc[this->_arg[0].c_str()])(this->_arg);
        return;
      }
      std::cerr << "Invalid number or type of arguments for commande : " << this->_arg[0] << std::endl;
    }
    else
    {
      if ((int)this->_param.size() == this->_countArg[this->_arg[0].c_str()])
      {
        (this->*_dofunc[this->_arg[0].c_str()])(this->_arg);
        return;      
      }
      std::cerr << "Invalid number or type of arguments for commande : " << this->_arg[0] << std::endl;
    }
  }
}

void              Parser::sizeMap(const std::vector<std::string> &arg)
{
  (void)arg;
  game.setNewMap(_param[0], _param[1]);
}

void						Parser::contentMap(const std::vector<std::string> &arg)
{
  (void)arg;
  if (_param.size() == 9)
  {
    if (game.getMap().isValidPos(_param[0], _param[1]))
    {
      int posx = _param[0];
      int posy = _param[1];

      game.getMap().setCase(posx, posy, _param);
    }
    else
      std::cerr << ">> Invalid map content response (invalid pos)." << std::endl;  
  }
  else
    std::cerr << ">> Invalid map content response (invalid nb args)." << std::endl;
}

void						Parser::nameEquipe(const std::vector<std::string> & arg)
{
  if (arg.size() == 2)
    this->_teamColor[arg[1]] = sf::Color(rand() % 255, rand() % 255, rand() % 255);
}

void						Parser::coPlayer(const std::vector<std::string> &arg)
{
  std::string teamName = arg[6];

  if (game.getMap().isValidPos(_param[1], _param[2]))
    game.getMap().addPlayer(_param[0], _param[1], _param[2], _param[4], teamName, this->_teamColor[teamName], 0, 0);
  else
    std::cerr << ">> Invalid player position" << std::endl;
}

void						Parser::posPlayer(const std::vector<std::string> & arg)
{
  (void)arg;
  if (game.getMap().isValidPos(_param[1], _param[2]))
  {
    game.getMap().setPosPlayer(_param[0], _param[1], _param[2]);
    switch (_param[3])
    {
      case 1 :
      {
        game.getMap().setType(_param[0], PLAYER_N);
        break;
      }
      case 2 :
      {
        game.getMap().setType(_param[0], PLAYER_E); 
        break;
      }
      case 3 :
      {
        game.getMap().setType(_param[0], PLAYER_S);
        break;
      }
      case 4 :
      {
        game.getMap().setType(_param[0], PLAYER_O); 
        break;
      }
    }
  }
  else
    std::cerr << ">> Invalid player position" << std::endl;
}

void						Parser::levelPlayer(const std::vector<std::string> & arg)
{
  game.getMap().setLevelPlayer(_param[0],_param[1]);
  game.getHud().setLevel(arg[2]);
}

void						Parser::stockPlayer(const std::vector<std::string> & arg)
{
  if (game.getMap().checkPlayers(_param[0]) == true)
  {
    game.getHud().fillInventory(arg);
    game.getHud().setTeam(game.getMap().getPlayer(_param[0]).getTeamName());
  }
}

void						Parser::expulsePlayer(const std::vector<std::string> & arg)
{
  (void)arg;
}

void						Parser::broadcastPlayer(const std::vector<std::string> & arg)
{
  game.getHud().setName(arg[1]);
  game.getHud().setMsg(arg[2]);
}

void						Parser::startIncantation(const std::vector<std::string> & arg)
{
  (void)arg;

  game.getMap().enableInvoc(_param);
}

void						Parser::endIncantation(const std::vector<std::string> & arg)
{
  (void)arg;

  if (_param.size() >= 3)
    game.getMap().disableInvoc(_param[0], _param[1]);
}

void						Parser::playerLey(const std::vector<std::string> & arg)
{
  (void)arg;
}

void						Parser::dropRessource(const std::vector<std::string> & arg)
{
  (void) arg;
  game.getMap().addResource(game.getMap().getPlayer(_param[0]).getPosX(), game.getMap().getPlayer(_param[0]).getPosY(), (objectType)_param[1]);
}

void						Parser::takeRessource(const std::vector<std::string> & arg)
{
  (void) arg;
  game.getMap().remResource(game.getMap().getPlayer(_param[0]).getPosX(), game.getMap().getPlayer(_param[0]).getPosY(), (objectType)_param[1]);
}

void						Parser::deadPlayer(const std::vector<std::string> & arg)
{
	(void)arg;
  game.getMap().remPlayer(_param[0]);
}

void						Parser::eggLey(const std::vector<std::string> & arg)
{
  (void)arg;

  if (game.getMap().isValidPos(_param[2], _param[3]))
    game.getMap().addEgg(_param[0], _param[2], _param[3], sf::Color(200, 0, 50));
}

void						Parser::eclosion(const std::vector<std::string> & arg)
{
  (void)arg;
  game.getMap().setEclosionEgg(_param[0], 1);
}

void						Parser::coForEgg(const std::vector<std::string> & arg)
{
	(void)arg;

  if (game.getMap().checkEgg(_param[0]))
    game.getMap().remEgg(_param[0]);
}

void						Parser::eggDead(const std::vector<std::string> & arg)
{
  (void)arg;
  if (game.getMap().checkEgg(_param[0]))
    game.getMap().remEgg(_param[0]);
}

void						Parser::sawUnity(const std::vector<std::string> & arg)
{
  game.getHud().setUnity(arg[1]);
  game.setUnity(_param[0]);
}

void						Parser::endGame(const std::vector<std::string> & arg)
{
	std::cout << "Game over : winner are " << arg[1] << std::endl;
  exit(0);
}

void						Parser::msgServer(const std::vector<std::string> & arg)
{
	std::cout << "message du serveur : " << arg[1] << std::endl;
}

void						Parser::unknowCommand(const std::vector<std::string> & arg)
{
  (void)arg;
  std::cout << "Une commande inconnue a etait envoye" << std::endl;
}

void						Parser::wrongParam(const std::vector<std::string> & arg)
{
  (void)arg;
  std::cout << "des mauvais parametres sont present dans la dernieres commandes" << std::endl;
}
