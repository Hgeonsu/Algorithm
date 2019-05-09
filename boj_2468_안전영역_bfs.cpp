//잠긴 영역 = 0, 안전한 영역을 1로 해서 새로운 map 필요
//아무 지역도 물에 잠기지 않을 수도 있음
#include<iostream>
#include<queue>
using namespace std;

int N; //N*N 행렬
int map[101][101], fld[101][101], vis[101][101];
int hmax = -1;
int maxCnt = 0; //안전한 곳의 개수 최대값

queue<pair<int, int> > q;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0, };

void bfs(pair<int, int> start) {
	q.push(start);
	vis[start.first][start.second] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)continue;
			if (fld[nr][nc] == 0 || vis[nr][nc] == 1)continue;

			q.push({ nr, nc });
			vis[nr][nc] = 1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int time = 1; //TC 개수 받을 때
	//cin >> time;
	while (time > 0) {

		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (hmax < map[i][j]) {
					hmax = map[i][j];
				}
			}
		}
		//물 높이 0 ~ hmax 까지 포함, map[i][j] 값과 비교해서 fld[i]][j]채우고 bfs 해서 안전한 영역 개수 찾기
		for (int h = 0; h <= hmax; h++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (map[i][j] <= h) {
						fld[i][j] = 0; //잠긴 영역이면 fld = 0
					}
					else {
						fld[i][j] = 1; //안전한 영역이면 fld = 1
					}
				}
			}

			//위에까지 fld 완성

			int cnt = 0; //높이 별 안전한 영역의 개수
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (fld[i][j] == 1 && vis[i][j] == 0) {
						bfs({ i, j });
						cnt++;
					}
				}
			}

			if (maxCnt < cnt) {
				maxCnt = cnt;
			}

			//vis 배열 초기화 안 해서 처음에 결과 제대로 안나옴
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					vis[i][j] = 0;
				}
			}
		}
		cout << maxCnt << '\n'; //결과 출력

		//map, fld, vis초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = 0;
				fld[i][j] = 0;
				vis[i][j] = 0;
			}
		}
		hmax = -1;
		maxCnt = 0;
		time--;
	}
	return 0;
}