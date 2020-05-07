#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
using namespace std;


void getDict(map<string,string>& dict);


int main() {
    

	map<string,string> dict;

	getDict(dict);


	string line;

	while(getline (cin,line)) {

		map<string,string>::iterator con = dict.find(line);

		if (con != dict.end()) cout << con->second << endl;
		else cout << "eh"<< endl;

	}



    return 0;
}



void getDict(map<string,string>& dict) {

	string line;

	while(getline (cin,line) && line != "") {

		std::vector<string> v;

		stringstream ss(line);
    	string token;
    	while (getline(ss, token, ' ')) {
        	v.push_back(token);
    	}

    	if (v.size() > 1) dict.insert ( pair<string,string>(v.at(1),v.at(0)) );

	}

}