/***************************************/
// N이하의 수 중에서 가장 큰 2의 거듭제곱수를 반환하는
// 함수 func4 (int N)을 작성하라.
// N은 10억 이하의 자연수이다.
/***************************************/

#include <iostream>
#include <cmath>
using namespace std;

int func4(int N) {
    int val = 1;
    while (2 * val <= N) {
        val *= 2;
    }
    return val;
}

int main() {
    int N;
    cin >> N;
    cout << func4(N) << endl;

    return 0;
}