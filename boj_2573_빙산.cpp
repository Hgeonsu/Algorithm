#include<iostream>
#include<queue>
using namespace std;
int map[301][301], sub[301][301];
bool vis[301][301];
int row, col;
int cnt = 0;
queue<pair<int, int> > cntQ;
queue<pair<int, int> > q;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
void bfsCnt(pair<int, int> start) {
	cnt++;
	cntQ.push(start);
	vis[start.first][start.second] = true;
	while (!cntQ.empty()) {
		pair<int, int> cur = cntQ.front();
		cntQ.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];

			if (nr < 0 || nc < 0 || nr >= row || nc >= col)continue;
			if (map[nr][nc] == 0 || vis[nr][nc] == true)continue;

			vis[nr][nc] = true;
			cntQ.push({ nr, nc });
		}
	}
}

void makeSub(pair<int, int> start) {

	q.push(start);
	vis[start.first][start.second] = true;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		int melt = 0;
		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];

			if (nr < 0 || nc < 0 || nr >= row || nc >= col)continue;
			if (map[nr][nc] == 0) {
				sub[cur.first][cur.second]++;
				continue;
			}
			if (vis[nr][nc] == true)continue;

			vis[nr][nc] = true;
			q.push({ nr, nc });
		}
	}
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}
	int year = 0;
	bool allzero = true;
	while (1) {
		allzero = true;
		cnt = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] != 0 && vis[i][j] == false) {
					bfsCnt({ i, j });
				}
			}
		}
		//vis 초기화
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				
				//전부 녹을때까지 분리 안되는 경우 잡기 위해
				if (map[i][j] != 0) {
					allzero = false;
				}
				if (vis[i][j] == true)
					vis[i][j] = false;
			}
		}
		if (cnt >= 2 || allzero) {
			break;
		}

		else if (cnt < 2) {
			year++;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					if (map[i][j] != 0 && vis[i][j] == false) {
						makeSub({ i, j });
					}

				}
			}
		}
		//vis 초기화
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (vis[i][j] == true)
					vis[i][j] = false;

			}
		}

		//녹은 빙산 갱신 동시에 녹는양 배열 초기화
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {

				if (map[i][j] - sub[i][j] < 0)
					map[i][j] = 0;
				else {
					map[i][j] = map[i][j] - sub[i][j];
				}
				sub[i][j] = 0;
			}
		}
	}
	if (allzero)
		cout << 0 << '\n';
	else
		cout << year << '\n';

	return 0;
}
/*
빙산 개수 파악을 위해 전형적인 flood fill 사용
빙산의 값을 갱신할 때, 동시에 갱신되는 효과를 보기 위해서 sub배열 사용
초기화 할 것들 주의해서 초기화
*/