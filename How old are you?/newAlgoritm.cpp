#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct date
{
	int day;
	int month;
	int year;
};

void getDate(date& Date);

int main() {

	string temp;
	int tests;
	getline(cin,temp);
	tests = stoi(temp);

	for (int n = 1; n <= tests; ++n) {

		cout << "Case #" << n << ": ";

		date cDate, bDate;
		getDate(cDate);
		getDate(bDate);
		bool isBDay = false;
		bool isInvalid = false;
		int afterBDay = 0;

		if (bDate.year > cDate.year) isInvalid = true;
		else if (bDate.year == cDate.year) {
			if (bDate.month > cDate.month) isInvalid = true;
			else if (bDate.month == cDate.month) {
				if (bDate.day > cDate.day) isInvalid = true;
				else if (bDate.day == cDate.day) isBDay = true;
			}
		}

		if (bDate.month > cDate.month) afterBDay = -1;
		else if (bDate.month == cDate.month && bDate.day > cDate.day) afterBDay = -1;

		if (!isInvalid) {
			if (!isBDay) {
				int age = afterBDay + (cDate.year - bDate.year);
				if (age > 130) cout << "Check birth date" << endl;
				else cout << age << endl;
			} else cout << 0 << endl;
		} else cout << "Invalid birth date" << endl;
		


	}

    return 0;
}

void getDate(date& Date) {
	string temp;
	
	getline(cin,temp,'/');
	Date.day = stoi(temp);
	
	getline(cin,temp,'/');
	Date.month = stoi(temp);
	
	getline(cin,temp);
	Date.year = stoi(temp);
}
