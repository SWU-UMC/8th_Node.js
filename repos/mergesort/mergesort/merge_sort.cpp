#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 15;
int L[SIZE] = { 10, 4, 7, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };


void print_data()
{
	for (int i = 0; i < SIZE; i++)
		cout << " " << L[i] << " ";
	cout << endl;
}

void merge(int left, int right, int middle)
{

	int left_size = middle - left + 1;
	int right_size = right - middle;

	//배열 두개 생성
	vector<int> LTemp(left_size);
	vector<int> RTemp(right_size);

	for (int i = 0; i < left_size; i++)
		LTemp[i] = L[left + i];
	for (int j = 0; j < right_size; j++)
		RTemp[j] = L[middle + 1 + j];

	int i = 0; //왼쪽 배열 가르키는 인덱스
	int j = 0; // 오른쪽 배열 가르키는 인덱스
	int k = left; // 합병될 배열을 가르키는 인덱스

	//두 배열 순서대로 합치기
	while (i < left_size && j < right_size) {
		if (LTemp[i] <= RTemp[j]) {
			L[k] = LTemp[i];
			i++;
		}
		else {
			L[k] = RTemp[j];
			j++;
		}
		k++;
	}
	//나머지 배열 정리
	while (i < left_size) {
		L[k] = LTemp[i];
		i++;
		k++;
	}
	while (j < right_size) {
		L[k] = RTemp[j];
		j++;
		k++;
	}
}

void merge_sort(int left, int right)
{
	if (left < right) {
		int middle = (right + left) / 2;

		merge_sort(left, middle);
		merge_sort(middle + 1, right);

		merge(left, right, middle);

	}
}

int main()
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	merge_sort(0, SIZE - 1);

	cout << "\n\nSorted Data : ";
	print_data();

	return 0;
}
