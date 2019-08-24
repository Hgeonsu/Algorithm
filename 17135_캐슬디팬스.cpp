//#include<iostream>
//#include<queue>
//#include<set>
//using namespace std;
//typedef pair<int, int> pii;
//int m[19][18], tmp[19][18], N, M, d, st = 1, arr[19], dis[19][18];
//int dr[3] = { 0,-1,0 }, dc[3] = {-1, 0, 1};
//bool isused[18];
//queue<pii> q;
//set<pii> killed;
//
//void bfs(pii start) {
//	dis[start.first][start.second]++;
//	q.push(start);
//	while (!q.empty()) {
//		pii cur = q.front(); q.pop();
//		if (dis[cur.first][cur.second] >= d) continue; //사정거리 마지막 점
//		for (int i = 0; i < 3; i++) {
//			int nr = cur.first + dr[i];
//			int nc = cur.second + dc[i];
//			if (nr < 1 || nc < 1 || nr > N || nc > M || dis[nr][nc] >= 0) continue;
//			if (m[nr][nc] == 1) {
//				killed.insert({ nr, nc });
//				return;
//			}
//
//			q.push({ nr, nc });
//			dis[nr][nc] = dis[cur.first][cur.second] + 1;
//		}
//	}
//}
//void init() {
//	for(int i = 1 ; i <= N+1 ; i++)
//		for(int j = 1 ; j <= M ; j++)
//			dis[i][j] = -1;
//	while (!q.empty()) q.pop();
//}
//bool allKilled() {
//	for (int i = 1; i <= N; i++)
//		for (int j = 1; j <= M; j++) 
//			if (m[i][j] != 0) 
//				return false;
//		
//	return true;
//}
//int kill() {
//	int cnt = 0;
//	for (set<pii>::iterator itr = killed.begin(); itr != killed.end(); itr++) {
//		m[itr->first][itr->second] = 0;
//		cnt++;
//	}
//	killed.clear();
//	return cnt;
//}
//void move() {
//	for (int i = N; i >= 1; i--) 
//		for (int j = 1; j <= M; j++) 
//			m[i][j] = m[i - 1][j];
//}
//int ans = 0;
//void btk(int k) {
//	if (k == 3) {
//		
//		int killSum = 0;
//		while (1) {
//			//적 다 사라질 때까지
//			if (allKilled()) break;
//
//			for (int i = 0; i < 3; i++) {
//				bfs({ N + 1, arr[i] });
//				init();
//			}
//			killSum += kill();//죽은 적들 배열에서 제거
//		
//			move();	
//		}
//		if (ans < killSum) ans = killSum;
//		
//		for (int i = 1; i <= N; i++)
//			for (int j = 1; j <= M; j++)
//				m[i][j] = tmp[i][j];
//		return;
//	}
//	if (k == 0) st = 1;
//	for (int i = st; i <= M; i++) {
//		if (!isused[i]) {
//			arr[k] = i;
//			st = i;
//			isused[i] = true;
//			btk(k + 1);
//			isused[i] = false;
//		}
//	}
//}
//int main(void) {
//	cin >> N >> M >> d;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			cin >> m[i][j];
//			tmp[i][j] = m[i][j];
//		}
//	}
//
//	btk(0);
//	cout << ans;
//	return 0;
//}