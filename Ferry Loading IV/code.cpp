#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

int solve();
void SortInto(queue<int>& left, queue<int>& rigth);

int main() {

	string line;

	getline(cin,line);

	int c = stoi(line);


	for (int i = 0; i < c; i++) cout << solve() << endl;


    return 0;
}


int solve() {

	queue<int> left;
	queue<int> rigth;

	string line;

	getline(cin, line, ' ');
	int len = stoi(line)*100;

 	SortInto(left,rigth);

	int counter = 0;
	bool leftSide = true;

	while (left.size()+rigth.size() > 0) {

		int curentLode = 0;
		++counter;

		if (leftSide) { 
			while (!left.empty() && curentLode + left.front() < len) {

				curentLode += left.front();
				left.pop();
			}

			leftSide = false;

		} else {
			while (!rigth.empty() && curentLode + rigth.front() < len) {

				curentLode += rigth.front();
				rigth.pop();
			}

			leftSide = true;
		}


	}

	return counter;
}


void SortInto(queue<int>& left, queue<int>& rigth) {

	string line;

	getline(cin, line);
	int m = stoi(line);

	for (int i = 0; i < m; i++) {

		getline(cin, line, ' ');
		int size = stoi(line);
		getline(cin,line);

		if (line == "left") left.push(size);
		else rigth.push(size);
	}

}

