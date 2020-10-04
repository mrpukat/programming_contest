#include <bitset>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int PRIMESELING = 10000001;
bitset<10000010> bs;
vector<int> primes;

int gcd (int a, int b) { return b == 0 ? a : gcd(b, a % b);}

bool isPrime(int p) {
	if (p <= PRIMESELING) return bs[p];

	for (int i = 0; i < primes.size(); ++i) {
		if (p % primes[i] == 0) return false;
	}
	return true;
}

int getPower(int p) {

	if (p == -2147483648) return 31;

	bool isNegative = false;
	if (p < 0) {
		p *= -1;
		isNegative = true;
	}

	if (isPrime(p) or p == 1) return 1;

	int temp = p;
	vector<int> prime_powers;

	for (int i = 0; i < primes.size(); ++i) {
		bool common = p % primes[i] == 0;
		if (common) {
			int res = 0;
			while (temp % primes[i] == 0) {
				temp /= primes[i];
				res += 1;
			}
			prime_powers.push_back(res);
		}

	}

	if(isPrime(temp)) {
		return 1;
	}

	while (prime_powers.size() > 1) {
		prime_powers[0] = gcd(prime_powers[0],prime_powers[1]);
		prime_powers.erase(prime_powers.begin() + 1);
	}

	while(isNegative && prime_powers[0] % 2 == 0) prime_powers[0] /= 2;

	return prime_powers[0];
}




int main() {

	bs.set();
	bs[0] = bs[1] = 0;

	for (long long i = 2; i <= PRIMESELING; ++i) {

		if(bs[i]) {
			for (long long j = i*i; j <= PRIMESELING; j += i)
			{
				bs[j] = 0;
			}
			primes.push_back(i);
		}

	}
	int problem;
	while(cin >> problem && problem != 0) {
		cout << getPower(problem) << endl;
	}
    
    return 0;
}