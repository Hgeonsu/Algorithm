#include<iostream>
#include<algorithm>
#include<queue>
#pragma warning(disable:4996)
using namespace std;
int map[26][26], vis[26][26];
int N;
queue<pair<int, int> > q;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int res[625]; //길이 25가능한데, 1씩 띄어서 아파트 있는 게 최대니까 크기[13 * 13][13 * 13]일듯 -> 아님 런타임에러로 터짐

int bfs(pair<int, int> start) {
	q.push(start);
	vis[start.first][start.second] = 1;
	int homeCnt = 1;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];

			//범위 벗어나면 continue
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)continue;
			if (map[nr][nc] == 0 || vis[nr][nc] == 1)continue; //집이 아니거나, 방문했으면 continue

			q.push({ nr,nc });
			vis[nr][nc] = 1;
			homeCnt++;
		}
	}

	//for문 통과 회수 return
	return homeCnt;
}

int main(void) {
	int time;
	time = 1;
	cin >> time;
	while (time > 0) {
		int cnt = 0; // 전체 단지의 수

		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &map[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1 && vis[i][j] == 0) {
					res[cnt] = bfs({ i, j }); //res 크기 잡을 때 주의 -> 
					cnt++;
				}
			}
		}
		
		//res 배열에 각 단지의 크기 저장, cnt = 전체 단지의 개수
		
		cout << cnt << '\n';
		sort(res, res + cnt);
		for (int i = 0; i < cnt; i++) {
			cout << res[i] << '\n';
		}

		//초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = 0;
				vis[i][j] = 0;
			}
		}
		//res는 덮어 씌워지니까 상관없음
		time--;
	}
	return 0;
}