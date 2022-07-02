#include "jsonobj.h"
#include "utils.h"

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

DataAdapter JsonObject::operator [](const char * key)
{
    return json[key].c_str();
}

JsonObject::operator const char *()
{
    return nullptr;
}
