//#pragma warning(disable:4996)
//#include<iostream>
//using namespace std;
//char m[101][101];
//bool vis[101][101];
//int N;
//int dr[4] = { 0,0,1, -1 };
//int dc[4] = { 1,-1,0,0 };
//int cnt1 = 0, cnt2 = 0;
//bool norCheck(int nr, int nc, char c) {
//	if (nr < 0 || nc < 0 || nr >= N || nc >= N || vis[nr][nc] || m[nr][nc] != c)
//		return true;
//	else
//		return false;
//}
//
//void dfs(int row, int col, char c) {
//	vis[row][col] = true;
//	
//	for (int i = 0; i < 4; i++) {
//		int nr = row + dr[i];
//		int nc = col + dc[i];
//
//		if (norCheck(nr, nc, c)) continue;
//		dfs(nr, nc, c);
//	}
//}
//int main(void) {
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> m[i];
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (!vis[i][j]) {
//				dfs(i, j, m[i][j]);
//				cnt1++;
//			}
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (m[i][j] == 'R') m[i][j] = 'G';
//			vis[i][j] = false;
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (!vis[i][j]) {
//				dfs(i, j, m[i][j]);
//				cnt2++;
//			}
//		}
//	}
//	cout << cnt1 << ' ' << cnt2 << '\n';
//
//	return 0;
//}
//
