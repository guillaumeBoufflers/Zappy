#ifndef		__PARSE_HH__
#define		__PARSE_HH__

#include	<vector>
#include	<iostream>
#include	<utility>
#include	<string>
#include	<fstream>
#include	<iomanip>
#include	<algorithm>

#include	"tools.hh"

class		Parse
{
private:
  std::vector<std::vector<std::string > >	_view;
  std::vector<std::pair<std::string, int> >	_inventory;
  std::vector<std::string>			_adding;
  void						addToInventory(std::string &line);
  void						addObjects(std::string &see);
  unsigned int					matchWith(const std::string &str, const char &c) const;
  void						addEmptyCase(std::string &see);
public:
  Parse();
  ~Parse();
  /****/
  std::vector<std::vector<std::string > >	&parseView(std::string &);
  std::vector<std::string> parseInventory(std::string &inventory);
};

#endif
