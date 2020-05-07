#include <iostream>
#include <string>
using namespace std;

int main() {

	int guess;
	cin >> guess;
	int low = -1;
	int hig = 11;
	while(guess != 0) {
		string res;
		cin >> res;
		cin >> res;
		if (res == "high") {
			if (guess < hig) hig = guess;
		} 
		else if (res == "low") {
			if (guess > low) low = guess;
		}
		else {
			if (low >= hig) cout << "Stan is dishonest" << endl;
			else if (guess >= hig) cout << "Stan is dishonest" << endl;
			else if (guess <= low) cout << "Stan is dishonest" << endl;
			else cout << "Stan may be honest" << endl;
			low = -1;
			hig = 11;
		}
		cin >> guess;
	}

    return 0;
}