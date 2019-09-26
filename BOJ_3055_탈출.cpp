#pragma warning(disable :4996)
#include<iostream>
#include<queue>

using namespace std;
typedef pair<int, int> pii;
const int dr[4] = { 0,0,1,-1 };
const int dc[4] = { 1,-1,0,0 };

int R, C;
char m[51][51];
int dis[51][51];

pii st;
queue<pii> q;
queue<pii> fldq;
bool fldVis[51][51];

void fldbfs() {
	int qs = fldq.size();
	while (qs--) { //한 번의 확산만 일어나도록
		pii cur = fldq.front();
		fldq.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];
			
			if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
			if (fldVis[nr][nc] || m[nr][nc] =='D' || m[nr][nc] == 'X') continue;
			m[nr][nc] = '*';
		}
	}
}

void flood() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!fldVis[i][j] && m[i][j] == '*') {
				fldq.push({ i, j }); //확산 지점들 미리 push
				fldVis[i][j] = true;
			}
		}
	}
	fldbfs();
}
void bfs() {
	q.push(st);
	dis[st.first][st.second]++;

	while (!q.empty()) {
		int qs = q.size();
		//물이동 먼저 하고, 길이 1만큼 이동하도록

		flood();
		while (qs--) {
			
			pii cur = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nr = cur.first + dr[i];
				int nc = cur.second + dc[i];
				if (nr < 0 || nc < 0 || nr >= R || nc >= C || dis[nr][nc] >= 0)
					continue;
				
				if (m[nr][nc] == '*' || m[nr][nc] == 'X') continue;
				
				q.push({ nr, nc });
				dis[nr][nc] = dis[cur.first][cur.second] + 1;
				
				if (m[nr][nc] == 'D') {
					cout << dis[nr][nc];
					return;
				}
			}
		}
	}
	
	cout << "KAKTUS";
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//*물, X돌, 비버굴D, 고슴도치S
	
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> m[i][j];
			dis[i][j] = -1;
			if (m[i][j] == 'S') {
				st.first = i;
				st.second = j;
			}
		}
	}

	bfs();
	
	return 0;
}

