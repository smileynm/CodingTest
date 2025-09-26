#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define X   first
#define Y   second

int main() {
    int board[102][102] = {0,};
    int dist[102][102] = {0,};
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pair<int, int>> Q;

    int N, M;
    char digit[102] = {0,};

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> digit;
        for (int j=0; j<M; j++) {
            board[i][j] = digit[j] - '0';
        }
    }

    dist[0][0] = 1;
    Q.push({0, 0});
    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir=0; dir<4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }
            if (dist[nx][ny]!=0 || board[nx][ny]!=1) {
                continue;
            }
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    cout << dist[N-1][M-1];

    return 0;
}