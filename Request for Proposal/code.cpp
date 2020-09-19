#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

void solution(int req, int pro, int rpf) {
	unordered_set<string> requaurments;
	string line;
	getline(cin,line); // Removes \n
	for (int i = 0; i < req; ++i) {
		getline(cin,line);
		requaurments.insert(line);
	}

	string name;
	int points = -1;
	float price = 0.00f;

	for (int i = 0; i < pro; ++i) {
		string pro_name;
		getline(cin,pro_name);
		float d;
		int r, poi = 0;
		scanf("%f %d", &d, &r);
		getline(cin,line); // Removes \n
		for (int j = 0; j < r; ++j) {
			getline(cin,line);
			if (requaurments.find(line) != requaurments.end()) ++poi;
		}
		if ((poi > points) || ((poi == points) && d < price)) {
			name = pro_name;
			price = d;
			points = poi;
		}
	}

	if (rpf > 1) printf("\n");
	printf("RFP #%d\n%s\n",rpf,name.c_str());

}


int main() {

	int req, pro, rpf = 0;
	while(scanf("%d %d", &req, &pro), (req || pro)) {
		++rpf;
		solution(req,pro,rpf);
	}

    return 0;
}