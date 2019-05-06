#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int map[102][102]; //끝나면 초기화
int dis[102][102]; //마찬가지로 끝나면 초기화
int res[102];
int cnt = 0;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = {1,-1,0,0};
int M, N;
queue<pair<int, int> > q;
int bfs(pair<int,int> start) {
	int finDis = 0;
	q.push(start);
	dis[start.first][start.second] = 1;
	finDis++;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dy[i];
			int nc = cur.second + dx[i];

			// 지도에서 1이거나, 범위나가면 continue
			if (nr < 0 || nr >= M || nc < 0 || nc >= N)continue;
			if (map[nr][nc] == 1)continue;
			if (dis[nr][nc] > 0)continue; //방문했어도 통과

			//지도에서 0이면서 방문 안 했을 때만 아래 실행
			q.push({ nr,nc });
			dis[nr][nc] = 1;
			finDis++;
			//printf("\n[%d][%d]넓이 = %d\n", nr, nc, finDis);
		}
	}
	return finDis;
}
int main(void) {
	int time; // 몇번 실행할 지
	//cin >> time;
	time = 1;
	while (time > 0) {
		
		cin >> M >> N;
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			int lx, ly, rx, ry;
			cin >> lx >> ly >> rx >> ry;
			int lux = lx, luy = ry;
			int rbx = rx, rby = ly;
			for (int j = M - luy; j <= M - 1 - rby; j++) {
				for (int p = lux; p <= rbx - 1; p++) {
					if(map[j][p] == 1)continue;
					//printf("\nmap[%d][%d] = 1", j, p);
					map[j][p] = 1;
				}
			}
		}
		/*printf("\n");
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d", map[i][j]);
			}
			printf("\n");
		}*/

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (dis[i][j] == 0 && map[i][j] == 0) {
					//방문 안했고, 지도 상에서 0이면
					res[cnt] = bfs({ i, j });
					cnt++;
				}
			}
			//printf("\n");
		}
		
		cout << cnt << '\n';
		sort(res, res + cnt);
		for (int i = 0; i < cnt; i++) {
			cout << res[i] << ' ';
		}

		//초기화
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = 0;
				dis[i][j] = 0;
			}
		}
		cnt = 0;
		time--;
	}
	return 0;
}