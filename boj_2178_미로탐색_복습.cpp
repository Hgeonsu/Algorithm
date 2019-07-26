//#pragma warning(disable : 4996)
//#include<iostream>
//#include<queue>
//using namespace std;
//int n, m, map[101][101], dis[101][101];
//
//queue<pair<int, int> > q;
//int dr[4] = { 0, 0, 1, -1 };
//int dc[4] = { 1, -1, 0, 0 };
//void bfs(pair<int, int> start) {
//	q.push(start);
//	dis[start.first][start.second]++;
//	while (!q.empty()) {
//		pair<int, int> cur = q.front();
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int nr = cur.first + dr[i];
//			int nc = cur.second + dc[i];
//
//			if (nr < 0 || nc < 0 || nr >= n || nc >= m || map[nr][nc] == 0 || dis[nr][nc] > 0) continue;
//
//			q.push({ nr, nc });
//			dis[nr][nc] = dis[cur.first][cur.second] + 1;
//		}
//	}
//}
//int main(void) {
//	//ios::sync_with_stdio(false); 이거 적어두고 아래에서 scanf 쓰면 gcc에선 틀린다
//	cin.tie(0);
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			scanf("%1d", &map[i][j]);
//
//
//	bfs({ 0, 0 });
//	cout << dis[n - 1][m - 1] << '\n';
//	return 0;
//}
