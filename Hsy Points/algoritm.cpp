#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int main() {

	map<string, int> dict;
	int m;
	cin >> m;
	int n;
	cin >> n;
	for (int i = 0; i < m; ++i) {
		string line;
		cin >> line;
		int dollar;
		cin >> dollar;
		dict[line] = dollar;
	}

	for (int i = 0; i < n; ++i) {
		string word;
		cin >> word;
		int points = 0;
		while (word != ".") {
			if (dict.find(word) != dict.end()) points += dict[word];
			cin >> word;
		}
		cout << points << endl;
	}

    return 0;
}