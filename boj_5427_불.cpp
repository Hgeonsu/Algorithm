//#include<iostream>
//#include<queue>
//using namespace std;
//int Col, Row, dis[1001][1001]; //dis�� ����� ���� ��ġ(�� �������� �ִܰŸ�)�� ����
//char m[1001][1001]; //���� ����
//bool Fire[1001][1001]; //���� ���� ���� ����
//int dr[4] = { 0,0,1,-1 };
//int dc[4] = { 1,-1,0,0 };
//queue<pair<int, int> > fireQ; //���� ������ ������ ť
//queue < pair<int, int> > q; //����� �̵��� ������ ť
//void Fbfs() {
//	while (!q.empty()) { //����� ������ ��ġ�� ������ �� �̻��� ������ ���ǹ�
//
//		int num = fireQ.size(); //�� �� �ִ� �Ҳ����θ� Ȯ�� ����
//		while (num--) { 
//			pair<int, int> cur = fireQ.front();
//			fireQ.pop();
//			for (int i = 0; i < 4; i++) {
//				int nr = cur.first + dr[i];
//				int nc = cur.second + dc[i];
//				if (nr < 0 || nc < 0 || nr >= Row || nc >= Col) continue;
//				if (m[nr][nc] == '#' || Fire[nr][nc]) continue; //�� or �̹� ���� �����ϴ� ���̸� continue
//				//printf("\n%d %d �߰�\n", nr, nc);
//				fireQ.push({ nr, nc });
//				Fire[nr][nc] = true;
//				m[nr][nc] = '*';
//			}
//		}
//
//		int Run = q.size(); //�Ұ� ���������� ���� ��ĭ�� �����̰� ����
//		while (Run--) {
//			pair<int, int> cur = q.front();
//			q.pop();
//			for (int i = 0; i < 4; i++) {
//				int nr = cur.first + dr[i];
//				int nc = cur.second + dc[i];
//				if (nr < 0 || nc < 0 || nr >= Row || nc >= Col) {
//					//Ż��ó�� -> �ǹ� ������ ���µ� n�� �ɷȰ�, ���� �Ѿ�ϱ� +1
//					cout << dis[cur.first][cur.second] + 1 << '\n';
//					return;
//				}
//				if (dis[nr][nc] >= 0 || m[nr][nc] != '.')continue; //�̹� ������ ���̰ų� �̵��� �� �ִ� ���� �ƴϸ� continue
//				q.push({ nr, nc });
//				dis[nr][nc] = dis[cur.first][cur.second] + 1;
//			}
//		}
//	}
//	cout << "IMPOSSIBLE" << '\n';
//}
//void init() {
//	for (int i = 0; i < Row; i++) {
//		for (int j = 0; j < Col; j++) {
//			dis[i][j] = -1; // 0�̻��̸� ����� ���İ� ����(�湮 �Ϸ�)
//			Fire[i][j] = false;
// 		}
//	}
//	while (!q.empty()) q.pop(); //Ż�� ���ǿ��� ť�� ���� �ʾҴµ� �Լ��� �����
//	while (!fireQ.empty()) fireQ.pop();
//}
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		cin >> Col >> Row;
//		
//		init(); //TC�� ������, ť�� ������ ����� �ʰ� ������ ��쵵 �����Ƿ� ť�� �ʱ�ȭ
//		for (int i = 0; i < Row; i++) {
//			for (int j = 0; j < Col; j++) {
//				cin >> m[i][j];
//				if (m[i][j] == '@') { //����� ���� ��ġ�� ��Ƶ־���. ���� ���� ���� ������
//					q.push({ i, j }); 
//					dis[i][j]++;
//				}
//			}
//		}
//		
//
//		for (int i = 0; i < Row; i++) {
//			for (int j = 0; j < Col; j++) {
//				if (m[i][j] == '*' && !Fire[i][j]) {
//					fireQ.push({ i, j });
//					Fire[i][j] = true;
//				}
//			}
//		}
//		Fbfs();
//	}
//	return 0;
//}
//////print
////cout << '\n';
////for (int i = 0; i < Row; i++) {
////	for (int j = 0; j < Col; j++) {
////		//cout << m[i][j] << ' ';
////		cout << dis[i][j] << ' ';
////	}
////	cout << '\n';
////}