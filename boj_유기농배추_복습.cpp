//#include<iostream>
//#include<queue>
//using namespace std;
//int map[51][51], vis[51][51];
//int m, n, k;
//
//int cnt = 0;
//queue<pair<int, int> > q;
//int dr[4] = { 0, 0, 1, -1 };
//int dc[4] = { 1, -1, 0, 0 };
//void bfs(pair<int, int> start) { //�������� bfs
//	cnt++; //�� ���� �߰�
//	q.push(start);
//	vis[start.first][start.second] = 1;
//	while (!q.empty()) {
//		pair<int, int> cur = q.front();
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int nr = cur.first + dr[i];
//			int nc = cur.second + dc[i];
//			//���� �����ų� ���߰� ���� ���̰ų� �̹� �湮�� ���̸� continue
//			if (nr < 0 || nc < 0 || nr >= n || nc >= m || vis[nr][nc] == 1 || map[nr][nc] == 0)continue;
//			
//			q.push({ nr, nc });
//			vis[nr][nc] = 1;
//
//		}
//	}
//
//}
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	int tc;
//	cin >> tc;
//	while (tc--) {
//
//		cin >> m >> n >> k;
//
//		int n1, n2;
//		while (k--) {
//			cin >> n1 >> n2;
//			map[n2][n1] = 1;
//		}
//
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < m; j++)
//				if (map[i][j] == 1 && vis[i][j] == 0)
//					bfs({ i, j }); //1�� ���� �Ѱ������
//
//		cout << cnt << '\n';
//
//		//���ķ� �ʱ�ȭ
//		for (int i = 0; i < n; i++) 
//			for (int j = 0; j < m; j++) {
//				map[i][j] = 0;
//				vis[i][j] = 0;
//			}
//		cnt = 0;
//	}
//
//	return 0;
//}
