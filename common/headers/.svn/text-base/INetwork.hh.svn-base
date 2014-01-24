#ifndef			__INETWORK_HH__
#define			__INETWORK_HH__

#include		<string>
#include		"common.hh"
#include		"Task.hh"
#include    "Broadcast.hh"

#define     TIMEOUT_DURATION 400000
#define     TIMEOUT_NB_TRIES 10
#define     TIMEOUT_CMD 10000000

class INetwork
{
public:
  virtual ~INetwork(){};
  /****/
  virtual bool		isABroadcast(std::string &data) const = 0;
  virtual bool		canPush() const = 0;
  /****/
  virtual Broadcast	*popBroadcast() = 0;
  virtual int		getBroadcastSize() const = 0;
  virtual Task		getTask() const = 0;
  /****/
  virtual bool		init() = 0;
  virtual bool		connectCli() const = 0;
  virtual void		cleanFd() const = 0;
  virtual void		setFd() = 0;
  virtual void		addCmd(const std::string &cmd) = 0;
  virtual void		setTimeVal() = 0;
  virtual void		doSelect() = 0;
  virtual void		handleFlux() = 0;
  virtual void		sendData() = 0;
  virtual void		readData() = 0;
  virtual void		processAction() = 0;
  virtual bool		getAnswerWithTimeout(std::string &ret, int duree) = 0;
  virtual void		*flowianbitch() = 0;
};

#endif
