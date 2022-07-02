#include <iostream>
#include <fstream>
#include <sstream>

#include "jsonobject.h"
#include "jsonarray.h"

using namespace std;


int readConfig(string & ret)
{
    ifstream in("test.json");
    ostringstream ost;
    ost << in.rdbuf();
    in.close();
    ret = ost.str();
    ost.close();
    return 0;
}

int main(void)
{
   string a, b;
   string::const_iterator start,end;
   readConfig(a);
   cout << a << endl;
   cout << "========华丽的分隔线========" << endl;
   JsonObject json = a.c_str();
   cout << "version -> " << json["version"] << endl;
   cout << "comment -> " << json["comment"] << endl;
   cout << "content -> " << json["content"] << endl;
   JsonArray array = json["content"];
   for(unsigned int i = 0; i < array.size(); i++)
       cout << "content[" << i << "] = " << array[i] << endl;
    return 0;
}

