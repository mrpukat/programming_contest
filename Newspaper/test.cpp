#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

double solution();
void getMap(map<char, double>& map);

int main() {

	//string line;
	int n;

	cin >> n;

	//getline(cin,line);
	//int n = stoi(line);
	for (int test = 0; test < n; ++test) {

		//cout << test << endl;			
		double res = solution();
		printf("%4.2f$\n", res);
		//cout << res  << "$" << endl;
	}


    return 0;
}


double solution() {

	map<char, double> map;
	double res = 0;
	string line;

	getMap(map);

	int m;
	cin >> m;

	//getline(cin, line);
	//int m = stoi(line);

	
	for(int l = 0; l <= m; l++) {
		
		getline(cin,line, '\n');
		//cout << line << endl;
		//cin >> line;
		for (int k = 0; k < line.size(); ++k) {
			if (map.end() != map.find(line[k])) res += map[line[k]];
		}
		//cout << res << endl;

	}


	return res/100;

}

void getMap(map<char, double>& map) {

	int k;
	cin >> k;

	for (int i = 0; i < k; ++i) {
		char t;
		cin >> t;
		int w;
		cin >> w;

		map[t] = w;
	}
}
