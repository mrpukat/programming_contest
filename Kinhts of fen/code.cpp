#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int boardSize = 5;
const int exampelBoard[5][5] = {{1,1,1,1,1}, {0,1,1,1,1}, {0,0,-1,1,1}, {0,0,0,0,1}, {0,0,0,0,0}};
int board[5][5];

int tryNext(int step,int x,int y, int lX, int lY);
bool tryDone();
bool inBounds(int x,int y);

int main() {

	string line;
	getline(cin,line);
	int test = stoi(line);
	for (int i = 0; i < test; ++i) {
		int x,y;
		
		for(int i = 0; i < boardSize; ++i) {
			getline(cin,line);
			for (int j = 0; j < boardSize; ++j) { 
				char curr = line[j];
				if (curr == '1') board[i][j] = 1;
				else if (curr == '0') board[i][j] = 0;
				else {
					board[i][j] = -1;
					x = i;
					y = j;
				}
			}
		}

		int steps = tryNext(0,x,y,-1,-1);
		if (steps > 10) cout << "Unsolvable in less than 11 move(s)." << endl;
		else cout << "Solvable in " << steps <<" move(s)." << endl;
	}

    return 0;
}

int tryNext(int steps,int x,int y,int lX,int lY) {

	if (steps > 10) return steps;
	if (tryDone()) return steps;
	
	int fastes = 11;
	int temp;

	for(int i = -2; i <= 2; ++i) {
		for(int j = -2; j <= 2; ++j) {
			if(!(j == 0 || i == 0 || i == j || -1*i == j) && inBounds(x+i,y+j) && !(x+i == lX && y+j == lY)) {
				
				board[x][y] = board[x+i][y+j];
				board[x+i][y+j] = -1;
				temp = tryNext(steps + 1,x+i,y+j,x,y);
				board[x+i][y+j] = board[x][y];
				board[x][y] = -1;

				if (temp < fastes) fastes = temp;
			}
		}
	}

	return fastes;
}


bool inBounds(int x,int y) {
	if (x < 0) return false;
	if (y < 0) return false;
	if (x >= boardSize) return false;
	if (y >= boardSize) return false;
	return true;
}

bool tryDone() {

	for(int i = 0; i < boardSize; ++i) {
		for (int j = 0; j < boardSize; ++j) {
			if (board[i][j] != exampelBoard[i][j]) return false;
		}
	}
	return true;
} 