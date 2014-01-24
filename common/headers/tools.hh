#ifndef		__TOOLS_HH__
#define		__TOOLS_HH__

#include	<string>
#include	<vector>
#include    <sstream>
#include    <fstream>
#include	<iostream>

std::vector<std::string>  cutString(const std::string &, const char);
int						  stringToInt(const std::string &myStream);
std::string   			  intToString(int myStream);
bool					  isNum(const std::string &s);
std::string 			  randString();
void 					  replaceBy(std::string &, char, char);

#endif
