#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {

	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i) {

		double size;
		cin >> size;
		int anser = size/2;
		int res;
		for(int k = 0; k < size; ++k) {
			int temp;
			cin >> temp;
			if (k == anser) res = temp;
		}

		cout << "Case " << i << ": " << res << endl;

	}
	

    return 0;
}