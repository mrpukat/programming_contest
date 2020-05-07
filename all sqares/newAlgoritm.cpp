#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void GetInput(int& k,int& x,int& y);
bool inBounds(int x,int y,int sqareEge);
bool allZero(int a,int b, int c);

int main() {

	int k;
	int x;
	int y;
	GetInput(k,x,y);

	while (!allZero(k,x,y)) {

		int bounds = 0;
		int sqareEge = 1024;
		int boardSize = 2048;

		while (k >= 1) {

			if (x > sqareEge) x = 2*sqareEge - x;
			if (y > sqareEge) y = 2*sqareEge - y;

			sqareEge = sqareEge - k;

			if (inBounds(x,y,sqareEge)) bounds++;
			k /= 2;

		}

		cout << "  " << bounds << endl;

		GetInput(k,x,y);
	}

    return 0;
}

void GetInput(int& k,int& x,int& y) {
	cin >> k;
	cin >> x;
	cin >> y;
}

bool inBounds(int x,int y,int sqareEge) {

	//cout  << sqareEge << " " <<  x << " " << y << endl;

	if(x >= sqareEge && y >= sqareEge) return true;
	else return false;

}

bool allZero(int a,int b, int c) {

	if (a == 0 && b == 0 && c == 0) return true;
	else return false;
}