#include <iostream>
#include <string>
#include <vector>
using namespace std;

void removeSpace(string& line);

int main() {

	string isbn;
	while(getline(cin,isbn)) {

		removeSpace(isbn);

		int count = 0;

		vector<int> parsel_sums;

		for (int i = 0; i < isbn.size(); ++i) {
			char c = isbn[i];
			if((c >= '0' && c <= '9') || c == 'X') {
				++count;

				int posebulInt = c - '0';
				if (parsel_sums.empty()) {
					if (c == 'X') count--;
					else parsel_sums.push_back(posebulInt);
				}
				else if (c == 'X') {
					if (count == 10) parsel_sums.push_back(parsel_sums.back() + 10);
					else count--;
				}
				else parsel_sums.push_back(parsel_sums.back() + posebulInt);
			}
			else if (c != '-' && c != ' ') count = 11;
		}

		if (count == 10) {
			int sum = 0;
			for (int i = 0; i < parsel_sums.size(); ++i) {
				sum += parsel_sums[i];
			}
			if (sum % 11 == 0) cout << isbn << " is correct." << endl;
			else cout << isbn << " is incorrect." << endl;
		}
		else cout << isbn << " is incorrect." << endl;
	}



    return 0;
}

void removeSpace(string& line) {
	int i = 0;
	while(line[i] == ' '){
		i++;
	}
	int j = line.size()-1;
	while(line[j] == ' '){
		j--;
	}
	j++;
	line = line.substr(i,j-i);
}