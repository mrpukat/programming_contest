#include <iostream>
using namespace std;

void getList(int size, int list[]);
void quicksort(int array[], int start, int end);
int partition(int array[], int left, int right, int pivot);
void copyArray(int a[], int b[], int size);
void swap(int array[], int a, int b);
int find(int array[], int size, int value, int pos);

int main() {

	int studentsSize;

	while (cin >> studentsSize) {

		int studentsList[studentsSize];
		int sortedList[studentsSize];

		getList(studentsSize, studentsList);
		copyArray(studentsList, sortedList, studentsSize);
		quicksort(sortedList, 0, studentsSize-1);

		int cost = 0;
		for (int i = 0; i < studentsSize; ++i) {
			int valuePos = find(sortedList, studentsSize, studentsList[i], studentsSize/2);
			if(valuePos < i) cost += (i - valuePos);
			else cost += (valuePos - i);
		}

		cout << cost/2 << endl;

	}
    return 0;
}

int find(int array[], int size, int value, int pos) {

	if (array[pos] == value) return pos;
	if (array[pos] > value) return find(array, size, value, pos/2);
	else return find(array, size, value, pos + (size - pos)/2);
}

void getList(int size, int list[]) {
	for (int i = 0; i < size; ++i) {
		cin >> list[i];
	}
}

void quicksort(int array[], int start, int end) {

	int middel = (start+end)/2;
	swap(array, middel, end);

	int k = partition(array, start, end-1, array[end]);

	swap(array, k, end);
	if ((k - start) > 1) quicksort(array, start, k-1);
    if ((end - k) > 1) quicksort(array, k+1, end);
}

void swap(int array[], int a, int b) {
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

int partition(int array[], int left, int right, int pivot) {

	while (left <= right) {

    	while (array[left] < pivot) left++;

    	while ((right >= left)  && (array[right] >= pivot)) right--;

    	if (right > left) swap(array, left, right);
   	}
	return left;
}

void copyArray(int a[], int b[], int size) {
	for (int i = 0; i < size; ++i) {
		b[i] = a[i];
	}
}