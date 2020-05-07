#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <math.h>
using namespace std;

int main() {

	int n;
	int conter = 0;;

	while (cin >> n) {

		conter++;

		map<string, int> myMap;
		std::vector<string> v;

		for (int i = 0; i < n; ++i) {
			string name;

			cin >> name;
			v.push_back(name);
			myMap[name] = 0;
		}


		for (int k = 0; k < n; ++k) {

			string giver;
			cin >> giver;
			int sum;
			cin >> sum;

			myMap[giver] -= sum;

			int m;
			cin >> m;
			if (m != 0) {
				int rest = sum % m;

				sum -= rest;
				myMap[giver] += rest;
			} else {
				myMap[giver] += sum;
				sum = 0;
			}

			for (int j = 0; j < m; ++j) {
				string resiver;
				cin >> resiver;
				myMap[resiver] += sum/m;
			}
		}

  		map<string,int>::iterator it;

  		if (conter > 1) cout <<'\n';;
  		

		for (int l = 0; l < n; ++l) {
			it = myMap.find(v[l]);
			cout << it->first << " " << it->second << endl;
		}

		//cout << '\n';

	}
	

    return 0;
}