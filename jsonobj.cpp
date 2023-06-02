#include "json.h"
#include "utils.h"

#include <sstream>

using namespace std;

JsonObject::JsonObject(){}

JsonObject::JsonObject(string jsonstr)
{
    string::const_iterator start = jsonstr.begin(), end = jsonstr.end();
    string key;
    findContent('{', '}', start, end);
    start++;
    while(start < end){
       key = findKey(jsonstr, start, end);
       json[key] = findValue(jsonstr, start, end);
    }
}

CopyDataAdapter JsonObject::getValue(const char * key)
{
    return json[key];
}

RefDataAdapter JsonObject::operator [](const char * key)
{
    return json[key];
}

JsonObject::operator string()
{
    stringstream ss;
    map<std::string, std::string>::iterator it = json.begin();
    ss << '{';
    while(1){
        ss << '"' << it->first << "\" = \"" << it++ ->second << '"';
        if (it == json.cend())
            break;
        ss << ',' ;
    }

    ss << '}';
    return ss.str();
}

