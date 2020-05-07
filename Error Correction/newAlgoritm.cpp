#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {

	int n;
	cin >> n;

	while (n != 0) {

		vector<int> unRow;
		vector<int> unCollum;

		int matrix[n][n];
		for (int i = 0; i < n; ++i) {
			int sum = 0;
			for (int j = 0; j < n; ++j) {
				int input;
				cin >> input;
				matrix[i][j] = input;
				sum += input;
			}
			if (sum % 2 != 0) unRow.push_back(i+1);
		}

		for (int j = 0; j < n; ++j) {
			int sum = 0;
			for (int i = 0; i < n; ++i) {
				sum += matrix[i][j];
			}
			if (sum % 2 != 0) unCollum.push_back(j+1);
		}

		if (unRow.size() == 0 && unCollum.size() == 0) cout << "OK" << endl;
		else if (unRow.size() == 1 && unCollum.size() == 1) cout << "Change bit (" << unRow.back() << "," << unCollum.back() << ")" << endl;
		else cout << "Corrupt" << endl;


		cin >> n;
	}

    return 0;
}