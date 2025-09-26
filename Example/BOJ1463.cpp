#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x;
    int count = 0;
    cin >> x;

    while (x!=1) {
        if (x%3 == 0) {
            x /= 3;
        } else if (x%2 == 0) {
            x /= 2;
        } else {
            x -= 1;
        }
        count++;
    }

    cout << count-1;
    return 0;
}