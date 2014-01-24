#ifndef			__BROADCAST_HH_
#define			__BROADCAST_HH_

#include		<string>
#include		<iomanip>
#include		<vector>
#include		"common.hh"
#include		"tools.hh"

class Broadcast
{
public:
	Broadcast();
	~Broadcast();
	const std::string &getType() const;
	const std::vector<std::string> &getDest() const;
	const std::string &getData() const;
	const std::string &getFrom() const;
	const std::string &getRandString() const;
	int			getCase() const;
	void		setCase(const std::string &f);
	bool    	isForEveryone(const std::string &dest) const;
	//
	bool		parseMessage(std::string &message, const std::string &id);
private:
	int			_case;
	std::string _randString;
	std::string _team;
	std::string _from;
	std::vector<std::string> _dest;
	std::string	_type;
	std::string _data;
};

#endif
