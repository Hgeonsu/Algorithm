#include<iostream>
#include<queue>
using namespace std;
//M = col, N = row, K = 배추있는 곳의 개수
int N, M, K;
int map[51][51], vis[51][51];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int num = 0;
queue<pair<int, int> > q;
void bfs(pair<int, int> start) {
	q.push(start);
	vis[start.first][start.second] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M)continue;
			if (map[nr][nc] == 0 || vis[nr][nc] == 1)continue;

			q.push({ nr,nc });
			vis[nr][nc] = 1;

		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int time;
	cin >> time;
	while (time > 0) {
		cin >> M >> N >> K;
		num = 0;
		for (int i = 0; i < K; i++) {
			int row, col;
			cin >> col >> row;
			map[row][col] = 1;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1 && vis[i][j] == 0) {
					bfs({ i,j });
					num++;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = 0;
				vis[i][j] = 0;
			}
		}

		cout << num << '\n';


		time--;
	}
	return 0;
}
