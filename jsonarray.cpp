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
    if(index >= size())
        json.insert(json.begin() + index ,string());
    return json[index];
}

RefDataAdapter JsonArray::operator [] (unsigned int index)
{
    if(index >= size())
        json.insert(json.begin() + index ,string());
    return json[index];
}

JsonArray::operator string()
{
    stringstream ss;
    vector<string>::iterator it = json.begin();
    ss << '[';
    while(it != json.end()){
        ss << '"' << *(it++) << '"';
	if(it == json.end()) break;
	ss << ',';
    }
    ss << ']';
    return ss.str();
}
