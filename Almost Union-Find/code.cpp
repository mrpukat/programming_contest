#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void Union(vector<int> *arr, map<int, int>& pos);
void move(vector<int> *arr, map<int, int>& pos);
void sum(vector<int> *arr, map<int, int>& pos);

int main() {

	int sets, numOper;

	while(cin >> sets >> numOper) {

		vector<int> *array = new vector<int>[sets+1];
		map<int, int> numberPos;

		for (int i = 1; i <= sets; ++i) {
			array[i].push_back(i);
			numberPos[i] = i;
		}

		for (int i = 0; i < numOper; ++i) {
			int operation;
			cin >> operation;

			switch(operation) {
  				case 1:
    				Union(array, numberPos);
    				break;
  				case 2:
    				move(array, numberPos);
					break;
  				case 3:
   					sum(array, numberPos);
	  				break;
			}
		}

		delete[] array;

	}
	
    return 0;
}

void Union(vector<int> *arr, map<int, int>& pos) {

	int i, j;
	cin >> i >> j;

	if (pos[i] != pos[j]) {
		int p = pos[i];
		while(!arr[p].empty()) {
			arr[pos[j]].push_back(arr[p].back());
			pos[arr[p].back()] = pos[j];
			arr[p].pop_back();
		}
	}

}

void move(vector<int> *arr, map<int, int>& pos) {

	int i, j;
	cin >> i >> j;

	if(pos[i] != pos[j]) {

		int size = arr[pos[i]].size();		

		for (int k = 0; k < size; ++k) {
			if (arr[pos[i]].at(k) == i) {
				arr[pos[i]].erase(arr[pos[i]].begin()+k);
				arr[pos[j]].push_back(i);
				break;
			}
		}
		pos[i] = pos[j];
	}
}

void sum(vector<int> *arr,map<int, int>& pos) {

	int i;
	cin >> i;

	int size = arr[pos[i]].size();
	int sum = 0;
	for (int k = 0; k < size; ++k) {
		sum += arr[pos[i]].at(k);
	}

	cout << size << " " << sum << endl;

}