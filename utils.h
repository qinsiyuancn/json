#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>

extern int findContent(char charstart, char charend, std::string::const_iterator & itstart, std::string::const_iterator & itend);

extern int trim(std::string & target);

extern std::string::const_iterator findSpectialChar(std::string::const_iterator itstart, std::string::const_iterator itend, const char * charset, unsigned int charcount);

extern std::string findKey(const std::string & jsonstr,std::string::const_iterator & itstart, std::string::const_iterator itend);

extern std::string findValue(const std::string & jsonstr, std::string::const_iterator & itstart, std::string::const_iterator itend);

#endif
