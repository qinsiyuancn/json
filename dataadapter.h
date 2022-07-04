#ifndef __DATA_ADAPTER_H__
#define __DATA_ADAPTER_H__

#include <string>
#include <sstream>
class DataAdapter
{
public:
    DataAdapter(std::string & data):data(data){}
    
    template<typename T>
    T getValue()
    {
	T ret;
	std::stringstream ss;
	ss << data;
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
        return data;
    }
private:
    std::string &data;

};

#endif
