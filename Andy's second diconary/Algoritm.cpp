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
		std::vector<string> v;

		while(getline(ss,line,' ')) {
			for (int i = 0; i < line.size(); ++i) {
				if(		 line[i] >= 'A' && line[i] <= 'Z') last += line[i] + ('a' - 'A');
				else if (line[i] >= 'a' && line[i] <= 'z') last += line[i];
				else if (line[i] == '-') 				   last += line[i];
				else {
					dict.insert(last);
					last = "";
				}
			}
			v.push_back(last);
			last = "";
		}
		if (v.size() > 0) {
			next = v.back();
			if (next[next.size()-1] != '-') {
				next = "";
				dict.insert(v.begin(),v.end());
			} else {
				dict.insert(v.begin(),--v.end());
				string t = "";
				for (int j = 0; j < next.size()-1; ++j) t += next[j];
				next = t;
			}  
		}
		getline(cin,line);
	}

	for (std::set<string>::iterator it=dict.begin(); it!=dict.end(); ++it) if (!it->empty())cout << *it << endl;

    return 0;
}