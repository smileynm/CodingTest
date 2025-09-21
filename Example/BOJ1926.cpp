#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define X   first
#define Y   second

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int board[500][500];
    int vis[500][500] = {0,};
    queue<pair<int, int>> Q;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int count = 0;
    int area = 0;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j]==1 && vis[i][j]==0) {
                vis[i][j] = 1;
                Q.push({i, j});
                count++;
                int cur_area = 0;
                while(!Q.empty()) {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    cur_area++;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                            continue;
                        }
                        if (vis[nx][ny] || board[nx][ny] != 1) {
                            continue;
                        }
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                        //cur_area++;
                    }
                }
                //cout << cur_area;
                if (cur_area >= area) {
                    area = cur_area;
                }
            }
        }
    }

    cout << count << '\n';
    cout << area << '\n';

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << vis[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    return 0;
}