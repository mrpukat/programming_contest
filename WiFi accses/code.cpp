#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef pair<int,int> cords;

int distace(int x,int y,int X, int Y);

int main() {

	int tests;
	cin >> tests;

	for (int t = 1; t <= tests; ++t) {
		cout << "Case " << t << ":\n";

		int roters, locations;
		cin >> roters >> locations;

		vector<pair<cords,int> > rotersCords;

		for (int i = 0; i < roters; ++i) {
			int x, y, r;
			cin >> x >> y >> r;
			rotersCords.push_back(make_pair(make_pair(x,y),r));
		}

		for (int i = 0; i < locations; ++i) {
			int x, y;
			cin >> x >> y;

			bool conected = false;

			for (int r = 0; r < roters; ++r) {
				int X = rotersCords[r].first.first;
				int Y = rotersCords[r].first.second;
				int R = rotersCords[r].second;
				conected = (distace(x,y,X,Y) <= R*R);
				if (conected) break;
			}

			if (conected) cout << "Yes\n";
			else cout << "No\n";

		}


	}

    return 0;
}

int distace(int x,int y,int X, int Y) {
	int resX, resY;
	if (x > X) resX = x - X;
	else resX = X - x;
	if (y > Y) resY = y - Y;
	else resY = Y - y;
	return resX*resX + resY*resY;
}