#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void getAllId(vector<long>& v, int length);
int compareId(vector<long>& v1,vector<long>& v2);
void sorting(vector<long>& v);

int main() {
    
	int n;
	int m;

	string line;

	getline(cin,line,' ');
	n = stoi(line);
	getline(cin, line);
	m = stoi(line);

	do {

		vector<long> jill;
		vector<long> jack;
	
		getAllId(jill,n);
		getAllId(jack,m);

		cout << compareId(jill,jack) << endl;

		getline(cin,line,' ');
		n = stoi(line);
		getline(cin, line);
		m = stoi(line);

	} while (n != 0);

    return 0;
}


int compareId(vector<long>& v1,vector<long>& v2) {

	int n = 0;
	int i = 0;
	int conter = 0;

	while(i < v1.size() && n < v2.size()) {

		long a = v1.at(i);
		long b = v2.at(n);


		if (a == b) {
			
			conter++;
			n++;
			i++;
		}
		else if ( a > b) n++;
		else i++;


	}

	return conter;
}

void getAllId(vector<long>& v, int length) {

	string line;

	for (int i = 0; i < length; i++) {

		getline(cin,line);
		long temp = stol(line);
		v.push_back(temp);
	}

	sorting(v);

}



void sorting(vector<long>& v) {

	bool sorted = false;

	while (!sorted) {
		sorted = true;
		for (int i = 0; i < v.size()-1;i++) {

			long a = v.at(i);
			long b = v.at(i+1);

			if (a > b) {

				v[i] = b;
				v[i+1] = a;
				sorted = false;
			}
		}

	}

}
