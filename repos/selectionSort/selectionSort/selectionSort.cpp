#include <iostream>
using namespace std;

const int SIZE = 15;
int L[SIZE] = { 10, 4, 7, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };


void print_data()
{
	for (int i = 0; i < SIZE; i++)
		cout << " " << L[i] << " ";
	cout << endl;
}

void selection_sort()
{
	int min_index, temp= 0;

	for (int i = 0; i < SIZE; i++) {
		min_index = i;
		for (int j = i+1; j < SIZE; j++) {
			if (L[j] < L[min_index]) {
				min_index = j;
			}
		}
		temp = L[i];
		L[i] = L[min_index];
		L[min_index] = temp;
	}

}

void main()
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	selection_sort();

	cout << "\n\nSorted Data : ";
	print_data();

}
