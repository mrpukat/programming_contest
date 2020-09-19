#include <iostream>
using namespace std;

int main() {

	int a, b, c;
	cin >> a >> b >> c;

	while (a != 0 && b != 0 && c != 0) {

		if (a < c && b < c) {
			if (a*a + b*b == c*c) cout << "right" << endl;
			else cout << "wrong" << endl;
		}
		else if (a < b && c < b) {
			if (a*a + c*c == b*b) cout << "right" << endl;
			else cout << "wrong" << endl;
		}
		else if (b < a && c < a) {
			if (c*c + b*b == a*a) cout << "right" << endl;
			else cout << "wrong" << endl;
		}
		else {
			cout << "wrong" << endl;
		}
		cin >> a >> b >> c;
	}

    return 0;
}