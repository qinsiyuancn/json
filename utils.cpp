#include <algorithm>
#include <string>
#include "utils.h"
using namespace std;

int findContent(char charstart, char charend, string::const_iterator & itstart, string::const_iterator & itend)
{
    unsigned int stack = 0;
    string::const_iterator i;
    for(i = itstart; i <= itend; i++){
        if (*i == charend && stack){
            if ( !(-- stack) ){
                itend = i;
                return 1;
            }
        }else if( *i == charstart){
            if ( ! (stack++) ){
                itstart=i;
            }
        }
    }
    itstart = i;
    return 0;
}

int trim(string & target)
{
    static const char charset[] = { ' ', '\t', '\r', '\n'};
    unsigned int i = 0;
    for(i = 0; i < sizeof(charset)/sizeof(charset[0]); i++){
        target.erase(remove(target.begin(), target.end(), charset[i]), target.end());
    }
    return 0;
}

string::const_iterator findSpectialChar(string::const_iterator itstart, string::const_iterator itend, const char * charset, unsigned int charcount)
{
    string::const_iterator i;
    unsigned int j = 0;
    for(i = itstart; i <= itend; i++){
        for(j = 0; j < charcount; j++){
            if(charset[j] == *i)
                return i;
        }
    }
    return itstart;
}

string findKey(const string & jsonstr,string::const_iterator & itstart, string::const_iterator itend)
{
    static const char charset[] =  {'"', ':'};
    string result;
    string::const_iterator temp = itend;
    string::const_iterator scit = findSpectialChar(itstart, itend, charset, sizeof(charset)/sizeof(charset[0]));
    switch(*scit){
    case '"':
        do{
            itstart = scit;
            temp = itend;
            findContent(*itstart, *itstart, itstart, temp);
            result += string(jsonstr, itstart - jsonstr.begin() + 1, temp - itstart - 1);
            itstart ++;
            scit = findSpectialChar(itstart, itend, charset, sizeof(charset)/sizeof(charset[0]));
        }while(*scit != ':' && scit < itend && itstart < itend); 
        break;
    case ':':
        result = string(jsonstr, itstart - jsonstr.begin(), itend - itstart);
        trim(result);
        break;
   }
   itstart = scit + 1;
   return result;
}

string findValue(const string & jsonstr, string::const_iterator & itstart, string::const_iterator itend)
{
    static const char charset [] = {'{', '[', '"', ','};
    static const char charsetPair[] = {','};
    static const char charsetQuotes[] = {'"', ','};
    char start = 0, end = 0;
    string::const_iterator temp = itend;
    string::const_iterator i = findSpectialChar(itstart, itend, charset, sizeof(charset)/sizeof(charset[0]));
    string result;
    switch(*i){
    case '{':
    case '[':
        end = (*i) + 2; 
        itstart = i;
        start = *i;
        findContent(start, end, itstart, temp);
        i = itstart;
        itstart = temp + 1;
        itstart = findSpectialChar(itstart, itend, charsetPair, sizeof(charsetPair)/sizeof(charsetPair[0])) + 1;
    return string(jsonstr, i - jsonstr.begin(), temp - i + 1);
    case '"':
         do{
            itstart = i;
            temp = itend;
            findContent(*itstart, *itstart, itstart, temp);
            result += string(jsonstr, itstart - jsonstr.begin() + 1, temp - itstart - 1);
            itstart ++;
            i = findSpectialChar(itstart, itend, charsetQuotes, sizeof(charsetQuotes)/sizeof(charsetQuotes[0]));
        }while(*i != ',' && i < itend && itstart < itend); 
        itstart = i + 1;
        return result;
    case ',':
        temp = itstart;
        itstart = i + 1;
        return string(jsonstr, temp - jsonstr.begin(), itend - temp - 1);
    default:
        return result;
    }
}


