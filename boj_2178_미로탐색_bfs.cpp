#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int N, M;
int map[102][102]; // 초기화 필요

int dis[102][102];
queue<pair<int, int> > q;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };


void bfs(pair<int,int> start) {
	q.push(start);
	dis[start.first][start.second]++;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dy[i];
			int nc = cur.second + dx[i];

			if (nr < 1 || nr > N || nc < 1 || nc > M)continue; //범위 벗어나는 경우
			if (dis[nr][nc] > 0)continue; // 이미 방문했을 경우 통과
			if (map[nr][nc] == 0)continue; //확인할 필요 없는 경우 통과
			
			q.push({ nr,nc });
			dis[nr][nc] = dis[cur.first][cur.second] + 1;
			//printf("\ndist[%d][%d] = %d\n", nr, nc, dis[nr][nc]);
		}
	}
}

int main(void) {
	int time = 1;
	//cin >> time;
	while (time > 0) {
		
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				scanf_s("%1d", &map[i][j]); // gcc에 돌리면 컴파일에러. boj에서도 
			}
		}
		
		bfs({ 1,1 });
		cout << dis[N][M] << '\n'; //결과

		//map 초기화
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				map[i][j] = 0;
				dis[i][j] = 0;
			}
		}
		time--;
	}
	return 0;
}