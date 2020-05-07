#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

void buildDict(map<char, string>& dict);

int main() {

	map<char,string> dict;

	buildDict(dict);

	string line;

	while(cin >> line) {

//		cin >> line;

		string newString = "";

		for (int i = 0; i < line.size(); ++i) {

			if (dict.end() != dict.find(line[i])) newString += dict[line[i]];
			else newString += line[i];

		}

		cout << newString << endl;

	}

    return 0;
}


void buildDict(map<char, string>& dict) {

	dict['A'] = "2";
	dict['B'] = "2";
	dict['C'] = "2";
	dict['D'] = "3";
	dict['E'] = "3";
	dict['F'] = "3";
	dict['G'] = "4";
	dict['H'] = "4";
	dict['I'] = "4";
	dict['J'] = "5";
	dict['K'] = "5";
	dict['L'] = "5";
	dict['M'] = "6";
	dict['N'] = "6";
	dict['O'] = "6";
	dict['P'] = "7";
	dict['Q'] = "7";
	dict['R'] = "7";
	dict['S'] = "7";
	dict['T'] = "8";
	dict['U'] = "8";
	dict['V'] = "8";
	dict['W'] = "9";
	dict['X'] = "9";
	dict['Y'] = "9";
	dict['Z'] = "9";
}