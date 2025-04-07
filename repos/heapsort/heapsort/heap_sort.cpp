#include <iostream>
using namespace std;

#define SWAP(x, y, t) (t=x, x=y, y=t)

double L[15] = { 10, 4, 0, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };

void print_data(double L[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		cout << " " << L[i];
	cout << endl;
}

void Max_heap(double L[], int root, int n)
{
	int left_child, right_child, root_data;

	// 여기를 채워 완성하세요.
	left_child = 2 * root + 1;
	right_child = 2 * root + 2;
	int max = root;
	int temp;

	if (left_child < n && L[left_child] > L[max]) {
		max = left_child;
	}
	if (right_child < n && L[right_child] > L[max]) {
		max = right_child;
	}

	if (max != root) {
		SWAP(L[root], L[max], temp);
		Max_heap(L, max, n);
	}
}

void HeapSort(double L[], int n)
{
	int i, temp;

	// 최대 히프 구조 생성
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
		Max_heap(L, i, n);

	// 실제 정렬
	// 제일큰수(0번째 원소)를 마지막(n-1번째)으로 옮기고 heap 재구성
	for (i = n - 2; i >= 0; i--)
	{
		//두 원소 L[0],L[i+1] 교환
		SWAP(L[0], L[i + 1], temp);
		Max_heap(L, 0, i);
	}
}

int main()
{
	// 처음 상태를 보여줌
	cout << "Input Data : ";
	print_data(L, 15);

	/* sort the elements of array L[] in ascending order */
	HeapSort(L, 15);

	// 정렬된 결과를 보여줌
	cout << "\nSorted Data : ";
	print_data(L, 15);

}