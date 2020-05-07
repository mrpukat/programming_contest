#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
using namespace std;

int max_el(int array[], int size);
int build_train(int array[], int size);

int main() {

	ofstream output;
	ifstream input;
	input.open("long.txt",ios::in);
	output.open("res.txt", ios::out);

	int tests;
	input >> tests;

	for (int i = 0; i < tests; ++i) {
		int cars;
		input >> cars;
		int inp[cars];
		for (int j = 0; j < cars; ++j) {
			input >> inp[j];
		}

		output << build_train(inp, cars) << endl;

	}

	input.close();
	output.close();

    return 0;
}

int build_train(int array[], int size) {

	vector<list<int> > lst;

	for (int i = 0; i < size; ++i) {
		int currentSize = lst.size();
		for (int j = 0; j < currentSize; ++j) {
			list<int> first (lst[j]);
			if (array[i] > lst[j].back() ) {
				first.push_back(array[i]);
				lst.push_back( first );
			}
			else if (array[i] < lst[j].front() ) {
				first.push_front(array[i]);
				lst.push_back( first );
			}
		}
		list<int> first (1,array[i]);
		lst.push_back(first);

	}

	int el = 0;

	for (int i = 0; i < lst.size(); ++i) {
		if (el < lst[i].size()) el = lst[i].size();
	}

	return el;
}