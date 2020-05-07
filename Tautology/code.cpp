#include <iostream>
#include <string>
using namespace std;
/*
char table[2][2][5] = {
	{}
}
*/
bool isTautology(string &line);

int main() {

	string line;

	while (cin >> line && line != "0") {
		cout << (isTautology(line) ? "tautology" : "not") << endl;
	}

    return 0;
}

bool isTautology(string &line) {




}
