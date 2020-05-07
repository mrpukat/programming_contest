#include <iostream>
#include <fstream>
using namespace std;

int max_el(int array[], int size);
int lis(int array[], int val[], int size);
int lds(int array[], int val[], int size);
int solve(int array[], int size);

int main() {

	/*ofstream output;
	ifstream input;
	input.open("in.txt",ios::in);
	output.open("res.txt", ios::out);*/

	int tests;
	cin >> tests;

	for (int i = 0; i < tests; ++i) {
		int cars;
		cin >> cars;
		int inp[cars];
		for (int j = 0; j < cars; ++j) {
			cin >> inp[j];
		}

		//cout << lis(inp, cars) + lds(inp, cars) -1 << endl;
		//cout << lis(inp,cars) << endl;
		//cout << lds(inp,cars) << endl;
		/*int max = 0;
		for (int j = 0; j < cars; ++j) {
			int t1 = lds(inp, j);
			int t2 = lis(inp, j);
			int temp;
			if (t1 > t2) temp = t1 - 1;
			else temp = t2 - 1;
			if (max < temp) max = temp;
		}
		cout << "-" << max << endl;*/
		/*
		int t1 = lis(inp,cars);
		int t2 = lds(inp,cars);
		if (t1 > t2) output << t1 << endl;
		else output << t2 << endl;*/

		cout << lis(inp,cars) + lds(inp,cars) -1 << endl;
		//cout << lds(inp,cars) << endl;

	}

	//output.close();
	//input.close();


    return 0;
}


int solve(int array[], int size) {

	int lst[size];
	lst[0] = 1;

	for (int i = 1; i < size; ++i) {
		lst[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (array[i] > array[j] && lst[i] < lst[j] + 1) {
				lst[i] = lst[j] + 1;
			}
		}
	}


	return max_el(lst,size);

}


int lis(int array[], int val[], int size) {

	int lst[size];
	lst[0] = 1;

	for (int i = 1; i < size; ++i) {
		lst[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (array[i] > array[j] && lst[i] < lst[j] + 1) {
				lst[i] = lst[j] + 1;
			}
		}
	}


	return max_el(lst,size);

}

int lds(int array[], int val[], int size) {

	int lst[size];
	lst[0] = 1;

	for (int i = 1; i < size; ++i) {
		lst[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (array[i] < array[j] && lst[i] < lst[j] + 1) {
				lst[i] = lst[j] + 1;
			}
		}
	}

	return max_el(lst,size);

}

int max_el(int array[], int size) {
	int el = 0;
	for (int i = 0; i < size; ++i) {
		if (array[i] > el) el = array[i];
	}
	return el;
}