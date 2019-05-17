#include<iostream>
#include<queue>
using namespace std;
char map[31][31][31]; //층,row, col
int vis[31][31][31];
int dr[6] = { 0,0,-1,1,0,0 }; // 동서남북상하
int dc[6] = { 1, -1, 0,0,0,0 };
int dh[6] = { 0,0,0,0,1,-1 };
int h, r, c;
pair<int, pair<int, int> > start;
pair<int, pair<int, int> > dest;
int time = 0;
bool done = false;

queue<pair<int, pair<int, int> > > q;

void bfs() {
	q.push(start);
	vis[start.first][start.second.first][start.second.second]++;
	while (!q.empty()) {
		pair<int, pair<int, int> > cur = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nh = cur.first + dh[i];
			int nr = cur.second.first + dr[i];
			int nc = cur.second.second + dc[i];

			if (nh < 0 || nr < 0 || nc < 0 || nh >= h || nr >= r || nc >= c)continue;
			if (vis[nh][nr][nc] > 0 || map[nh][nr][nc] == '#')continue;
		
			vis[nh][nr][nc] = vis[cur.first][cur.second.first][cur.second.second] + 1;
			q.push({ nh, {nr, nc} });
			if (nh == dest.first && nr == dest.second.first && nc == dest.second.second) {
				done = true;
				return;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//문자로 받고 6방향
	
	while (1) {
		cin >> h >> r >> c;
		if (h == 0 && r == 0 && c == 0)
			break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S') {
						start = { i, {j, k} };
					}
					else if (map[i][j][k] == 'E') {
						dest = { i, {j, k} };
					}
				}
			}
		}
		bfs();

		if (done) {
			cout << "Escaped in " << vis[dest.first][dest.second.first][dest.second.second] - 1 << " minute(s).\n";
		}
		else {
			cout << "Trapped!\n";
		}
		//초기화
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					vis[i][j][k] = 0;
					map[i][j][k] = NULL;
				}
			}
		}
		done = false;
		while (!q.empty()) {
			q.pop();
		}
	}

	return 0;
}
/*
전형적인 6방햑 탐색. queue를 완전히 비우지 않고 bfs에서 while문을 탈출하기 때문에 초기화 시킬 때 queue를 비워줘야 하는 것 주의
*/