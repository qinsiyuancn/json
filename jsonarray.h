#ifndef __JSONARRAY_H__
#define __JSONARRAY_H__

#include <string>
#include <vector>


class JsonArray
{
public:
    JsonArray();
    JsonArray(const char *);

    operator const char *();
    DataAdapter operator [] (unsigned int);

    unsigned int size();

private:
    vector<std::string> json;
};
#endif
