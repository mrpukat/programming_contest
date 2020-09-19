#include <iostream>
#include <map>
#include <queue>
using namespace std;

int domino(int dominos,int m,int l);

int main() {

	int tests;
	cin >> tests;

	for (int i = 0; i < tests; ++i) {
		int dominos, m, l;
		cin >> dominos >> m >> l;
		cout << domino(dominos,m,l) << endl;
	}

    return 0;
}


int domino(int dominos,int m,int l) {

	bool is_fallen[dominos+1];
	int fallen = 0;

	multimap<int,int> next_to;
	queue<int> falling_dominons;

	for (int i = 1; i <= dominos; ++i){
		is_fallen[i] = false;
	}

	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		next_to.insert(pair<int,int>(a,b));
	}

	multimap<int,int>::iterator it;

	for (int i = 0; i < l; ++i) {
		int pushed;
		cin >> pushed;

		falling_dominons.push(pushed);

		while (!falling_dominons.empty()) {
			pushed = falling_dominons.front();
			if (!is_fallen[pushed]) {
				is_fallen[pushed] = true;
				fallen++;

				for (it=next_to.equal_range(pushed).first; it!=next_to.equal_range(pushed).second; ++it) {
					falling_dominons.push((*it).second);
				}
			}
			falling_dominons.pop();
		}
	}

	return fallen;
}