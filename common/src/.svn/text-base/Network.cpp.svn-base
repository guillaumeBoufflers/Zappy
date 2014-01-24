#include	"Network.hh"

Network::Network(const std::string &ip, const int &port, const std::string &id) : _ip(ip), _port(port), _id(id),  _isIncant(false), _nbAnswer(0), _canPush(true), _isTakingCmd(false), _error(false)
{
  std::cout << this->_id << std::endl;
}

Network::~Network()
{

}

/*******/
void            *run(void *data)
{
  Network        *network = (Network*) data;
 
  network->flowianbitch();
  return (NULL);
}

Task		Network::getTask() const
{
  return (this->_answer);
}

bool		Network::isABroadcast(std::string &data) const
{
  std::vector<std::string> tmpVec;

  tmpVec = cutString(data, ' ');
  for (std::vector<std::string>::const_iterator it = tmpVec.begin(); it != tmpVec.end(); ++it)
    {
      if (it == tmpVec.begin())
	{
	  if ((*it) == "message")
	    return (true);
	  else
	    return (false);
	}
    }  
  return (false);
}

bool		Network::getAnswerWithTimeout(std::string &ret, int duree)
{
  int triesleft = TIMEOUT_NB_TRIES;

  do
    {
      if (this->_answerList.size() > 0)
	{
	  ret = this->_answerList.front();
	  this->_answerList.pop_front();
	  return (true);
	}
      usleep(duree / TIMEOUT_NB_TRIES);
      --triesleft;
    } while (triesleft);
  return (false);
}

bool		Network::canPush() const
{
  return (this->_canPush);
}

/*******/

int		Network::getBroadcastSize() const
{
  return (this->_broadcastList.size());
}

Broadcast	*Network::popBroadcast()
{
  std::string tmp;
  int		i = 0;

  Broadcast *broadcast = new Broadcast();
  tmp = this->_broadcastList.front();
  this->_broadcastList.pop_front();
  while (tmp[i])
    {
      if (tmp[i] == ',')
      {
        tmp[i] = '.';
        break ;        
      }
      i++;
    }
  if (broadcast->parseMessage(tmp, this->_id))
    return (broadcast);
  return (NULL);
}

void		Network::addCmd(const std::string &cmd)
{
  std::string yop = cmd;
  pthread_mutex_lock(&this->_mutexNet);
  this->_canPush = false;
  this->_cmdList.push_back(cmd);
  if (this->isABroadcast(yop) == false)
    {
      std::vector<std::string> tmp;
      tmp = cutString(yop, ' ');
      std::string bitch = tmp.front();
      if (bitch == "incantation\n")
        {
          this->_isIncant = true;
          this->_nbAnswer = 0;
        }
      bitch.erase(std::remove(bitch.begin(), bitch.end(), '\n'), bitch.end());
      this->_answer.setCommandType(bitch);
    }
  pthread_mutex_unlock(&this->_mutexNet);
}

/*******/

bool		Network::init()
{
  pthread_mutex_init(&this->_mutexNet, NULL);
  if ((this->_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    return (false);
  this->_highestSock = this->_sock + 1;
  this->_sin.sin_addr.s_addr = inet_addr(this->_ip.c_str());
  this->_sin.sin_family = AF_INET;
  this->_sin.sin_port = htons(this->_port);
  if (!connectCli())
    return (false);
  pthread_create(&this->_networkThread, NULL, run, this);
  return (true);
}

bool		Network::connectCli() const
{
  if (connect(this->_sock,(SOCKADDR*)(&this->_sin), sizeof(this->_sin)) == -1)
    return (false);
  return (true);
}

void		Network::cleanFd() const
{
  FD_ZERO(&this->_rs);
  FD_ZERO(&this->_ws);
}

void		Network::setFd()
{
  FD_SET(this->_sock, &this->_rs);
  if (this->_cmdList.size() != 0)
    FD_SET(this->_sock, &this->_ws);
}

void		Network::setTimeVal()
{
  this->_timeOut.tv_sec = 0;
  this->_timeOut.tv_usec = 0;
}

void		Network::doSelect()
{
  this->_selectRet = select(this->_highestSock, &this->_rs, &this->_ws, NULL, &this->_timeOut);
}

void		Network::sendData()
{
  if (write(this->_sock, this->_cmdList.front().c_str(), this->_cmdList.front().size()) == -1)
    this->_error = true;
}

void		Network::readData()
{
  std::vector<std::string> tmpVec;
  std::string	tmpString;
  char		tmpBuff[512];
  int		ret;

  bzero(tmpBuff, 512);
  ret = read(this->_sock, tmpBuff, 511);
  if (ret == -1 || ret == 0)
    {
      this->_error = true;
      return;
    }
  tmpString = tmpBuff;
  bzero(tmpBuff, 511);
  while (ret == 511)
    {
      ret = read(this->_sock, tmpBuff, 511);
      if (ret == -1 || ret == 0)
	{
	  this->_error = true;
	  return;
	}
      tmpString += tmpBuff;
      bzero(tmpBuff, 511);
    }  
  tmpVec = cutString(tmpString, '\n');
  for (std::vector<std::string>::iterator it = tmpVec.begin(); it != tmpVec.end(); ++it)
    {
      if (this->isABroadcast(*it) == true)
        this->_broadcastList.push_back((*it));
      else
	{
	  if (this->_isIncant == true)
	    {
	      if (this->_nbAnswer == 0)
		this->_nbAnswer = 1;
	      else
		{
		  this->_nbAnswer = 0;
		  this->_answerList.push_back((*it));
		  this->_answer.setAnswer((*it));
		  this->_canPush = true;
		  this->_isIncant = false;
		}         
	    }
	  else
	    {
	      this->_answerList.push_back((*it));
	      this->_answer.setAnswer((*it));
	      this->_canPush = true;
	    }
	}
    }
}

void		Network::handleFlux()
{
  if (FD_ISSET(this->_sock, &this->_rs))
    this->readData();
  if (FD_ISSET(this->_sock, &this->_ws))
    {
      pthread_mutex_lock(&this->_mutexNet);
      if (this->_cmdList.size() != 0)
	{
	  sendData();
	  this->_cmdList.pop_front();
	}
      pthread_mutex_unlock(&this->_mutexNet);
    }
}

void		Network::processAction()
{
  this->setTimeVal();
  this->cleanFd();
  this->setFd();
  this->doSelect();
  if (this->_selectRet == -1)
    {
      this->_error = true;
      return;
    }
  if (this->_selectRet > 0)
    this->handleFlux();
}

void   *Network::flowianbitch()
{
  while (1 && this->_error == false)
    {
      this->processAction();
      usleep(10);
    }
  return (NULL);
}
