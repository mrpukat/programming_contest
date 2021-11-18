#include <iostream>
#include "string"
using namespace std;

string althabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

void solve(int n) {
	string word, encryped;
	cin >> word;

	for (int i = word.size()-1; i >= 0; --i) {
		int pos = althabet.find(word[i]);
		int newpos;
		if (pos + n >= althabet.size()) newpos = (pos + n) - althabet.size();
		else newpos = pos + n;
		encryped.push_back(althabet[newpos]);
	}

	cout << encryped << endl;

}


int main() {

	int n;

	while (cin >> n && n != 0) {
		solve(n);
	}

    return 0;
}

