#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

double msf();

int main() {

	int test;
	cin >> test;
	for (int i = 0; i < test; ++i) {
		printf("%4.2f\n", msf()); 
	}

    return 0;
}

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

double distance (ii a, ii b) {
	double x = a.first - b.first;
	double y = a.second - b.second;

	return sqrt(x*x + y*y);
}

double msf() {
	int s, n;
	cin >> s >> n;
	ii city[n];


	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		city[i] = ii(x,y);
	}

	vector< pair<double, ii> > EdgeList;

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {

			double w = distance(city[i],city[j]);
			EdgeList.push_back(make_pair(w, ii(i, j)));
		}
	}

	int edges = EdgeList.size();
	sort(EdgeList.begin(), EdgeList.end());

	double cost = 0.0;

	UnionFind UF(n);

	for (int i = 0; i < edges; ++i) {
		if (UF.amountOfSets() == s) break;
		pair<double, ii> front = EdgeList[i];
		int u = front.second.first;
		int v = front.second.second;
		if (!UF.isSameSet(u, v)) {
			cost = front.first;
			UF.unionSet(u, v);
		}
	}
	return cost;
}

