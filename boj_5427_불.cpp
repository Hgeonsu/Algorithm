//#include<iostream>
//#include<queue>
//using namespace std;
//int Col, Row, dis[1001][1001]; //dis로 사람의 매초 위치(그 지점까지 최단거리)를 관리
//char m[1001][1001]; //빌딩 상태
//bool Fire[1001][1001]; //불의 존재 여부 관리
//int dr[4] = { 0,0,1,-1 };
//int dc[4] = { 1,-1,0,0 };
//queue<pair<int, int> > fireQ; //불의 번짐을 관리할 큐
//queue < pair<int, int> > q; //사람의 이동을 관리할 큐
//void Fbfs() {
//	while (!q.empty()) { //사람이 움직일 위치가 없으면 더 이상의 진행이 무의미
//
//		int num = fireQ.size(); //매 초 있던 불꽃으로만 확산 진행
//		while (num--) { 
//			pair<int, int> cur = fireQ.front();
//			fireQ.pop();
//			for (int i = 0; i < 4; i++) {
//				int nr = cur.first + dr[i];
//				int nc = cur.second + dc[i];
//				if (nr < 0 || nc < 0 || nr >= Row || nc >= Col) continue;
//				if (m[nr][nc] == '#' || Fire[nr][nc]) continue; //벽 or 이미 불이 존재하는 곳이면 continue
//				//printf("\n%d %d 추가\n", nr, nc);
//				fireQ.push({ nr, nc });
//				Fire[nr][nc] = true;
//				m[nr][nc] = '*';
//			}
//		}
//
//		int Run = q.size(); //불과 마찬가지로 매초 한칸씩 움직이게 통제
//		while (Run--) {
//			pair<int, int> cur = q.front();
//			q.pop();
//			for (int i = 0; i < 4; i++) {
//				int nr = cur.first + dr[i];
//				int nc = cur.second + dc[i];
//				if (nr < 0 || nc < 0 || nr >= Row || nc >= Col) {
//					//탈출처리 -> 건물 끝까지 가는데 n초 걸렸고, 이제 넘어가니까 +1
//					cout << dis[cur.first][cur.second] + 1 << '\n';
//					return;
//				}
//				if (dis[nr][nc] >= 0 || m[nr][nc] != '.')continue; //이미 지나온 길이거나 이동할 수 있는 길이 아니면 continue
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
//			dis[i][j] = -1; // 0이상이면 사람이 거쳐간 상태(방문 완료)
//			Fire[i][j] = false;
// 		}
//	}
//	while (!q.empty()) q.pop(); //탈출 조건에서 큐가 비지 않았는데 함수가 종료됨
//	while (!fireQ.empty()) fireQ.pop();
//}
//int main() {
//	int T;
//	cin >> T;
//	while (T--) {
//		cin >> Col >> Row;
//		
//		init(); //TC가 여러개, 큐를 완전히 비우지 않고 끝내는 경우도 있으므로 큐도 초기화
//		for (int i = 0; i < Row; i++) {
//			for (int j = 0; j < Col; j++) {
//				cin >> m[i][j];
//				if (m[i][j] == '@') { //사람의 시작 위치를 담아둬야함. 불이 덮어 쓰기 때문에
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