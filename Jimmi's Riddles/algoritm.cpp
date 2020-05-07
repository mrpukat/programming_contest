#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

bool getInputLine(string line, vector<int>& comandLine, map<string, int> comadMap);
void makeComadMap(map<string, int>& comandMap);
void combineVerbs(vector<int>& comandLine, int first, int second);
void makeAction(vector<int>& comandLine, int first);
void makeActor(vector<int>& comandLine, int first);
void makeActiceList(vector<int>& comandLine, int first);
void makeStatment(vector<int>& comandLine, int first);
bool activeListMaker(vector<int>& comandLine, int start);

/*
 * Statment = 1
 * Action = 2
 * ACTIVE_LIST = 3
 * ACTOR = 4
 * ARTICLE = 5
 * AND = 6
 * NOUN = 7
 * VERB = 8
 * , = 9
 */

int main() {

	map<string ,int> comandMap;
	makeComadMap(comandMap);

	string line;

	while (getline(cin,line)) {
		
		int first = 0;
		int second = 0;
		bool done = false;
		vector<int> comandLine;

		if (!getInputLine(line,comandLine,comandMap)) done = true;

		if (comandLine.empty()) done = true;

		while (!done) {
			int combination = 0;

			while (second - first > 2) ++first;

			for (int i = first; i <= second; ++i){
				combination += comandLine[i]*(pow(10,second-i));
			}
			
			//cout << combination << endl;
			//cout << first << " " << second << endl;

			switch (combination) {

				case 8:
					if (comandLine.size() == first + 1) done = true;
					else if(!activeListMaker(comandLine,first+1)) done = true;
					if (first < second) ++first;
					else if (second+1 != comandLine.size()) {
						first = 0;
						++second;
					} else done = true;
					break;
				case 2:
					comandLine[first] = 1;
					first = 0;
					second = 0;
					break;
				case 7:
					comandLine[first] = 4;
					first = 0;
					second = 0;
					break;
				case 4:
					comandLine[first] = 3;
					first = 0;
					second = 0;
					break;
				case 383:
					makeAction(comandLine,first);
					first = 0;
					second = 0;
					break;
				case 57:
					makeActor(comandLine,first);
					first = 0;
					second = 0;
					break;
				case 364:
					makeActiceList(comandLine,first);
					first = 0;
					second = 0;
					break;
				case 192:
					makeStatment(comandLine,first);
					first = 0;
					second = 0;
					break;
				default:
					if (first < second) ++first;
					else if (second+1 != comandLine.size()) {
						first = 0;
						++second;
					} else done = true;
			}

		}

		if (comandLine.size() == 1 && comandLine.at(0) == 1) cout << "YES I WILL" << endl;
		else cout << "NO I WON'T" << endl;

	}

    return 0;
}

bool activeListMaker(vector<int>& comandLine, int start) {

	int first = start;
	int second = start;
	bool done = false;

	while (!done) {

		while (second - first > 2) ++first;


		int combination = 0;
		for (int i = first; i <= second; ++i){
			combination += comandLine[i]*(pow(10,second-i));
		}
		
		//cout << combination << endl;
		//cout << first << " " << second << endl;

		switch (combination) {

			case 8:
				if (comandLine.size() == first + 1) done = true;
				else if(!activeListMaker(comandLine,first+1)) done = true;
				if (first < second) ++first;
					else if (second+1 != comandLine.size()) {
						first = start;
						++second;
					} else done = true;
				break;
			case 7:
				comandLine[first] = 4;
				first = start;
				second = start;
				break;
			case 4:
				comandLine[first] = 3;
				first = start;
				second = start;
				break;
			case 57:
				makeActor(comandLine,first);
				first = start;
				second = start;
				break;
			case 364:
				makeActiceList(comandLine,first);
				first = start;
				second = start;
				break;
			/*case 192:
				makeStatment(comandLine,first);
				first = start;
				second = start;
				break;*/
			default:
				if (first < second) ++first;
				else if (second+1 != comandLine.size() && comandLine.at(second+1) != 9) {
					first = start;
					++second;
				} else done = true;
		}

	}

	if(comandLine.size() == start+1 || (comandLine.size() > second+1 && comandLine.at(second+1) == 9)) return true;
	else return false;
}

bool getInputLine(string line, vector<int>& comandLine, map<string, int> comadMap) {

	stringstream ss(line);
	string word;

	while(ss >> word) {
		bool saved = false;
		if (word.size() > 1 && word[word.size()-1] == ',') {
			saved = true;
			word.pop_back();
		}

		if(comadMap.find(word) == comadMap.end()) return false;

		comandLine.push_back(comadMap[word]);
		if (saved) comandLine.push_back(9);
	}

	return true;
}

void makeComadMap(map<string, int>& comadMap) {

	comadMap["tom"] = 7;
	comadMap["jerry"] = 7;
	comadMap["goofy"] = 7;
	comadMap["mickey"] = 7;
	comadMap["jimmy"] = 7;
	comadMap["dog"] = 7;
	comadMap["cat"] = 7;
	comadMap["mouse"] = 7;

	comadMap["hate"] = 8;
	comadMap["love"] = 8;
	comadMap["know"] = 8;
	comadMap["like"] = 8;
	comadMap["hates"] = 8;
	comadMap["loves"] = 8;
	comadMap["knows"] = 8;
	comadMap["likes"] = 8;

	comadMap["a"] = 5;
	comadMap["the"] = 5;

	comadMap["and"] = 6;

	comadMap[","] = 9;
}

void makeAction(vector<int>& comandLine, int first) {
	vector<int>::iterator it = comandLine.begin();
	comandLine.erase(it+first+1,it+first+3);
	comandLine[first] = 2;
}

void makeActor(vector<int>& comandLine, int first) {
	vector<int>::iterator it = comandLine.begin();
	comandLine.erase(it+first+1,it+first+2);
	comandLine[first] = 4;
}

void makeActiceList(vector<int>& comandLine, int first) {
	vector<int>::iterator it = comandLine.begin();
	comandLine.erase(it+first+1,it+first+3);
	comandLine[first] = 3;
}

void makeStatment(vector<int>& comandLine, int first) {
	vector<int>::iterator it = comandLine.begin();
	comandLine.erase(it+first+1,it+first+3);
	comandLine[first] = 1;
}
