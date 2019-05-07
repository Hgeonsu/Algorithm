#include<iostream>
#include<queue>
using namespace std;
int dis[300][300];
queue<pair<int, int> >q;
int dr[8] = { -2, -1, 1, 2, 2, 1, -1, -2 }; // 나이트 방향 한시부터 CW
int dc[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int l; //체스판 길이
int desx, desy;
void bfs(pair<int, int> start) {

	q.push(start);
	dis[start.first][start.second]++; 
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		
		for (int i = 0; i < 8; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i]; //나이트가 움직일 수 있는 경우의 수

			//체스판 밖으로 나가면 continue
			if (nr < 0 || nr >= l || nc < 0 || nc >= l)continue;
			if (dis[nr][nc] >= 0)continue; //dis 배열 값이 0이상이면 방문한 적이 있는 것
			q.push({ nr, nc });
			dis[nr][nc] = dis[cur.first][cur.second] + 1;
			if (nr == desx && nc == desy)
				return;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int time;
	cin >> time;

	while (time > 0) {

		cin >> l;
		int startx, starty;
		cin >> startx >> starty;
		cin >> desx >> desy;

		//dis 배열 초기화
		for (int i = 0; i < 300; i++) {
			for (int j = 0; j < 300; j++) {
				dis[i][j] = -1;
			}
		}

		//queue 초기화
		while (!q.empty()) {
			q.pop();
		}
		
		bfs({ startx, starty });

		//결과
		cout << dis[desx][desy] <<'\n';
		
		time--;
	}
	return 0;
}