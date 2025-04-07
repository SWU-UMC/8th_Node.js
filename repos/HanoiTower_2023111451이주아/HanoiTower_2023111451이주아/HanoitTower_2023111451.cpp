#include <iostream>
using namespace std;

int cnt = 0; // 이동 횟수 카운트 변수

void Hanoi(int n, char from, char temp, char to) {
    if (n == 1) {
        cnt++;
        cout << "#" << cnt << " Move a disk from " << from << " to " << to << endl;
    }
    else {
        Hanoi(n - 1, from, to, temp);
        cnt++;
        cout << "#" << cnt << " Move a disk from " << from << " to " << to << endl;
        Hanoi(n - 1, temp, from, to);
    }
}

int main() {
    int n; // 원반의 수

    cout << "원반의 갯수를 입력하세요: ";
    cin >> n;

    Hanoi(n, 'A', 'B', 'C');

    cout << "전체 원반 이동 수(원반수: " << n << ") = " << cnt << endl;

    return 0;
}