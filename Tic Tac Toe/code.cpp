#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool readGrid();
int getWins(char grid[3][3], char player);

int main() {

	int testCases;
	cin >> testCases;


	for (int i = 0; i < testCases; ++i) {
		
		if(readGrid()) cout << "yes" << endl;
		else cout << "no" << endl;

	}

    return 0;
}


bool readGrid() {

	char element;
	char grid[3][3];
	int p1 = 0;
	int p2 = 0;

	
	string line;
	getline(cin,line); // Reads '/n'
	
	for (int i = 0; i < 3; ++i) {
		
		getline(cin,line);
		stringstream ss(line);

		for (int j = 0; j < 3; ++j) {
			ss.get(element);
			grid[i][j] = element;
			if(element == 'X') p1++;
			else if(element == 'O') p2++;
		}
	}

	int p1Wins = getWins(grid,'X');
	int p2Wins = getWins(grid,'O');

	//cout << "p2: " << p2Wins << " " << p2 << endl;
	//cout << "p1: " << p1Wins << " " << p1 << endl;

	if (p1Wins + p2Wins > 1) return false;
	else if (p1Wins == 1 && p2 + 1 != p1) return false;
	else if (p1Wins == 1 && p2 + 1 == p1) return true;
	else if (p2Wins == 1 && p2 == p1) return true;
	else if (p2Wins == 1 && p2 != p1) return false;
	else if (p2 == p1 || p1 == p2 + 1) return true;
	else return false;

}

int getWins(char grid[3][3], char player) {

	int wins = 0;




	for (int i = 0; i < 3; ++i) {
		if (grid[i][0] == player) {
			if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2]) wins++;
		}
	}
	for (int i = 0; i < 3; ++i) {
		if (grid[0][i] == player) {
			if (grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i]) wins++;
		}
	}
	if (grid[1][1] == player) {
		if (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) wins++;
		else if (grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0]) wins++;
	}
	if (wins > 0) return 1;
	else return 0;
}
