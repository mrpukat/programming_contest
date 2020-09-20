#include <iostream>
using namespace std;

// first arr[l:m] second arr[m+1:r]
unsigned long long mergeSort(int arr[], int l, int m, int r) {
	unsigned long long swaps = 0;
	int n1 = m - l + 1;
	int n2 = r - m;
	int larr[n1], rarr[n2];

	for (int i = 0; i < n1; ++i) { 
		larr[i] = arr[l + i]; 
	}

	for (int i = 0; i < n2; ++i) { 
		rarr[i] = arr[m + 1 + i]; 
	}

	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (larr[i] <= rarr[j]) {
			arr[k] = larr[i];
			i++;
		}
		else {
			arr[k] = rarr[j];
			j++;
			swaps += n1 - i;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = larr[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = rarr[j];
		j++;
		k++;
	}

	return swaps;
}

unsigned long long merge(int arr[], int l, int r) {
	unsigned long long swaps = 0;
	
	if (l < r) {
		int m = l + (r - l) /2;

		swaps += merge(arr, l, m);
		swaps += merge(arr, m + 1, r);

		swaps += mergeSort(arr, l, m, r);
	}
	return swaps;
}

unsigned long long countSwaps(int size) {

	int arr[size];

	for (int i = 0; i < size; ++i) { 
		cin >> arr[i]; 
	}
	
	return merge(arr, 0, size - 1);
}


int main() {

	int size;
	while (cin >> size && size != 0) {
		cout << countSwaps(size) << endl;
	}
    return 0;
}
