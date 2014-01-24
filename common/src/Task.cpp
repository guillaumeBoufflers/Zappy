#include		"Task.hh"

Task::Task()
{

}

Task::~Task()
{

}

std::string		Task::getCommandType() const
{
  return (this->_commandType);
}

std::string		Task::getAnswer() const
{
  return (this->_answer);
}

void			Task::setCommandType(const std::string &commandType)
{
  this->_commandType = commandType;
}

void			Task::setAnswer(const std::string &answer)
{
  this->_answer = answer;
}
