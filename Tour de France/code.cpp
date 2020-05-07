#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

int main() {

	int f;
	int r;

	cin >> f;

	do {

		cin >> r;

		vector<double> v;

		int temp = 0;

		for (int i = 0; i < f; ++i) {

			cin >> temp;
			v.push_back(temp);
		}

		set<double> s;

		for (int j = 0; j < r; ++j) {

			cin >> temp;

			for (int k = 0; k < f; ++k) {
				s.insert(temp/v[k]);
			}
		}

		set<double> final;

		set<double>::iterator endit = --s.end();

		for (set<double>::iterator it = s.begin(); it != endit; ++it) {

			double b =	*(it++);
			double sb = *(it--);

			final.insert(sb/b);

		}

		set<double>::iterator iterat = final.end();

		double res = *(--iterat);

		res = round(res*100)/100;
		printf("%4.2f\n", res);

		cin >> f;

	} while (f != 0);

    return 0;
}