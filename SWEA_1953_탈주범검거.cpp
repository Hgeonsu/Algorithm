#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;

int m[51][51], dis[51][51];
vector<vector<int> > dr = { {0,0,1,-1}, {1,-1}, {0,0}, {0, -1},{1, 0},{1,0}, {-1,0} }; //동서남북
vector<vector<int> > dc = { {1,-1,0,0}, {0,0}, {1,-1}, {1,0}, {0,1}, {0, -1}, {0,-1} };

queue<pii> q;

int r, c, mr, mc, Time; //m~ 맨홀 위치
int cnt = 0;

int findDir(int nr, int nc) {
	if (nr == 0 && nc == 1) return 1;
	else if (nr == 0 && nc == -1) return 2;
	else if (nr == 1 && nc == 0) return 3;
	else return 4;
}

bool dirCheck(int srcDir, int desIdx) {
	if (srcDir == 1) { //동쪽으로 이동중인 경우
		if (desIdx == 2 || desIdx == 4 || desIdx == 5) return false;
		else return true;
	}
	else if (srcDir == 2) { //서쪽으로 이동중인 경우
		if (desIdx == 2 || desIdx == 6 || desIdx == 7) return false;
		else return true;
	}
	else if (srcDir == 3) { //남쪽으로 이동중인 경우
		if (desIdx == 3 || desIdx == 5 || desIdx == 6) return false;
		else return true;
	}
	else { //북쪽으로 이동중인 경우
		if (desIdx == 3 || desIdx == 4 || desIdx == 7) return false;
		else return true;
	}
}

void bfs(pii st) {
	q.push(st);
	dis[st.first][st.second]++; //시작점 시간 1로
	cnt++;
	
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		if (dis[cur.first][cur.second] >= Time) return; //탈출조건

		int deltaIdx = m[cur.first][cur.second]; //1나오면 0으로 써야함(좌표 이동 벡터 인덱스)
		
		for (int i = 0; i < dr[deltaIdx - 1].size(); i++) {
			int nr = cur.first + dr[deltaIdx - 1][i];
			int nc = cur.second + dc[deltaIdx - 1][i];

			if (nr < 0 || nc < 0 || nr >= r || nc >= c || dis[nr][nc] >= 1) continue;
			if (m[nr][nc] == 0) continue;

			int curDir = findDir(dr[deltaIdx - 1][i], dc[deltaIdx - 1][i]); //어느 방향으로 이동중인지
			
			
			if (!dirCheck(curDir, m[nr][nc])) continue; //이동할 수 없는 방향

			q.push({ nr, nc });
			dis[nr][nc] = dis[cur.first][cur.second] + 1;

			cnt++;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		cin >> r >> c >> mr >> mc >> Time;
		
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> m[i][j]; 
		
		bfs({ mr, mc });
		
		printf("#%d %d\n", tc, cnt);

		//초기화
		cnt = 0;
		while (!q.empty()) q.pop();
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				dis[i][j] = 0;
	}
	return 0;
}

