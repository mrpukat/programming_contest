#include <iostream>
using namespace std;


int max(int array[], int size);
int lis(int array[], int var[], int size);
int lds(int array[], int var[], int size);
int trainsorting(int array[], int size);
int towDinMax(int arr1[], int arr2[],int size);

int main() {

	int tests;
	cin >> tests;

	for (int i = 0; i < tests; ++i) {
		int cars;
		cin >> cars;
		int inp[cars];
		for (int j = 0; j < cars; ++j) {
			cin >> inp[j];
		}

		cout << "-" << trainsorting(inp,cars) << endl;
	}

    return 0;
}



int trainsorting(int array[], int size) {

	int lst[size];
	int ilst[size];
	int dlst[size];

	for (int i = 0; i < size; ++i) {
		lst[i] = 1;
		ilst[i] = 1;
		dlst[i] = 1;
	}

	lis(array, ilst, size);
	lds(array, dlst, size);

	for (int i = 0; i < size; ++i) { 

		lst[i] = ilst[i] + dlst[i] - 1;
		cout << "_" << lst[i] << " " << ilst[i] << " " << dlst[i] << endl;
    }

    return max(lst,size);
}



int lis(int array[], int lst[], int size) {

	//int lst[size];
	lst[0] = 1;

	for (int i = 1; i < size; ++i) {
		lst[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (array[i] > array[j] && lst[i] < lst[j] + 1) {
				lst[i] = lst[j] + 1;
			}
		}
	}

	return max(lst, size);

}

int lds(int array[], int lst[], int size) {

	//int lst[size];
	lst[size-1] = 1;

	for (int i = size-2; i >= 0; --i) {
		lst[i] = 1;
		for (int j = size-1; j > i; --j) {
			if (array[i] > array[j] && lst[i] < lst[j] + 1) {
				lst[i] = lst[j] + 1;
			}
		}
	}

	return max(lst, size);
}


int towDinMax(int arr1[], int arr2[], int size) {
	
	int max = 0;

	for (int i = 0; i < size; ++i) {
		if (max < arr1[i] + arr2[i]) max = arr1[i] + arr2[i];
	}

	return max;

}

int max(int array[], int size) {

	int max = 0;

	for (int i = 0; i < size; ++i) {
		if (max < array[i]) max = array[i];
	}

	return max;
}
