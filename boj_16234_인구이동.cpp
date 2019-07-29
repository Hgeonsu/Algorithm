//#include<iostream>
//#include<queue>
//#include<math.h>
//#include<vector>
//using namespace std;
//int N, L, R, m[51][51];
//bool bor[51][51]; //방문 처리 배열
//int dr[4] = { 0, 0, 1, -1 };
//int dc[4] = { 1, -1, 0, 0 };
//
//queue<pair<int, int> > q;
//bool updated = false;
//int idxSum = 0;
//vector<pair<int, int> > v;
//void bfs(pair<int, int> start) {
//	q.push(start);
//	bor[start.first][start.second] = true;
//
//	while (!q.empty()) {
//		pair<int, int> cur = q.front();
//		q.pop();
//		
//		for (int i = 0; i < 4; i++) {
//			int nr = cur.first + dr[i];
//			int nc = cur.second + dc[i];
//			if (nr < 0 || nc < 0 || nr >= N || nc >= N || bor[nr][nc])
//				continue;
//			if (abs(m[nr][nc] - m[cur.first][cur.second]) >= L &&
//				abs(m[nr][nc] - m[cur.first][cur.second]) <= R) {
//				q.push({ nr, nc });
//				bor[nr][nc] = true; 
//				
//				v.push_back({ nr, nc });
//				idxSum += m[nr][nc];
//			}
//		}
//	}
//}
//void init() {
//	for (int i = 0; i < N; i++) 
//		for (int j = 0; j < N; j++) 
//			bor[i][j] = 0;
//}
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> N >> L >> R;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			cin >> m[i][j];
//
//	int res = 0;
//	while (1) {
//		updated = false;
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				if (!bor[i][j]) {
//					v.clear();
//					v.push_back({ i,j }); 
//					idxSum = m[i][j];
//					bfs({ i, j });
//				}
//				//열린 국경이 있으면
//				if (v.size() >= 2) { //한 연합 내의 국가 개수
//					updated = true;
//					int val = idxSum / v.size();
//					for (int i = 0; i < v.size(); i++) {
//						m[v[i].first][v[i].second] = val;
//					}
//				}
//			}
//		}
//		if (updated) res++;
//		else break;
//		init();
//	}
//	cout << res << '\n';
//	return 0;
//}
