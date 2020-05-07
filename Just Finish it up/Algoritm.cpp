#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool testRoot(int fule[], int cost[], int size, int pos);

int main() {
	int test;
	cin >> test;

	for (int t = 1; t <= test; ++t) {

		int stations;
		cin >> stations;

		int fule[stations];
		int cost[stations+1];
		int sum = 0;

		for (int i = 0; i < stations; ++i) {
			cin >> fule[i];
			sum += fule[i];
		}

		for (int i = 1; i <= stations; ++i) {
			cin >> cost[i];
			sum -= cost[i];
		}

		cout << "Case " << t << ": ";
		if (sum >= 0) {

			int res;

			for (int i = 0; i < stations; ++i) {
				if(testRoot(fule,cost,stations,i)) {
					cout << "Possible from station " << i+1 << endl;
					i = stations;
				}
			}
		} else cout << "Not possible" << endl;

	}

    return 0;
}

bool testRoot(int fule[], int cost[], int size, int pos) {

	int f = 0;
	bool faild = false;

	for (int i = pos; i < size; ++i) {
		f += fule[i];
		f -= cost[i+1];
		if (f < 0) {
			faild = true;
			i = size;
		}
	}

	for (int i = 0; i < pos; ++i) {
		f += fule[i];
		f -= cost[i+1];
		if (f < 0) {
			faild = true;
		}
		if (faild) i = pos;
	}

	return !faild;
}