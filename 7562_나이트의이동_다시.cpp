//#include<iostream>
//#include<queue>
//using namespace std;
//int n, dist[301][301];
//queue<pair<int, int> >q;
//int dr[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
//int dc[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
//void bfs(pair<int, int> Src, pair<int, int> Dst) {
//	q.push(Src);
//	dist[Src.first][Src.second]++;
//	while (!q.empty()) {
//		pair<int, int> cur = q.front();
//		q.pop();
//		for (int i = 0; i < 8; i++) {
//			int nr = cur.first + dr[i];
//			int nc = cur.second + dc[i];
//			
//			if (nr < 0 || nc < 0 || nr >= n || nc >= n || dist[nr][nc] >= 0) continue;
//			
//			q.push({ nr, nc });
//			dist[nr][nc] = dist[cur.first][cur.second] + 1;
//			if (nr == Dst.first && nc == Dst.second) return; //이후에 큐 비우기
//		}
//	}
//}
//int main(void) {
//	int tc;
//	cin >> tc;
//	while (tc--) {
//		cin >> n;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				dist[i][j] = -1;
//			}
//		}
//		pair<int, int> src, dst;
//		cin >> src.first >> src.second >> dst.first >> dst.second;
//		bfs(src, dst);
//
//		cout << dist[dst.first][dst.second] << '\n';
//		
//		//초기화
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				dist[i][j] = -1;
//			}
//		}
//		while (!q.empty()) q.pop(); //queue가 비워지지 않은 상태로 bfs가 끝난다
//	}
//	return 0;
//}