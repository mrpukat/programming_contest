#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {

	int blocks = 0;
	cin >> blocks;

	vector<int> *array = new vector<int>[blocks];
	map<int, int> blockPos;

	for (int i = 0; i < blocks; ++i) {
		array[i].push_back(i);
		blockPos[i] = i;
	}

	string frome;
	int f;
	string to;
	int t;

	cin >> frome;

	while(frome != "quit") {

		cin >> f;
		cin >> to;
		cin >> t;

		if (blockPos[f] != blockPos[t]) {

			if (frome == "move") {
				
				while(array[blockPos[f]].back() != f) {
					int block = array[blockPos[f]].back();
					array[block].push_back(block);
					array[blockPos[f]].pop_back();
					blockPos[block] = block;
				}
			}

			if (to == "onto") {

				while(array[blockPos[t]].back() != t) {
					int block = array[blockPos[t]].back();
					array[block].push_back(block);
					array[blockPos[t]].pop_back();
					blockPos[block] = block;
				}

			}

			bool fondBlock = false;
			int vectorSize = array[blockPos[f]].size();
			int bp = blockPos[f];
			int counter = 0;

			for (int k = 0; k < vectorSize; ++k){
				if (array[bp][k] == f) fondBlock = true;
				if (fondBlock) {
					int curentBlock = array[bp][k];
					array[blockPos[t]].push_back(curentBlock);
					counter++;
					blockPos[curentBlock] = blockPos[t];
				}
			}
			for (int i = 0; i < counter; ++i) {
				array[bp].pop_back();
			}

		}
		cin >> frome;
	}

	for (int w = 0; w < blocks; ++w) {
		cout << w << ":";
		for (int x = 0; x < array[w].size(); ++x) {
			cout << " " << array[w][x];
		}
		cout << "\n";
	}

	delete[] array;

    return 0;
}