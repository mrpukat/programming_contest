#include <iostream>
#include <list>
using namespace std;

int getMove(list<int> &stack, int move, int array[]);

int main() {


	int tests;
	cin >> tests;

	for (int i = 0; i < tests; ++i) {
		int size, moves;
		cin >> size >> moves;
		list<int> lstack;
		int startArr[size];

		for (int j = 1; j <= size; ++j) {
			startArr[j-1] = j;
		}

		for (int j = 0; j < moves; ++j) {
			int move;
			cin >> move;

			if (j == 0) cout << getMove(lstack, move, startArr);
			else cout << " " << getMove(lstack, move, startArr);

		}
		cout << '\n';
	}


    return 0;
}


int getMove(list<int> &stack, int move, int array[]) {

	if (array[move-1] != -1) {
		array[move-1] = -1;
		stack.push_back(move);
		return move -2 + stack.size();
	}

	int pos = 0;
	list<int>::iterator it;

	for (it = stack.begin(); it != stack.end(); ++it) {
		pos++;
		if (*it == move) {
			stack.erase (it);
			stack.push_back(move);
			break;
		}
	}
    
	return stack.size() -pos;
}