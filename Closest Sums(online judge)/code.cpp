#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

long closesSum(int arr[], int size, int sum);

int main() {

	int cases = 0;
	int n;
	while(cin >> n && n != 0) {

		++cases;

		int arr [n];

		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int sums;
		cin >> sums;

		cout << "Case " << cases << ":" << endl;

		for (int j = 0; j < sums; j++) {

			int sum;
			cin >> sum;

			cout << "Closest sum to " << sum << " is ";
			cout << closesSum(arr,n,sum) << "." << endl;

		}

	}

    return 0;
}


long closesSum(int arr[], int size, int sum) {

	long sdiff = numeric_limits<int>::max();

	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size; j++) {

			if(j != i) {

				long temp = sum-(arr[i] + arr[j]);

				if (temp*temp < sdiff*sdiff) sdiff = temp;

			}
		}
	}


	return (-1)*(sdiff-sum);
}














