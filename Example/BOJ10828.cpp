/*****************************************************************/
// 스택
// 
// <문제>
// 정수를 저장하는 스택을 구현한 다음,
// 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
// 명령은 총 다섯 가지이다.
// - push X: 정수 X를 스택에 넣는 연산이다.
// - pop: 스택에서 가장 위에 있는 정수를 빼고,
//      만약 스택에 들어있는 정수가 없을 경우에는 -1을 출력한다.
// - size: 스택에 들어있는 정수의 개수를 출력한다.
// - empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
// - top: 스택의 가장 위에 있는 정수를 출력한다.
//      만약 스택에 들어있는 정수가 없을 경우에는 -1을 출력한다.
//
// <입력>
// 첫째 줄에 주어지는 명령의 수 N (1 <= N <= 10,000)이 주어진다.
// 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다.
// 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다.
// 문제에 나와있지 않은 명령이 주어지는 경우는 없다.
//
// <출력>
// 출력해야하는 명령이 주어질 때 마다, 한 줄에 하나씩 출력한다.
/*****************************************************************/

#include <iostream>
using namespace std;

class Stack {
private:
    int arr[10000];
    int pos = 0;
public:
    void push(int X);
    int pop();
    int size();
    int empty();
    int top();
};

void Stack::push(int X) {
    arr[pos++] = X;
}

int Stack::pop() {
    if (pos > 0) {
        return arr[--pos];
    }
    return -1;
}

int Stack::size() {
    return pos;
}

int Stack::empty() {
    if (pos <= 0){
        return 1;
    }
    return 0;
}

int Stack::top() {
    if (pos > 0) {
        return arr[pos-1];
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::string order;
    Stack s;

    cin >> N;

    for (int i=0; i<N; i++) {
        cin >> order;
        //cout << order;
        if (order == "push") {
            int X;
            cin >> X;
            s.push(X);
        }
        else if (order == "pop") {
            cout << s.pop() << '\n';
        }
        else if (order == "size") {
            cout << s.size() << '\n';
        }
        else if (order == "empty") {
            cout << s.empty() << '\n';
        }
        else if (order == "top") {
            cout << s.top() << '\n';
        }
        else {
            cout << "error" << '\n';
        }
    }
    return 0;
}