#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main() {

	string next = "";
	set<string> dict;

	string line;
	getline(cin,line);

	while (!cin.eof()) {

		stringstream ss(line);

		string last = next;

		while(getline(ss,line,' ')) {
			for (int i = 0; i < line.size(); ++i) {
				if(		 line[i] >= 'A' && line[i] <= 'Z') last += line[i] + ('a' - 'A');
				else if (line[i] >= 'a' && line[i] <= 'z') last += line[i];
				else {
					dict.insert(last);
					last = "";
				}
			}
			dict.insert(last);
			last = "";
		}

		getline(cin,line);
	}

	for (std::set<string>::iterator it=dict.begin(); it!=dict.end(); ++it) if (!it->empty())cout << *it << endl;

    return 0;
}