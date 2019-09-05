#include<iostream>
#include<queue>

using namespace std;
int map[201][201], row, col, k;
bool  vis[201][201][31]; //r, c, 점프 가능 회수
struct Info {
	int r, c, jump, cnt;
};

queue<Info> q;
const int dr[4] = { 0,0,1,-1 };
const int dc[4] = { 1,-1,0,0 };
const int jr[8] = { -2,-1,1,2,2,1,-1,-2 };
const int jc[8] = { 1,2,2,1,-1,-2,-2,-1 };
void Print() {
	cout << '\n';
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << vis[i][j] << '\t';
		}
		cout << '\n';
	}
}
void bfs() {
	q.push({ 0, 0, k, 0 });
	vis[0][0][k] = true;
	while (!q.empty()) {
		int qs = q.size();
		//cout << qs << '\n';
		while (qs--) {
			
			Info cur = q.front();
			q.pop();
			if (cur.r == row - 1 && cur.c == col - 1) {
			//	printf("도착 %d", cur.cnt);
				cout << cur.cnt;
				return;
			}
			for (int i = 0; i < 4; i++) {
				int nr = cur.r + dr[i];
				int nc = cur.c + dc[i];
				if (nr < 0 || nc < 0 || nr >= row || nc >= col || map[nr][nc] == 1) continue;
				//if (vis[nr][nc] >= 0 && vis[nr][nc] >= cur.jump) continue;
				if (vis[nr][nc][cur.jump]) continue;
				q.push({ nr, nc, cur.jump, cur.cnt + 1 });
				vis[nr][nc][cur.jump] = true;
				//Print();
			}

			if (cur.jump <= 0) continue;
			for (int i = 0; i < 8 ; i++) {
				int nr = cur.r + jr[i];
				int nc = cur.c + jc[i];
				if (nr < 0 || nc < 0 || nr >= row || nc >= col || map[nr][nc] == 1) continue;
				//if (cur.jump <= vis[nr][nc]) continue;
				if (vis[nr][nc][cur.jump - 1]) continue;
				q.push({ nr, nc, cur.jump - 1, cur.cnt + 1 });
				vis[nr][nc][cur.jump - 1] = true;
				//Print();
			}

		}
	}
	cout << -1;
}

int main(void) {
	cin >> k >> col >> row;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			//vis[i][j] = -1;
		}
	}

	bfs();

	return 0;
}