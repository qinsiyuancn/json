#include "jsonarray.h"
#include "utils.h"

using namespace std;

JsonArray::JsonArray(){}

JsonArray::JsonArray(string jsonstr)
{
    string::const_iterator start = jsonstr.begin(), end = jsonstr.end();
    findContent('[', ']', start, end);
    start ++;
    while(start < end){
        json.push_back(findValue(jsonstr, start, end));
    }
}

unsigned int JsonArray::size()
{
    return json.size();
}

DataAdapter JsonArray::operator [] (unsigned int index)
{
    if(index < size())
        return json[index].c_str();
    return 0;
}

JsonArray::operator const char *()
{
    return nullptr;
}
