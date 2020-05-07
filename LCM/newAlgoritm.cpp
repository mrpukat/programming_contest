#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <math.h>
#include <map>
using namespace std;

int tow[] = {6,2,4,8};
int tre[] = {1,3,9,7};
int foe[] = {6,4};
int seven[] = {1,7,9,3};
int eat[] = {6,8,4,2};
int nine[] = {1,9};

int getLasDigitOfPow(int i, int p);

int main() {

	int PRIMESELING = 1000001;

	bool prime[PRIMESELING];
	memset(prime, true, sizeof(prime));


	for (int i = 2; i*i <= PRIMESELING; ++i) {

		if(prime[i]) {
			for (int j = i*i; j <= PRIMESELING; j += i)
			{
				prime[j] = false;
			}
		}

	}

	int n;
	cin >> n;

	while(n != 0) {

		unsigned long long res = 1;
		map<int, long> primeMap;

		for (int k = 2; k <= n; ++k) {

			if(prime[k] && k != 5) {

				long add = floor(log(n)/log(k));

				if (k == 2) {
					add -= floor(log(n)/log(5));
				}

				res *= getLasDigitOfPow(k,add);
				res = res % 10;
			}
		}

		cout << res << endl;

		cin >> n;
	}
	

    return 0;
}


int getLasDigitOfPow(int i, int p) {

	if (p == 0) return 1;
	else if (i % 10 == 1) return 1;
	else if (i % 10 == 5) return 5;
	else if (i % 10 == 6) return 6;

	else if (i % 10 == 2) return tow[p % 4];
	else if (i % 10 == 3) return tre[p % 4];
	else if (i % 10 == 4) return foe[p % 2];
	else if (i % 10 == 7) return seven[p % 4];
	else if (i % 10 == 8) return eat[p % 4];
	else if (i % 10 == 9) return nine[p % 2];
	else return 1;

}

