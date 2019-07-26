//#pragma warning(disable :4996)
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//using namespace std;
//int m[26][26], n;
//bool vis[26][26];
//vector<int> v;
//queue<pair<int, int> > q;
////int bigCnt = 0; //단지수
//int dr[4] = { 0,0,1,-1 };
//int dc[4] = { 1, -1, 0, 0 };
//
//void bfs(pair<int, int> start) {
//	//bigCnt++; //단지수 증가
//	q.push(start);
//	vis[start.first][start.second] = true;
//	int houseCnt = 1; // 시작점도 집이니까 1부터 시작
//	while (!q.empty()) {
//		pair<int, int> cur = q.front();
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int nr = cur.first + dr[i];
//			int nc = cur.second + dc[i];
//			
//			if (nr < 0 || nc < 0 || nr >= n || nc >= n)continue;
//			if (m[nr][nc] == 0 || vis[nr][nc] == true) continue; //집x or 이미방문
//
//			q.push({ nr, nc });
//			vis[nr][nc] = true;
//			houseCnt++;
//			
//		}
//	}
//	v.push_back(houseCnt);
//}
//int main(void) {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			scanf("%1d", &m[i][j]);
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (m[i][j] == 1 && vis[i][j] == false) {
//				bfs({ i, j });
//			}
//		}
//	}
//	sort(v.begin(), v.end());
//	cout << v.size() << '\n';
//	for (int i = 0; i < v.size(); i++)
//		cout << v[i] << '\n';
//	return 0;
//}