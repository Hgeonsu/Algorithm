//#include<iostream>
//using namespace std;
//int N, m[102][102];
//bool vis[102][102];
//int dr[4] = { 0,0,1,-1 };
//int dc[4] = { 1,-1,0,0 };
//void dfs(int row, int col, int H) {
//	vis[row][col] = true;
//	for (int i = 0; i < 4; i++) {
//		int nr = row + dr[i];
//		int nc = col + dc[i];
//		if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
//		if (vis[nr][nc] || m[nr][nc] <= H) continue;
//		dfs(nr, nc, H);
//	}
//}
//void init() {
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			vis[i][j] = false;
//}
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> N;
//	int hMin = 110, hMax = -1;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> m[i][j];
//			if (m[i][j] > hMax) hMax = m[i][j];
//			if (m[i][j] < hMin) hMin = m[i][j];
//		}
//	}
//	
//	int cntMax = 0;
//	for (int h = hMin - 1; h <= hMax ; h++) {
//		int cntH = 0;
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				if (m[i][j] > h && !vis[i][j]) {
//					dfs(i, j, h);
//					cntH++;
//				}
//			}
//		}
//	
//		if (cntH > cntMax) cntMax = cntH;
//		init();
//	}
//	cout << cntMax << '\n';
//	return 0;
//}