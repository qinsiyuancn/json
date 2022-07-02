#ifndef __JSONOBJ_H__
#define __JSONOBJ_H__

#include <map>
#include <string>
#include "dataadapter.h"

class JsonObject
{
public:
    JsonObject();
    JsonObject(const char *);
    
    /*
     * set Json object format string to analize
     * the format like this:
     * { "key1":"value1", "key2", "value2"  }
     */

    operator const char *();
    DataAdapter operator[](const char *);

private:
    std::map<std::string, std::string> json;
};

#endif
