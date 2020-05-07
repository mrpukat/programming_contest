#include <iostream>
#include <list>
using namespace std;

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


		int arr[size+1]; //Original Array
		int sum[size+1]; //Array used by RSQ
		//int rsq(int x, int y) { return sum[y]-sum[x-1]; }

		for (int i = 1; i <= size; ++i) {
			arr[i] = startArr[i-1];
		}

		/* Pre-computation -> put in int main*/
		memset(sum, 0, sizeof(sum)); //Not required if no multiple testcases
		for (int i = 1; i <= size; ++i) sum[i] = sum[i-1] + arr[i];

		for (int i = 1; i <= size; ++i) {
			cout << sum[i] << " ";
		}

		for (int j = 0; j < moves; ++j) {
			int move;
			cin >> move;

		}
	}


    return 0;
}