/*****************************************************************/
// 큐
// 
// <문제>
// 정수를 저장하는 큐를 구현한 다음,
// 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
// 명령은 총 여섯 가지이다.
// - push X: 정수 X를 큐에 넣는 연산이다.
// - pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다.
//      만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// - size: 큐에 들어있는 정수의 개수를 출력한다.
// - empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
// - front: 큐의 가장 앞에 있는 정수를 출력한다.
//      만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// - back: 큐의 가장 뒤에 있는 정수를 출력한다.
//      만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//
// <입력>
// 첫째 줄에 주어지는 명령의 수 N (1 <= N <= 10,000)이 주어진다.
// 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다.
// 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다.
// 문제에 나와있지 않은 명령이 주어지는 경우는 없다.
//
// <출력>
// 출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.
/*****************************************************************/

#include <iostream>
using namespace std;

class Queue {
private:
    int arr[10001];
    int head = 0;
    int rear = 0;
public:
    void push(int X);
    int pop();
    int size();
    int empty();
    int front();
    int back();
};

void Queue::push(int X) {
    if (rear >= 10000) {
        rear = 0;
        arr[rear] = X;
    } else {
        arr[rear++] = X;
    }
}

int Queue::pop() {
    if (rear != head) {
        return arr[head++];
    } else {
        return -1;
    }
}

int Queue::size() {
    return rear - head;
}

int Queue::empty() {
    if (rear!=head) {
        return 0;
    } else {
        return 1;
    }
}

int Queue::front() {
    if (rear != head) {
        return arr[head];
    } else {
        return -1;
    }
}

int Queue::back() {
    if (rear != head) {
        if (rear < head) {
            if (rear == 0) {
                return arr[10000];
            } else {
                return arr[rear-1];
            }
        }
        return arr[rear-1];
    } else {
        return -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Queue q;
    int N;
    std::string order;

    cin >> N;

    for (int i=0; i<N; i++) {
        cin >> order;
        if (order == "push") {
            int X;
            cin >> X;
            q.push(X);
        } else if (order == "pop") {
            cout << q.pop() << '\n';
        } else if (order == "size") {
            cout << q.size() << '\n';
        } else if (order == "empty") {
            cout << q.empty() << '\n';
        } else if (order == "front") {
            cout << q.front() << '\n';
        } else if (order == "back") {
            cout << q.back() << '\n';
        } else {
            cout << "error" << '\n';
        }
    }
    return 0;
}