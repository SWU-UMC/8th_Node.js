#include <iostream>
using namespace std;

const int SIZE = 15;
int L[SIZE] = { 10, 4, 7, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };

void print_data() {
    for (int i = 0; i < SIZE; i++) {
        cout << " " << L[i] << " ";
    }
    cout << endl;
}

void sort() {
    int flag = 0;
    int temp = 0;

    for (int i = 0; i < SIZE; i++) { //배열 수만큼 for문 실행
        flag = 0; //플래그를 넣어 정렬이 완성되면 실행종료되게하기
        for (int j = 1; j < SIZE; j++) { //인덱스j 원소를 그 바로 앞 원소를를 비교하여 더 큰 원소가 뒤로가게하는 코드  
            if (L[j - 1] > L[j]) {
                temp = L[j - 1];
                L[j - 1] = L[j];
                L[j] = temp;
                flag++;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

int main() {
    cout << "Input Data : ";
    print_data();

    sort();

    cout << "\n\nSorted Data : ";
    print_data();

    return 0;
}