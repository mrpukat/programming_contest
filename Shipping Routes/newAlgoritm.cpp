#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <map>
#include <limits>
using namespace std;

typedef pair<int, int> pi;

int main() {

	int cases;
	cin >> cases;

	cout << "SHIPPING ROUTES OUTPUT" << endl;

	for (int i = 1; i <= cases; ++i) {
		int warhusetsNum, pathNum, reqests;
		cin >> warhusetsNum >> pathNum >> reqests;
		map<string, int> index;
		int node[warhusetsNum];
		int path[warhusetsNum][warhusetsNum];
		for (int j = 0; j < warhusetsNum; ++j) {
			string word;
			cin >> word;
			index[word] = j;
			for (int k = 0; k < warhusetsNum; ++k) {
				path[j][k] = numeric_limits<int>::max();
			}
		}

		for (int j = 0; j < pathNum; ++j) {
			string one,two;
			cin >> one >> two;
			path[index[one]][index[two]] = 1;
			path[index[two]][index[one]] = 1;
		}

		cout << '\n' << "DATA SET  " << i << '\n' << endl;

		for (int j = 0; j < reqests; ++j) {

			for (int k = 0; k < warhusetsNum; ++k) {
				node[k] = numeric_limits<int>::max();
			}

			int vikt;
			cin >> vikt;
			string start, end;
			cin >> start >> end;
			node[index[start]] = 0;

			// -------------------------
			priority_queue<pi, vector<pi>, greater<pi> > pq;
			pq.push(make_pair(node[index[start]],index[start]));

			while(!pq.empty() && pq.top().second != index[end]) {

				int curent = pq.top().second;
				int dis = pq.top().first;
				pq.pop();

				for (int l = 0; l < warhusetsNum; ++l){
					if (path[curent][l] != numeric_limits<int>::max() && curent != l) {
						if (node[l] > path[curent][l] + dis) {
							node[l] = path[curent][l] + dis;
							pq.push(make_pair(node[l],l));
						}
					}
				}
			}
		//------------------------------

			if (node[index[end]] == numeric_limits<int>::max()) cout << "NO SHIPMENT POSSIBLE" << endl;
			else cout << "$" << node[index[end]]*vikt*100 << endl;

		}


	}

	cout << '\n' << "END OF OUTPUT" << endl;

    return 0;
}