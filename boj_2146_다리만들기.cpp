//섬의 개수를 구하기 위한 bfs,
//각 섬에서 다른 섬으로의 거리를 구하기 위한 bfs
#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
int N;
int map[101][101], idx[101][101], dis[101][101];
queue<pair<int, int> > q;
int index = -1;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int Min = 999;
void bfs(pair<int, int> start) { //영역 개수 구하는 bfs
	q.push(start);
	idx[start.first][start.second] = index;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= N)continue;

			if (map[nr][nc] == 0 || idx[nr][nc] >= 0)continue; //방문한적 있거나 육지가 아니면 continue;

			q.push({ nr, nc });
			idx[nr][nc] = index;
		}

	}
}

void bfsDis() {

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= N)continue;
			if (idx[nr][nc] == idx[cur.first][cur.second]) continue; //같은 섬이면 거리 안재고 continue
			if (dis[nr][nc] < 0 && idx[nr][nc] < 0) {
				//거리가 측정이 되지 않았으면서 바다인 경우
				dis[nr][nc] = dis[cur.first][cur.second] + 1; //방문처리(거리측정)
				q.push({ nr,nc });
				idx[nr][nc] = idx[cur.first][cur.second]; //dis배열의 값이, 어느 섬으로부터 측정된 건지 알아야하기 때문에 idx 값도 같이 바꿔줌
			}
			if (dis[nr][nc] > 0 && idx[cur.first][cur.second] != idx[nr][nc]) { //다른 섬으로부터 거리가 측정된 지점을 만난 경우
				if (Min > dis[nr][nc] + dis[cur.first][cur.second]) {
					Min = dis[nr][nc] + dis[cur.first][cur.second];

				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			idx[i][j] = -1;
			if (map[i][j] == 0) {
				dis[i][j] = -1; //바다인 경우 dis 값 -1로 초기화
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && idx[i][j] < 0) {
				//섬 index 할당 안된거면 방문 안한거니까
				index++; //index를 뭘로 초기화 해놓냐에 따라서 순서가 다름
				bfs({ i,j });
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (idx[i][j] >= 0) {
				q.push({ i, j });
				dis[i][j] = 0; //이미 0으로 초기화 되어있긴 함
			}
		}
	}
	bfsDis();

	cout << Min << '\n';

}
