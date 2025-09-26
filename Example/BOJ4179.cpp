#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

#define X   first
#define Y   second

char board[1000][1000];
int dist[1000][1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<pair<int, int>> jihoon;
    queue<pair<int, int>> fire;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    

    int R, C;
    cin >> R >> C;
    return 0;
}