#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n, m, map[502][502], vis[502][502];
queue<pair<int, int> > q;
int dx[4] = { 1, -1, 0, 0 }; //좌표 그대로 동서남북 순
int dy[4] = { 0, 0, 1, -1 }; 

int bfs(pair<int,int> start) {
	q.push(start);
	vis[start.first][start.second] = 1;
	int dist = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dy[i];
			int nc = cur.second + dx[i];
			
			if (vis[nr][nc] == 1 || nr < 0 || nr >= n || nc < 0 || nc >= m)continue;
			if (map[nr][nc] != 1)continue;
			
			vis[nr][nc] = 1;
			dist++;
			q.push({ nr, nc });
		}
	}
	return dist;
}
int main(void) {
	int max = 0, cnt = 0;
	int result=0; // 초기화 안해줘서 틀렸었음
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == 0 && map[i][j] == 1)
			{
				//pair<int, int> start = { i, j };
				result = bfs({ i, j });
				cnt++;
			}
			if (max < result) {
				max = result;
			}
		}
	}
	//if (cnt == 0)max = 0;
	cout << cnt << '\n' << max;
	return 0;
}