/***********************************************************************************/
// 숨바꼭질
// 
// <문제>
// 수빈이는 동생과 숨바꼭질을 하고 있다.
// 수빈이는 현재 점 N(0 <= N <= 100,000)에 있고, 동생은 점 K(0<= K <= 10,000)에 있다.
// 수빈이는 걷거나 순간이동을 할 수 있다.
// 만약, 수빈이의 위치가 X일 떄 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
// 순간이동을 하게 되는  경우에는 1초 후에 2*X의 위치로 이동하게 된다.
// 수빈이와 동생의 위치가 주어졌을 떄, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지
// 구하는 프로그램을 작성하시오.
//
// <입력>
// 첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다.
// N과 K는 정수이다.
//
// <출력>
// 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
/***********************************************************************************/

#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int dist[200002];
    fill(dist, dist+200002, -1);
    int dx[3] = {-1, 1, 2};
    queue<int> Q;

    int N, K;
    int count = 0;
    cin >> N >> K;

    dist[N] = 0;
    Q.push(N);
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 3; dir++) {
            if (dir <= 1) {
                int nx = cur + dx[dir];
                if (nx < 0 || nx >= 100001) {
                    continue;
                }
                if (dist[nx] != -1) {
                    continue;
                }
                dist[nx] = dist[cur] + 1;
                Q.push(nx);
            } else {
                int nx = cur * dx[dir];
                if (nx < 0 || nx >= 100001) {
                    continue;
                }
                if (dist[nx] != -1) {
                    continue;
                }
                dist[nx] = dist[cur] + 1;
                Q.push(nx);
            }
        }
    }
    cout << dist[K];
    return 0;
}