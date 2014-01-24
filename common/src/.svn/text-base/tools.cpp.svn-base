#include			"tools.hh"
#include      <unistd.h>
#include      <stdlib.h>


bool				isNum(const std::string &s)
{
  for(unsigned int i = 0; i < s.length(); i++)
    if(!((s[i] >= '0' && s[i] <= '9') || s[i] == ' '))
      return (false);
  return (true);
}

std::vector<std::string>	cutString(const std::string &order, const char delimitor)
{
  std::vector<std::string>	tab;
  int	len = order.size();
  int	i = 0;
  int	j;

  while (i < len)
    {
      i = order.find_first_not_of(delimitor, i);
      if (i == -1)
        return (tab);
      j = order.find_first_of(delimitor, i);
      if (j == -1)
	{
	  tab.push_back(order.substr(i));
	  return (tab);
	}
      else
        tab.push_back(order.substr(i, j - i));
      i = j + 1;
    }
  return (tab);
}

int   stringToInt(const std::string &myStream)
{
  int value;

  std::stringstream buffer(myStream);
  buffer >> value;
  return (value);
}

std::string           intToString(int a) 
{
    std::stringstream convert;

    convert << a;
    return (convert.str());
}


std::string randString()
{
 std::string   tmp;
 char          c;
 
 for (int a = 0 ; a < 30 ; a++)
 {
   if (rand() % 2 == 0)
   {
     c = (rand() % 10) + '0';
     tmp += c;
   }
   else
   {
     c = (rand() % 26) + 65;
     if (rand() % 2 == 0)
       c += 32;
     tmp += c;
   }
 }
return (tmp);
}

void    replaceBy(std::string &str, char before, char after)
{
  std::string tmp("");
  tmp += before;
  std::size_t found = str.find_first_of(tmp);
 while (found != std::string::npos)
 {
  str[found] = after;;
  found = str.find_first_of(tmp,found+1);
  }
  std::cout << str << '\n';
}
