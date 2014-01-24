#ifndef			__NETWORK_HH__
#define			__NETWORK_HH__

#include                <fcntl.h>
#include                <sys/types.h>
#include                <sys/socket.h>
#include                <sys/select.h>
#include                <sys/stat.h>
#include                <signal.h>
#include                <strings.h>
#include                <netdb.h>
#include                <stdio.h>
#include                <stdlib.h>
#include                <string.h>
#include                <netinet/in.h>
#include                <arpa/inet.h>
#include                <unistd.h>
#include                <time.h>

#include		<list>
#include		<string>
#include		<iostream>

#include		"INetwork.hh"
#include		"tools.hh"

typedef	int	        SOCKET;
typedef struct		sockaddr_in SOCKADDR_IN;
typedef struct		sockaddr SOCKADDR;

class Network : public	INetwork
{
private:
  std::list<std::string> _cmdList;
  std::list<std::string> _broadcastList;
  std::list<std::string> _answerList;
  struct timeval	 _timeOut;

  std::string		 _ip;
  int			 _port;
  std::string _id;
  
  SOCKADDR_IN     _sin;
  SOCKET		 _sock;
  SOCKET		 _highestSock;
  int			 _selectRet;
  fd_set		 _rs;
  fd_set		 _ws;
  bool       _isIncant;
  int         _nbAnswer;
  bool			 _canPush;
  pthread_t		 _networkThread;
  pthread_mutex_t	 _mutexNet;
  bool			 _getAnswer;
  Task			 _answer;
  bool      _isTakingCmd;
  bool			 _error;

public:
  Network(const std::string &ip, const int &port, const std::string &id);
  virtual ~Network();
  /****/
  virtual Broadcast	*popBroadcast();
  virtual int		getBroadcastSize() const;
  virtual bool		canPush() const;
  virtual Task		getTask() const;
  /****/
  virtual bool		init();
  virtual bool		connectCli() const;
  virtual void		cleanFd() const;
  virtual void		setFd();
  virtual void		addCmd(const std::string &cmd);
  virtual void		setTimeVal();
  virtual void		doSelect();
  virtual void		handleFlux();
  virtual void		sendData();
  virtual void		readData();
  virtual void		processAction();  
  virtual bool		isABroadcast(std::string &data) const;
  virtual void		*flowianbitch();
  virtual bool		getAnswerWithTimeout(std::string &ret, int duree = TIMEOUT_DURATION);
};

#endif
