#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

void makeMap(map<char, char>& dict);

int main() {

	string world;
	map<char, char> dict;
	makeMap(dict);

	while (cin >> world) {

		int i = 0;
		int j = world.size()-1;
		bool ispalondrome = true;
		bool ismirror = true;

		while (j - i >= 0) {
			if(world[i] != world[j]) ispalondrome = false;
			if(dict.find(world[i]) != dict.end()) {
				if (dict[world[i]] != world[j]) ismirror = false;
			} else ismirror = false;
			++i;
			--j;
		}

		cout << world;
		if(ismirror && ispalondrome) cout << " -- is a mirrored palindrome.\n" << endl;
		else if(ismirror) 			 cout << " -- is a mirrored string.\n" << endl;
		else if(ispalondrome) 		 cout << " -- is a regular palindrome.\n" << endl;
		else 						 cout << " -- is not a palindrome.\n" << endl;
	}

    return 0;
}

void makeMap(map<char, char>& dict) {
	dict['A'] = 'A';
	dict['E'] = '3';
	dict['H'] = 'H';
	dict['I'] = 'I';
	dict['J'] = 'L';
	dict['L'] = 'J';
	dict['M'] = 'M';
	dict['O'] = 'O';
	dict['S'] = '2';
	dict['T'] = 'T';
	dict['U'] = 'U';
	dict['V'] = 'V';
	dict['W'] = 'W';
	dict['X'] = 'X';
	dict['Y'] = 'Y';
	dict['Z'] = '5';
	dict['1'] = '1';
	dict['2'] = 'S';
	dict['3'] = 'E';
	dict['5'] = 'Z';
	dict['8'] = '8';
}