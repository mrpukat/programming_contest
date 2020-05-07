#include <iostream>
#include <sstream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

int main() {

	string line;
	while(getline(cin,line)) {
		stringstream ss(line);

		long double len, with, high, deg;		
		ss >> len >> with >> high >> deg;

		long double nineDeg, zeroDeg;
		nineDeg = sin((90-deg)*M_PI/180);
		zeroDeg = sin(deg*M_PI/180);

		long double h = len*(zeroDeg/nineDeg);

		long double aria = high*len;
		if(deg > 0) {
			aria -= h*len/2;

			if (h > high) {

				long double smalH = h - high;
				long double smalL = (len/h)*smalH;
				aria += smalH*smalL/2;
			}
		}

		aria *= with;

		printf("%4.3Lf mL\n", aria);

	}



	
    return 0;
}