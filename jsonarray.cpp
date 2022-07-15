#include "json.h"
#include "utils.h"
#include <sstream>

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

CopyDataAdapter JsonArray::getValue(unsigned int index)
{
    if(index < size())
        return json[index];
    return json[0];

}

RefDataAdapter JsonArray::operator [] (unsigned int index)
{
    if(index < size())
        return json[index];
    return json[0];
}

JsonArray::operator string()
{
    stringstream ss;
    ss << '[';
    ss << ']';
    return ss.str();
}
