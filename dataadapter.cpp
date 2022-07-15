#include "json.h"

CopyDataAdapter RefDataAdapter::operator [] (const char * key)
{
    return JsonObject(data).getValue(key);
}

CopyDataAdapter RefDataAdapter::operator [] (unsigned int index)
{
    return JsonArray(data).getValue(index);
}

CopyDataAdapter CopyDataAdapter::operator [] (const char * key)
{
    return JsonObject(data).getValue(key);
}

CopyDataAdapter CopyDataAdapter::operator [] (unsigned int index)
{
    return JsonArray(data).getValue(index);
}
