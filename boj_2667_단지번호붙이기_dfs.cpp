//#pragma warning(disable :4996)
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int n, m[26][26];
//bool vis[26][26];
//int dr[4] = { 0,0,1,-1 };
//int dc[4] = { 1,-1,0,0 };
//int homeCnt = 1;
//vector<int> v;
//void dfs(int row, int col) {
//	vis[row][col] = true;
//
//	for (int i = 0; i < 4; i++) {
//		int nr = row + dr[i];
//		int nc = col + dc[i];
//
//		if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
//		if (vis[nr][nc] || m[nr][nc] == 0) continue;
//		
//		homeCnt++;
//		dfs(nr, nc);
//	}
//}
//
//int main(void) {
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			scanf("%1d", &m[i][j]);
//	
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (!vis[i][j] && m[i][j] == 1) {
//				dfs(i, j);
//				v.push_back(homeCnt);
//				homeCnt = 1;
//			}
//		}
//	}
//	sort(v.begin(), v.end());
//
//	cout << v.size() << '\n';
//	for (int i = 0; i < v.size(); i++)
//		cout << v[i] << '\n';
//	return 0;
//}