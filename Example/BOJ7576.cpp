/***********************************************************************************/
// 토마토
// 
// <문제>
// 창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다.
// 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은
// 익은 토마토의 영향을 받아 익게 된다.
// 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다.
// 대각선 방향에 있는 토마토들에게는 영향을주지 못하며, 저절로 익는 경우는 없다고 가정한다.
// 철수는 창고에 보관된 토마토들이 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 알고 싶어 한다.
// 토마토를 창고에 보관하는 격자 모앙의 상자들의 크기와
// 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지,
// 그 최소 일수를 구하는 프로그램을 작성하라.
// 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.
//
// <입력>
// 첫 줄에는 상자의 크기를 나타내는 두 정수 M, N이 주어진다.
// M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단 2 <= M, N <= 1,000이다.
// 둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다.
// 즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다.
// 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다.
// 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.
//
// <출력>
// 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다.
// 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고,
// 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.
/***********************************************************************************/

#include <bits/stdc++.h>

#define X   first
#define Y   second

using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int board[1000][1000];
    int dist[1000][1000];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int result = 0;

    for (int i = 0; i < 1000; i++) {
        fill(board[i], board[i]+1000, 0);
        fill(dist[i], dist[i]+1000, -1);
    }
    
    queue<pair<int, int>> Q;

    int N, M;
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                Q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }
            if (dist[nx][ny]!=-1 || board[nx][ny] != 0) {
                continue;
            }
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dist[i][j] == -1 && board[i][j] != -1) {
                result = -1;
                break;
            }
            if (dist[i][j] >= result) {
                result = dist[i][j];
            }
        }
        if (result == -1) {
            break;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

    cout << result << '\n';

    return 0;
}