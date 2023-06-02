#ifndef __JSON_H__
#define __JSON_H__

#include <string>
#include <sstream>
#include <map>
#include <vector>

class DataAdapter
{
public:
    DataAdapter(){}
    virtual std::string &getData() = 0;
    
    template<typename T>
    T getValue()
    {
	T ret;
	std::stringstream ss;
	ss << getData().c_str();
        ss >> ret;
	return ret;
    }

    operator char()
    {
        return getValue<char>();
    }

    operator unsigned char()
    {
        return getValue<unsigned char>();
    }

    operator int()
    {
        return getValue<int>();
    }

    operator unsigned int()
    {
        return getValue<unsigned int>();
    }

    operator short()
    {
        return getValue<short>();
    }

    operator unsigned short()
    {
        return getValue<unsigned short>();
    }

    operator long()
    {
        return getValue<long>();
    }

    operator unsigned long()
    {
        return getValue<unsigned long>();
    }

    operator long long()
    {
        return getValue<long long>();
    }

    operator unsigned long long()
    {
        return getValue<unsigned long long>();
    }

    operator std::string()
    {
        return getData();
    }

    

};

class CopyDataAdapter : public DataAdapter
{
public:
    CopyDataAdapter(std::string data):data(data){}
    std::string &getData() { return data; }
    CopyDataAdapter operator [] (const char * key);

    CopyDataAdapter operator [] (unsigned int index);

private:
    std::string data;
};

class RefDataAdapter : public DataAdapter
{
public:
    RefDataAdapter(std::string & data):data(data){}
    std::string &getData(){ return data; }

    std::string operator = (std::string data)
    {
        return this->data = data;
    }

    template<typename T>
    std::string setValue (T data)
    {
        std::stringstream ss;
	ss << data;
	this->data = ss.str();
	return this->data;
    }

    std::string operator = (const char * data)
    {
        return setValue(data);
    }

    std::string operator = (int data)
    {
        return setValue(data);
    }

    std::string operator = (unsigned int data)
    {
        return setValue(data);
    }

    std::string operator = (short data)
    {
        return setValue(data);
    }

    std::string operator = (unsigned short data)
    {
        return setValue(data);
    }

    std::string operator = (long data)
    {
        return setValue(data);
    }

    std::string operator = (unsigned long data)
    {
        return setValue(data);
    }

    std::string operator = (long long data)
    {
        return setValue(data);
    }

    std::string operator = (unsigned long long data)
    {
        return setValue(data);
    }

    CopyDataAdapter operator [] (const char * key);

    CopyDataAdapter operator [] (unsigned int index);

    operator const char *()
    {
        return getData().c_str();
    }
private:
    std::string & data;
};

class JsonObject
{
public:
    JsonObject();
    JsonObject(std::string);
    
    /*
     * set Json object format string to analize
     * the format like this:
     * { "key1":"value1", "key2", "value2"  }
     */

    operator std::string();
    CopyDataAdapter getValue(const char *);
    RefDataAdapter operator[](const char *);

private:
    std::map<std::string, std::string> json;
};

class JsonArray
{
public:
    JsonArray();
    JsonArray(std::string);

    operator std::string();
    CopyDataAdapter getValue(unsigned int);
    RefDataAdapter operator [] (unsigned int);

    unsigned int size();

private:
    std::vector<std::string> json;
};
#endif
