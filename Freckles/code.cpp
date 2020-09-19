#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

typedef pair<double,double> pos;
typedef pair<double,int> di;

double distance(double X, double Y, double x, double y) {
	double rx = X - x;
	double ry = Y - y;

	return sqrt(rx*rx + ry*ry);
}

double mst(int nodes) {

	bool taken[nodes];
	pos node[nodes];
	priority_queue<di> pq;

	// INIT list
	for (int i = 0; i < nodes; ++i) {
		double x, y;
		cin >> x >> y;
		taken[i] = false;
		node[i] =  pos(x,y);
	}

	// INIT PQ
	taken[0] = true;
	for (int i = 1; i < nodes; ++i) {
		double dis = distance(node[0].first, node[0].second ,node[i].first, node[i].second);
		pq.push(di(-dis,i));
	}

	double cost = 0;

	while(!pq.empty()) {
		pos front = pq.top();
		pq.pop();
		double weight = -front.first;
		int index = front.second;
		if (!taken[index]) {
			cost += weight;
			taken[index] = true;
			for (int i = 0; i < nodes; ++i) {

				if (!taken[i]) {
					double dis = distance(node[index].first, node[index].second ,node[i].first, node[i].second);
					pq.push(di(-dis,i));
				}

			}
		}
	}

	return cost;
}

int main() {

	int test;
	cin >> test;

	for (int i = 0; i < test; ++i) {
		int nodes;
		cin >> nodes;
		if (i != 0) printf("\n");
		printf("%4.2f\n", mst(nodes));
	}

    return 0;
}