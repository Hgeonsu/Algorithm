//#include<iostream>
//using namespace std;
//int R, C, m[300][300];
//bool vis[300][300];
//int dr[4] = { 0,0,1,-1 };
//int dc[4] = { 1,-1,0,0 };
//void dfs(int row, int col) {
//	vis[row][col] = true;
//	
//	for (int i = 0; i < 4; i++) {
//		int nr = row + dr[i];
//		int nc = col + dc[i];
//		
//		if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
//		if (vis[nr][nc] || m[nr][nc] == 0) continue;
//		dfs(nr, nc);
//	}
//}
//int Flood() {
//	int res = 0;
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			if (m[i][j] != 0 && !vis[i][j]) {
//				res++;
//				if (res > 1) break;
//				dfs(i, j);
//			}
//		}
//	}
//	return res;
//}
//void init() {
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			vis[i][j] = false;
//		}
//	}
//}
//void Melt(int row, int col) {
//	vis[row][col] = true;
//	int cnt = 0;
//	for (int i = 0; i < 4; i++) {
//		int nr = row + dr[i];
//		int nc = col + dc[i];
//
//		if (nr < 0 || nc < 0 || nr >= R || nc >= C || vis[nr][nc]) continue;
//		if (m[nr][nc] == 0) cnt++;
//		else if (m[nr][nc] == 1) Melt(nr, nc);
//	}
//	if (m[row][col] - cnt <= 0) m[row][col] = 0;
//	else
//		m[row][col] = m[row][col] - cnt;
//}
//
//int main() {
//	cin >> R >> C;
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			cin >> m[i][j];
//		}
//	}
//
//	int year = 0;
//	while (1) {
//		for (int i = 0; i < R; i++) {
//			for (int j = 0; j < C; j++) {
//				if (m[i][j] != 0 && !vis[i][j]) {
//					Melt(i, j);
//				}
//			}
//		}
//		year++;
//		init();
//		if (Flood() > 1) {
//			cout << year << '\n';
//			break;
//		}
//		init();
//		if (Flood() == 0) {
//			cout << 0 << '\n';
//			break;
//		}
//		init();
//	}
//	return 0;
//}