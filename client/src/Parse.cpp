#include		"Parse.hh"

Parse::Parse()
{

}

Parse::~Parse()
{

}

unsigned int				Parse::matchWith(const std::string &str, const char &c) const
{
  unsigned int				i = 0;
  int					j = 0;  

  while (str[i])
    {
      if (str[i] == c)
	j++;
      i++;
    }
  return (j);
}

void					Parse::addObjects(std::string &see)
{
  std::string	tmp = "";

  while (see.size() != 0 && see[0] != ',')
    {
      tmp += see[0];
      see.erase(0,1);
    }
  this->_adding = cutString(tmp, ' ');
  this->_view.push_back(this->_adding);
  see.erase(0,1);
}

void					Parse::addEmptyCase(std::string &see)
{
  this->_adding.push_back("");
  this->_view.push_back(this->_adding);
  if (see.size() != 0)
    see.erase(0,1);
}

void					Parse::addToInventory(std::string &line)
{
  std::vector<std::string>		tmp;
  std::pair<std::string, int>		objs;
  std::string				type;
  int					amount;

  tmp = cutString(line, ' ');
  for (std::vector<std::string>::iterator it = tmp.begin(); it != tmp.end(); ++it)
    {
      if (it == tmp.begin())
	type = (*it);
      else
	amount = stringToInt((*it));
    }
  objs = std::make_pair(type, amount);
  this->_inventory.push_back(objs);
}

std::vector<std::vector<std::string > >	&Parse::parseView(std::string &see)
{
  unsigned int		size = matchWith(see, ',');

  //std::cout << "GOT VIEW" << see << std::endl;
  this->_view.clear();
  this->_adding.clear();
  see.erase(std::remove(see.begin(), see.end(), '{'), see.end());
  see.erase(std::remove(see.begin(), see.end(), '}'), see.end());
  while (see.size() != 0)
    {
      this->_adding.clear();
      if (see[0] == ',')
  this->addEmptyCase(see);
      
      else if (see[0] == ' ')
  see.erase(0,1);
      else
  this->addObjects(see);
    }
  this->_adding.clear();
  if (this->_view.size() == size)
    this->addEmptyCase(see);
  return (this->_view);
}

std::vector<std::string> Parse::parseInventory(std::string &inventory)
{
  std::size_t found;

  this->_inventory.clear();
  this->_adding.clear();
  inventory.erase(std::remove(inventory.begin(), inventory.end(), '{'), inventory.end());
  inventory.erase(std::remove(inventory.begin(), inventory.end(), '}'), inventory.end());
  inventory.erase(std::remove(inventory.begin(), inventory.end(), '\n'), inventory.end());
  while ((found = inventory.find_first_not_of("0123456789,")) != std::string::npos)
    inventory.erase(inventory.begin() + found);
  this->_adding = cutString(inventory, ',');
  return (this->_adding);
}
