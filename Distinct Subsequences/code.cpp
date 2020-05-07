#include <iostream>
using namespace std;

int main() {


	int test;
	cin >> test;

	for (int t = 0; t < test; ++t) {
		string big, smal;
		cin >> big >> smal;


		bool table[big.size()][smal.size()];
		for (int j = 0; j < big.size(); ++j) {
			for (int i = 0; i < smal.size(); ++i) {
				if (big[j] == big[i]) table[j][i] == true;
				else table[j][i] = false;
			}
		}



	}


    return 0;
}