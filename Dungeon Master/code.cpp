#include <iostream>
#include <string>
#include <limits>
#include <queue>
using namespace std;

int solvNextMaze(int x, int y, int z);

typedef pair<int, pair<int, int> > cords;

typedef pair<int, cords > dist;

int main() {

	int x, y, z;

	while (cin >> z >> y >> x && !(z == 0 && y == 0 && x == 0)) {
		int res = solvNextMaze(x, y, z);
		if (res == -1) cout << "Trapped!" << endl;
		else {
			cout << "Escaped in " << res << " minute(s)." << endl;
		}
	}

    return 0;
}


int solvNextMaze(int x, int y, int z) {

	char maze[x][y][z];
	int visided[x][y][z];

	cords start;
	cords goal;

	for (int i = 0; i < z; ++i) {
		for (int j = 0; j < y; ++j) {
			for (int k = 0; k < x; ++k) {
				cin >> maze[k][j][i];
				if (maze[k][j][i] == 'S') start = make_pair(k, make_pair(j, i));
				if (maze[k][j][i] == 'E') goal = make_pair(k, make_pair(j, i));
				visided[k][j][i] = false;
			}
		}
	}

	queue<dist> fronter;

	fronter.push(make_pair(0, start));
	visided[start.first][start.second.first][start.second.second] = true;

	while (!fronter.empty()) {

		dist front = fronter.front();
		int cost = front.first;
		cords pos = front.second;
		fronter.pop();

		int rx = pos.first;
		int ry = pos.second.first;
		int rz = pos.second.second;

		if (maze[rx][ry][rz] == 'E') {
			return cost;
		}

		///// X +- 1 /////////

		if (rx > 0 && !visided[rx - 1][ry][rz] && maze[rx - 1][ry][rz] != '#') {
			visided[rx - 1][ry][rz] = true;
			fronter.push(dist(cost + 1, cords(rx - 1, make_pair(ry, rz) ) ) );
		}

		if (rx < x-1 && !visided[rx + 1][ry][rz] && maze[rx + 1][ry][rz] != '#') {
			visided[rx + 1][ry][rz] = true;
			fronter.push(dist(cost + 1, cords(rx + 1, make_pair(ry, rz) ) ) );
		}

		///// Y +- 1 /////////

		if (ry > 0 && !visided[rx][ry - 1][rz] && maze[rx][ry - 1][rz] != '#') {
			visided[rx][ry - 1][rz] = true;
			fronter.push(dist(cost + 1, cords(rx, make_pair(ry - 1, rz) ) ) );
		}

		if (ry < y-1 && !visided[rx][ry + 1][rz] && maze[rx][ry + 1][rz] != '#') {
			visided[rx][ry + 1][rz] = true;
			fronter.push(dist(cost + 1, cords(rx, make_pair(ry + 1, rz) ) ) );
		}

		///// Z +- 1 /////////

		if (rz > 0 && !visided[rx][ry][rz - 1] && maze[rx][ry][rz - 1] != '#') {
			visided[rx][ry][rz - 1] = true;
			fronter.push(dist(cost + 1, cords(rx, make_pair(ry, rz - 1) ) ) );
		}

		if (rz < z-1 && !visided[rx][ry][rz + 1] && maze[rx][ry][rz + 1] != '#') {
			visided[rx][ry][rz + 1] = true;
			fronter.push(dist(cost + 1, cords(rx, make_pair(ry, rz + 1) ) ) );
		}

	}

	return -1;

}