#include <iostream>
#include <vector>
using namespace std;

int main() {

	int studentsSize;

	while (cin >> studentsSize) {
		int swaps = 0;
		int studentList[studentsSize];

		for (int i = 0; i < studentsSize; ++i) {
			cin >> studentList[i];

			for (int j = i; j > 0; --j) {
				if (studentList[j] < studentList[j-1]) {
					++swaps;
					int temp = studentList[j];
					studentList[j] = studentList[j-1];
					studentList[j-1] = temp;
				}
				else break;
			}
		}

		cout << swaps << endl;

	}
    return 0;
}