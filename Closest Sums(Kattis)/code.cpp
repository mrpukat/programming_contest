#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

long closesSum(int* arr, int size, int sum);

int main() {


	string line;

	int cases = 0;

	while(getline(cin,line) && !line.empty()) {

		++cases;

		int n = stoi(line);

		int arr [n];

		for(int i = 0; i < n; i++) {

			getline(cin,line);		
			arr[i] = stoi(line);

		}

		getline(cin,line);

		int sums = stoi(line);

		cout << "Case " << cases << ":" << endl;

		for (int j = 0; j < sums; j++) {

			getline(cin,line);

			int sum = stoi(line);

			cout << "Closest sum to " << sum << " is ";
			cout << closesSum(&arr[0],n,sum) << "." << endl;

		}

	}

    return 0;
}


long closesSum(int* arr, int size, int sum) {

	long sdiff = sum - (arr[0] + arr[1]);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

			if(j != i) {

				long temp = sum-(arr[i] + arr[j]);

				if (temp*temp < sdiff*sdiff) sdiff = temp;

			}
		}
	}


	return (-1)*(sdiff-sum);
}














