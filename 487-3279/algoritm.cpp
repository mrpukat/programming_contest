#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
using namespace std;

void makeMap(map<char, char>& index);

int main() {

	map<char, char> index;
	makeMap(index);


	int tests;
	cin >> tests;

	for (int i = 0; i < tests; ++i) {
		
		map<string, int> counter;
		set<string> things;

		int cases;
		cin >> cases;

		for (int j = 0; j < cases; ++j) {
			
			string line;
			cin >> line;

			string newLine = "";

			for (int k = 0; k < line.size(); ++k) {
				
				if (line[k] > 47 && line[k] < 58) newLine += line[k];
				else if (index.find(line[k]) != index.end()) newLine += index[line[k]];

				if (newLine.size() == 3) newLine += '-';
			}

			if (newLine.size() == 8) {

				if(things.find(newLine) != things.end()) {
					counter[newLine] += 1;
				} else {
					things.insert(newLine);
					counter[newLine] = 1;
				}
			}

		}
		bool duplicects = false;
		for(auto word : things) {
			if (counter[word] != 1) {
				cout << word << " " << counter[word] << endl;
				duplicects = true;
			}
		}

		if(!duplicects) cout << "No duplicates." << endl;

		if (i+1 != tests) cout << endl;
	}
	
    return 0;
}

void makeMap(map<char, char>& index) {


	index['A'] = '2';
	index['B'] = '2';
	index['C'] = '2';

	index['D'] = '3';
	index['E'] = '3';
	index['F'] = '3';

	index['G'] = '4';
	index['H'] = '4';
	index['I'] = '4';

	index['J'] = '5';
	index['K'] = '5';
	index['L'] = '5';

	index['M'] = '6';
	index['N'] = '6';
	index['O'] = '6';

	index['P'] = '7';
	index['R'] = '7';
	index['S'] = '7';

	index['T'] = '8';
	index['U'] = '8';
	index['V'] = '8';

	index['W'] = '9';
	index['X'] = '9';
	index['Y'] = '9';
}