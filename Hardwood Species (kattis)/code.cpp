#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

void readAria();

int main() {

	//string line;
	//getline(cin,line);
	//int testCases = stoi(line);
	//getline(cin,line); // Read empty line

	readAria();

	/*for (int i = 0; i < testCases; ++i) {
		readAria();
		if (i != testCases-1) cout << endl;
	}*/

    return 0;
}

void readAria() {

	int count = 0;
	string line;
	map<string, int > treeMap;
	while(!cin.eof() && getline(cin,line) && !line.empty()) {

		count++;
		treeMap[line]++;

	}

	cout << setprecision(6) << fixed;

  	for (auto& el: treeMap) {
  		double temp = (double)el.second/count;
   		cout << el.first << " " << temp*100 << endl;
  	}

}