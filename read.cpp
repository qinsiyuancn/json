#include <iostream>
#include <fstream>
#include <sstream>

#include "jsonobj.h"
#include "jsonarray.h"

using namespace std;


int readConfig(string & ret)
{
    ifstream in("test.json");
    ostringstream ost;
    ost << in.rdbuf();
    in.close();
    ret = ost.str();
    return 0;
}

int main(void)
{
    string a, b;
    string::const_iterator start,end;
    readConfig(a);
    cout << a << endl;
    cout << "========华丽的分隔线========" << endl;
    JsonObject json = a;
    const char * version = json["version"];
    const char * comment = json["comment"];
    const char * content = json["content"];
    cout << "version -> " << version << endl;
    cout << "comment -> " << comment << endl;
    cout << "content -> " << content << endl;
    JsonArray array = string(content);
    for(unsigned int i = 0; i < array.size(); i++){
        const char * tmp = array[i];
        cout << "content[" << i << "] = " << tmp << endl;
   }
    return 0;
}

