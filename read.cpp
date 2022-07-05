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
    const char * comment = json["comment"];
    string content = json["content"];
    cout << "version -> " << version.c_str() << endl;
    cout << "comment -> " << comment << endl;
    cout << "content -> " << content.c_str() << endl;
    JsonArray array = content;
    for(unsigned int i = 0; i < array.size(); i++){
        string tmp = array[i];
        cout << "content[" << i << "] = " << tmp.c_str() << endl;
        JsonObject contentJO = tmp;
	string condition = contentJO["condition"];
	cout << "condition -> " << condition << endl;
	string config = contentJO["config"];
	cout << "config -> " << config.c_str() << endl;


	JsonObject conditionJO = condition;
	string env = conditionJO["env"];
	cout << "env -> " << env.c_str() << endl;

        string type = conditionJO["type"];
	cout << "type -> " << type.c_str() << endl;

	int value = conditionJO["value"];
	cout << "value -> " << value << endl;

        JsonObject configJO = config;
	unsigned int cameraid = configJO["cameraid"];
	cout << "cameraid -> " << cameraid << endl;

	string configstr = configJO["param"];
        cout << "param -> " << configstr.c_str() << endl;	
    }
    return 0;
}

