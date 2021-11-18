#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

class UnionFind {
private: vector<int> p, rank; int nodes;
public:
	UnionFind(int N) {
		nodes = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; ++i) p[i] = i;
	}
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) p[y] = x;
			else { 
				p[x] = y;
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}
	int amountOfSets() {
		int amount = 0;
		for (int i = 0; i < nodes; ++i) {
			if (p[i] == i) amount++;
		}
		return amount;
	}
};

int findmst(int nodes,int paths) {

	vector< pair<int, ii> > EdgeList;

	for (int i = 0; i < paths; ++i) {
		int c1, c2, w;
		cin >> c1 >> c2 >> w;
		EdgeList.push_back(make_pair(w, ii(c1, c2)));
	}

	int edges = EdgeList.size();
	sort(EdgeList.begin(), EdgeList.end());

	int cost = 0;

	UnionFind UF(nodes);

	for (int i = 0; i < edges; ++i) {
		pair<int, ii> front = EdgeList[i];
		int u = front.second.first;
		int v = front.second.second;
		if (!UF.isSameSet(u, v)) {
			cost = front.first;
			UF.unionSet(u, v);
		}
	}

	if (UF.amountOfSets() == 1) return cost;
	else return -1;
}



int main() {

	int nodes, paths;
	while (cin >> nodes >> paths && !(nodes == 0 && paths == 0)) {
		int res = findmst(nodes, paths);
		if (res == -1) cout << "IMPOSSIBLE" << endl;
		else cout << res << endl;
	}

    return 0;
}
