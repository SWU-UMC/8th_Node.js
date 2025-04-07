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

int partition(int left, int right) {

	//set last element of the array as pivot
	int pivot = L[right];
	int i = left - 1;

	// incrementing j by one when it's greater than pivot
	for (int j = left; j <= right - 1; j++) {
		// if L[j] is smaller than pivot, increment i by one and swap with j
		// So, number smaller than the pivot stays on the left side of the array
		if (L[j] < pivot) {
			i++;
			int temp = L[i];
			L[i] = L[j];
			L[j] = temp;
		}
	}
	i++;
	int temp = L[i];
	L[i] = L[right];
	L[right] = temp;

	// i value is the index number of the pivot
	return i;
}

void quick_sort(int left, int right)
{
	//base case
	if (right <= left)
		return;

	int pivot = partition(left, right);
	quick_sort(left, pivot - 1);
	quick_sort(pivot + 1, right);

}

int main() 
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	quick_sort(0, SIZE - 1);

	cout << "\n\nSorted Data : ";
	print_data();

}
