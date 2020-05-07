#include <iostream>
#include <string>
#include <limits>
#include <queue>
using namespace std;

int solvNextMaze(int x, int y);

typedef pair<int,pair<int,int> > dist;

int main() {

	int testCases;
	cin >> testCases;

	for (int i = 0; i < testCases; ++i) {
		int x, y;
		cin >> x >> y;
		cout << solvNextMaze(x,y) << endl;
	}

    return 0;
}


int solvNextMaze(int sizeX, int sizeY) {

	int maze[sizeX][sizeY];
	int mazeDistace[sizeX][sizeY];

	for (int i = 0; i < sizeX; ++i) {
		for (int j = 0; j < sizeY; ++j) {
			int temp;
			cin >> temp;
			maze[i][j] = temp;
			mazeDistace[i][j] = numeric_limits<int>::max();
		}
	}

	mazeDistace[0][0] = maze[0][0];

	priority_queue<dist, vector<dist>, greater<dist> > priorityQueue;

	priorityQueue.push(make_pair(maze[0][0],make_pair(0,0)));

	while(!priorityQueue.empty() && !(priorityQueue.top().second.first == sizeX-1 && 
							  		  priorityQueue.top().second.second == sizeY-1)) {

		int distace = priorityQueue.top().first;
		int x = priorityQueue.top().second.first;
		int y = priorityQueue.top().second.second;
		priorityQueue.pop();

		if (x > 0) {
			if (mazeDistace[x-1][y] > mazeDistace[x][y] + maze[x-1][y]) {
				mazeDistace[x-1][y] = mazeDistace[x][y] + maze[x-1][y];
				priorityQueue.push(make_pair(mazeDistace[x-1][y],make_pair(x-1,y)));
			}
		}
		if (x+1 < sizeX) {
			if (mazeDistace[x+1][y] > mazeDistace[x][y] + maze[x+1][y]) {
				mazeDistace[x+1][y] = mazeDistace[x][y] + maze[x+1][y];
				priorityQueue.push(make_pair(mazeDistace[x+1][y],make_pair(x+1,y)));
			}
		}


		if (y > 0) {
			if (mazeDistace[x][y-1] > mazeDistace[x][y] + maze[x][y-1]) {
				mazeDistace[x][y-1] = mazeDistace[x][y] + maze[x][y-1];
				priorityQueue.push(make_pair(mazeDistace[x][y-1],make_pair(x,y-1)));
			}
		}
		if (y+1 < sizeY) {
			if (mazeDistace[x][y+1] > mazeDistace[x][y] + maze[x][y+1]) {
				mazeDistace[x][y+1] = mazeDistace[x][y] + maze[x][y+1];
				priorityQueue.push(make_pair(mazeDistace[x][y+1],make_pair(x,y+1)));
			}
		}

	}

	return mazeDistace[sizeX-1][sizeY-1];
}

