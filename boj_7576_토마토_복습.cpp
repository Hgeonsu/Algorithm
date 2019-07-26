//#include<iostream>
//#include<queue>
//using namespace std;
//int col, row, m[1000][1000];
//queue<pair<int, int> > q;
//bool vis[1000][1000];
//int dr[4] = { 0, 0, 1, -1 };
//int dc[4] = { 1, -1, 0, 0 };
//int Day = 0;
//bool isChanged = false;
//void bfs() {
//	
//	while (!q.empty()) {
//		int cnt = q.size();
//		isChanged = false;
//		while (cnt--) {
//			pair<int, int> cur = q.front();
//			q.pop();
//			
//			for (int i = 0; i < 4; i++) {
//				int nr = cur.first + dr[i];
//				int nc = cur.second + dc[i];
//				if (nr < 0 || nc < 0 || nr >= row || nc >= col) continue;
//				if (m[nr][nc] == -1 || vis[nr][nc] == true || m[nr][nc] == 1) continue;
//
//				m[nr][nc] = 1;
//				q.push({ nr, nc });
//				vis[nr][nc] = true;
//				isChanged = true;
//			}
//		}
//		if (!isChanged) break;
//		Day++;
//		
//	}
//	
//}
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> col >> row;
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			cin >> m[i][j];
//			if (m[i][j] == 1) {
//				q.push({ i, j });
//				vis[i][j] = true;
//			}
//		}
//	}
//	bfs();
//	
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			if (m[i][j] == 0) {
//				cout << -1 << '\n';
//				return 0;
//			}
//		}
//	}
//	
//	cout << Day <<'\n';
//	return 0;
//}
