#include			"Broadcast.hh"

Broadcast::Broadcast()
{
  
}

Broadcast::~Broadcast()
{
}

const std::string &Broadcast::getType() const
{
	return (this->_type);
}

const std::vector<std::string> &Broadcast::getDest() const
{
	return (this->_dest);
}

const std::string &Broadcast::getData() const
{
	return (this->_data);
}

const std::string &Broadcast::getFrom() const
{
  return (this->_from);
}

const std::string  &Broadcast::getRandString() const
{
  return (this->_randString);
}

int			Broadcast::getCase() const
{
	return (this->_case);
}

void		Broadcast::setCase(const std::string &f)
{
	std::vector<std::string> tmp;

	tmp = cutString(f, ' ');
	this->_case = stringToInt(tmp.back());
}

bool    Broadcast::isForEveryone(const std::string &dest) const
{
  if (dest == "ALL")
    return (true);
  return (false);
}

bool 		Broadcast::parseMessage(std::string &message, const std::string &id)
{
  std::vector<std::string> first;
  std::string 		     f;
  std::vector<std::string> tmp;

  (void)id;
  first = cutString(message, '.');
  f = first.back();
  first.pop_back();
  this->setCase(first.back());
  tmp = cutString(f, '-');
  if (tmp.size() != 6)
    return (false);
  this->_data = tmp.back();
  tmp.pop_back();
  this->_type = tmp.back();
  std::cout << "__GOT TYPE " << this->_type << std::endl;
  tmp.pop_back();
  this->_dest = cutString(tmp.back(), '_');
  tmp.pop_back();
  this->_from = tmp.back();
  if (isNum(this->_from) == false)
    return (false);
  tmp.pop_back();
  this->_team = tmp.back();
  tmp.pop_back();
  this->_randString = tmp.back();
  return (true);
}
