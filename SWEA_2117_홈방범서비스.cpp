#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
const int dr[4] = { 0,0,1,-1 };
const int dc[4] = { 1,-1,0,0 };
int oprFee[43], n, pay, map[21][21], dis[21][21];
queue<pii> q;


//큐, dis[][] 초기화
void initVis() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dis[i][j] = 0;

	while (!q.empty()) q.pop();
}

int bfs(pii st, int k) {
	int homeCnt = 0;
	
	q.push(st);
	dis[st.first][st.second]++;
	if (map[st.first][st.second] == 1) homeCnt++;
	

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		if (dis[cur.first][cur.second] == k) return homeCnt; //검색 종료

		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= n || dis[nr][nc] > 0) continue;

			q.push({ nr, nc });
			dis[nr][nc] = dis[cur.first][cur.second] + 1;
			if (map[nr][nc] == 1) homeCnt++;
			
		}
	}
	return -1;
}

bool cont() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dis[i][j] == 0 && map[i][j] == 1) return true;
		}
	}
	return false;
}

int main(void) {
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	//크기별 운용비용 미리 계산
	for (int i = 1; i <= 42; i++)
		oprFee[i] = i * i + (i - 1) * (i - 1);

	for (int t = 1; t <= T; t++) {
		int totalHome = 0;
		cin >> n >> pay;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) totalHome++;
			}

		int Max = 0; 
		int maxPay = totalHome * pay;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 1; k < 43; k++) {

					int retHome = bfs({ i, j }, k);

					//계산
					if (retHome * pay - oprFee[k] >= 0)
						if (retHome > Max) Max = retHome;

					//최대로 벌수있는 돈보다 운용 비용이 더 많이들면 break
					if (maxPay < oprFee[k]) {
						initVis();
						break;
					}

					initVis();
				}
			}
		}

		cout << "#" << t << ' ' << Max << '\n';
	}


	return 0;
}
