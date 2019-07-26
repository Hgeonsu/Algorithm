//#include<iostream>
//#include<queue>
//using namespace std;
//
//int map[500][500], dist[500][500];
//int row, col;
//
//queue<pair<int, int> > q;
//int dr[4] = { 0, 0, 1, -1 };
//int dc[4] = { 1, -1, 0, 0, };
//
//int cnt = 0;
//void bfs(pair<int, int> start) {
//	cnt++; //섬개수 확인
//	q.push(start);
//	dist[start.first][start.second]++; 
//	int di = 2; //위에서 시작점 방문하면 거리 1이니까, 다음으로 들어갈 거리는 2
//
//	while (!q.empty()) {
//		pair<int, int> cur = q.front();
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int nr = cur.first + dr[i];
//			int nc = cur.second + dc[i];
//
//			if (nr < 0 || nc < 0 || nr >= row || nc >= col || map[nr][nc] == 0 || dist[nr][nc] > 0)continue;
//
//			q.push({ nr, nc });
//			dist[nr][nc] = di;
//			di++;
//			
//		}
//	}
//}
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> row >> col;
//	for(int i = 0 ; i < row ; i++)
//		for (int j = 0; j < col; j++) {
//			cin >> map[i][j];
//		}
//
//	for (int i = 0; i < row; i++)
//		for (int j = 0; j < col; j++) {
//			if (map[i][j] == 1 && dist[i][j] == 0)
//				bfs({ i, j });
//		}
//	//방문처리 배열에 카운트를 해뒀기때문에 그 안에서 최댓값을 구하면 된다.
//	int Max = -1;
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			if (dist[i][j] > Max)
//				Max = dist[i][j];
//		}
//	}
//	cout << cnt << '\n' << Max << '\n';
//	return 0;
//}
