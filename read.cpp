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
    string version = json["version"];
    string comment = json["comment"];
    string content = json["content"];
    cout << "version -> " << version.c_str() << endl;
    cout << "comment -> " << comment.c_str() << endl;
    cout << "content -> " << content.c_str() << endl;
    JsonArray array = string(content);
    for(unsigned int i = 0; i < array.size(); i++){
        string tmp = array[i];
        cout << "content[" << i << "] = " << tmp.c_str() << endl;
   }
    return 0;
}

