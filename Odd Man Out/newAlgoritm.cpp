#include <iostream>
#include <set>
using namespace std;


void solve(int i) {

	int guesseds;
	cin >> guesseds;

	set<int> remember;
	set<int>::iterator it;

	for (int i = 0; i < guesseds; ++i) {
		int asked;
		cin >> asked;
		it = remember.find(asked);
		if (it == remember.end()) remember.insert(asked);
		else remember.erase(it);
	}

	it = remember.begin();

	cout << "Case #" << i << ": " << *it << endl;

}


int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		solve(i);
	}

    return 0;
}

