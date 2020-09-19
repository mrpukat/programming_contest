#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> cords;


void solution(double d, int n) {

	vector<cords> beehives;
	bool res[n];

	for (int i = 0; i < n; ++i) {
		double x, y;
		cin >> x >> y;
		beehives.push_back(make_pair(x,y));
		res[i] = false;
	}


	for (int i = 0; i < beehives.size(); ++i) {


		for (int j = i+1; j < beehives.size(); ++j) {
			double x = beehives[i].first - beehives[j].first;
			double y = beehives[i].second - beehives[j].second;
			bool soure;
			if (d*d > x*x + y*y) soure = true;
			else soure = false;

			if(!res[i]) res[i] = soure;
			if(!res[j]) res[j] = soure;
		}
	}

	int so = 0, sw = 0;

	for (int i = 0; i < n; ++i) {
		if (res[i]) so++;
		else sw++;
	}

	cout << so << " sour, " << sw << " sweet" << endl;

}


int main() {

	double d;
	int n;
	
	
	while(cin >> d && cin >> n && n != 0 && d != 0.0f) {
		solution(d,n);
	}

    return 0;
}
