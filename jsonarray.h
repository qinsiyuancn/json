#ifndef __JSONARRAY_H__
#define __JSONARRAY_H__

#include <string>
#include <vector>

#include "dataadapter.h"

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
