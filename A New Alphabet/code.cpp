#include <iostream>
#include <map>
#include "string"
using namespace std;

int main() {

	map<char,string> althabetMap;
	althabetMap['a'] = "@";
	althabetMap['b'] = "8";
	althabetMap['c'] = "(";
	althabetMap['d'] = "|)";
	althabetMap['e'] = "3";
	althabetMap['f'] = "#";
	althabetMap['g'] = "6";
	althabetMap['h'] = "[-]";
	althabetMap['i'] = "|";	
	althabetMap['j'] = "_|";
	althabetMap['k'] = "|<";
	althabetMap['l'] = "1";
	althabetMap['m'] = "[]\\/[]";
	althabetMap['n'] = "[]\\[]";
	althabetMap['o'] = "0";
	althabetMap['p'] = "|D";
	althabetMap['q'] = "(,)";
	althabetMap['r'] = "|Z";
	althabetMap['s'] = "$";
	althabetMap['t'] = "']['";
	althabetMap['u'] = "|_|";
	althabetMap['v'] = "\\/";
	althabetMap['w'] = "\\/\\/";
	althabetMap['x'] = "}{";
	althabetMap['y'] = "`/";
	althabetMap['z'] = "2";

	string word, newword;
	getline(cin,word);

	for (int i = 0; i < word.size(); ++i) {
		if (word[i] <= 'Z' && word[i] >= 'A') word[i] = word[i] - ('Z' - 'z');
		
		string temp;
		temp = althabetMap[word[i]];
		//cout << "debug" << althabetMap[word[i]] << endl;

		if (temp.empty()) temp = word[i];
		newword.append(temp);
	}

	cout << newword << endl;

    return 0;
}

