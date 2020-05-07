#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {

	int plug;
	while(cin >> plug) {
		vector<int> vekt;
		vekt.push_back(plug);
		for (int i = 0; i < 4; ++i) {
			cin >> plug;
			vekt.push_back(plug);
		}
		bool falil = false;
		for (int i = 0; i < 5; ++i) {
			cin >> plug;
			if (vekt[i] + plug != 1) falil = true;
		}
		if (falil) cout << "N" << endl;
		else cout << "Y" << endl;
	}

    return 0;
}