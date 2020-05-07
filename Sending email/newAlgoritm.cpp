#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <limits>
using namespace std;

typedef pair<int, int> pi;

int main() {

	int cases;
	cin >> cases;

	for (int i = 1; i <= cases; ++i) {

		int n;
		cin >> n;
		int path[n][n];
		int node[n];

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				path[i][j] = numeric_limits<int>::max();
			}
			node[i] = numeric_limits<int>::max();
		}

		int m;
		cin >> m;

		int s;
		cin >> s;
		node[s] = 0;
		int t;
		cin >> t;

		for (int k = 0; k < m; ++k) {
			int nodeOne;
			int nodeTwo;
			int distance;
			cin >> nodeOne;
			cin >> nodeTwo;
			cin >> distance;

			if (path[nodeOne][nodeTwo] > distance) {
				path[nodeOne][nodeTwo] = distance;
				path[nodeTwo][nodeOne] = distance;
			}
		}

		priority_queue<pi, vector<pi>, greater<pi> > pq;
		pq.push(make_pair(node[s],s));

		while(!pq.empty() && pq.top().second != t) {

			int curent = pq.top().second;
			int dis = pq.top().first;
			pq.pop();

			for (int l = 0; l < n; ++l){
				if (path[curent][l] != numeric_limits<int>::max()) {
					if (node[l] > path[curent][l] + dis) {
						node[l] = path[curent][l] + dis;
						pq.push(make_pair(path[curent][l] + dis,l));
					}
				}
			}
		}

		cout << "Case #" << i << ": ";

		if (node[t] == numeric_limits<int>::max()) cout << "unreachable" << endl;
		else cout << node[t] << endl;

	}



    return 0;
}