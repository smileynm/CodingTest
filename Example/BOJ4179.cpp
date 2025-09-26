#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;

#define X   first
#define Y   second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<pair<int, int>> jihoon;
    queue<pair<int, int>> fire;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool alive = false;
    int count = 0;

    int R, C;
    cin >> R >> C;

    char* board = new char[R * C];
    int* dist = new int[R * C];
    int* burned = new int[R * C];

    fill(dist, dist + R * C, 0);
    fill(burned, burned + R * C, 1000000);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i * C + j];
            // 불이 입력되면 해당 자리를 1
            if (board[i * C + j] == 'F') {
                burned[i * C + j] = 1;
                fire.push({i, j});
            }
            // 지훈이가 입력되면 해당 자리를 1
            if (board[i * C + j] == 'J') {
                dist[i * C + j] = 1;
                jihoon.push({i, j});
            }
        }
    }

    while(!fire.empty()) {
        pair<int, int> cur = fire.front();
        fire.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                continue;
            }
            if (board[nx * C + ny] == '#' || burned[nx * C + ny] != 1000000) {
                continue;
            }
            burned[nx * C + ny] = burned[cur.X * C + cur.Y] + 1;
            fire.push({nx, ny});
        }
    }
    // // 디버깅용 cout
    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         cout << burned[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    while (!jihoon.empty() && !alive) {
        pair<int, int> cur = jihoon.front();
        jihoon.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                alive = true;
                count = dist[cur.X * C + cur.Y];
                break;
            }
            if (board[nx * C + ny] == '#' || dist[nx * C + ny] > 0) {
                continue;
            }
            if (burned[nx * C + ny] <= dist[cur.X * C + cur.Y] + 1) {
                continue;
            }
            if (alive) {
                break;
            }
            dist[nx * C + ny] = dist[cur.X * C + cur.Y] + 1;
            jihoon.push({nx, ny});
        }
    }
    
    // // 디버깅용 cout
    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    delete[] board;
    delete[] dist;
    delete[] burned;
    

    if (alive) {
        cout << count;
    } else {
        cout << "IMPOSSIBLE";
    }


    return 0;
}