#include <iostream>
using namespace std;

void Union(int a, int b, int arr[],int weight[]);
int find(int curr,int arr[]);
void move(int a, int b, int arr[]);
void value(int a,int arr[], int weight[], int sets);

int main() {

	int sets, operation;

	while (cin >> sets >> operation) {

		int array[sets+1];
		int weight[sets+1];
		for (int i = 0; i <= sets; ++i) {
			array[i] = -1;
			weight[i] = 1;
		}


		for (int i = 0; i < operation; ++i) {
			int op, first, second;

			for (int i = 1; i <= sets; ++i) {
				cout << array[i] << " ";
			}
			cout << endl;

			cin >> op >> first;

			switch(op) {
  				case 1:
  					cin >> second;
  					Union(first,second,array,weight);
    				break;
  				case 2:
  					cin >> second;
  					move(first,second,array);
					break;
  				case 3:
  					value(first,array,weight,sets);
	  				break;
			}


		}


	}
	
    return 0;
}

void value(int a,int arr[], int weight[], int sets) {
	int root = find(a,arr);
	cout << weight[root] << " ";
	int count = 0;
	for (int i = 1; i <= sets; ++i) {
		if (find(arr[i],arr) == root) count++;
	}
	cout << count << endl;
}

void move(int a, int b, int arr[]) {
	int root1 = find(b,arr);
	if (root1 != a)	arr[a] = root1;
}

void Union(int a, int b, int arr[],int weight[]) {

	int root1 = find(a,arr);
	int root2 = find(b,arr);

	if (root2 != root1) {
		if (weight[root2] > weight[root1]) {
			arr[root1] = root2;
			weight[root2] += weight[root1];
		} else {
			arr[root2] = root1;
			weight[root1] += weight[root2];
		}
	}
}

int find(int curr,int arr[]) {

	if (arr[curr] == -1) return curr;
	arr[curr] = find(arr[curr],arr);
	return arr[curr];
}