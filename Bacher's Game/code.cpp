#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void solveGame(int stone, int table[], vector<int>& uMove);

int main() {

	int stone;
	while(cin >> stone) {

		int table[stone+1];
		memset(table, -1, sizeof(table));

		int moves;
		cin >> moves;
		vector<int> uMove;
		for (int i = 0; i < moves; ++i) {
			int cur;
			cin >> cur;
			uMove.push_back(cur);
		}

		for (int i = 0; i < moves; ++i) {
			int cur = uMove.at(i);
			if (cur <= stone) table[cur] = 1;
		}

		solveGame(stone, table, uMove);

		if (table[stone] == 1) cout << "Stan wins" << endl;
		else cout << "Ollie wins" << endl;
	}

    return 0;
}

void solveGame(int stone, int table[], vector<int>& uMove) {

	if (stone < 1) return;

	for (int i = uMove.size()-1; i >= 0; --i) {
		int current = stone - uMove.at(i);
		if (current > 0) {
			if (table[current] == -1) {
				solveGame(current,table,uMove);
			}

			if (table[current] == 0) {
				table[stone] = 1;
			}
		}
	}

	if (table[stone] == -1) table[stone] = 0;
}