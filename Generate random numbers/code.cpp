#include <iostream>
#include <unordered_set>
using namespace std;

int main() {

	long int seed;
	cin >> seed;
	while(seed != 0) {

		int count = 0;
		unordered_set<int> path;
		while(path.find(seed) == path.end()) {
			path.insert(seed);
			++count;
			seed *= seed;
       		seed /= 100;
        	seed = seed % 10000;
		}

		cout << count << endl;

		cin >> seed;
	}
	
    return 0;
}