#include<iostream>
#include<queue>
#include<math.h>
#include<vector>
using namespace std;
int N, L, R, m[51][51], bor[51][51];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

queue<pair<int, int> > q;
bool updated = false;
int idxCnt = 0, idxSum = 0;
vector<pair<int, int> > v;
void bfs(pair<int, int> start, int idx) {
	q.push(start);
	bor[start.first][start.second] = idx;
	
	v.clear();
	v.push_back({ start.first, start.second });
	idxCnt = 1;
	idxSum = m[start.first][start.second];

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N || bor[nr][nc] > 0)
				continue;
			if (abs(m[nr][nc] - m[cur.first][cur.second]) >= L &&
				abs(m[nr][nc] - m[cur.first][cur.second]) <= R) {
				q.push({ nr, nc });
				bor[nr][nc] = idx; //방문처리
				
				v.push_back({ nr, nc });
				//idxCnt++;
				idxSum += m[nr][nc];
				//mem[idx].cnt++;
				//mem[idx].Sum += m[nr][nc];
			}
		}
	}
}
void init() {
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			bor[i][j] = 0;
}
void Move(int idx) {
	for (int i = 1; i <= idx; i++) {
		int Sum = 0, cnt = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (bor[j][k] == i) {
					cnt++;
					Sum += m[j][k];
				}
			}
		}
		int val = Sum / cnt;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (bor[j][k] == i) {
					m[j][k] = val;
				}
			}
		}
	}
}
void Print() {
	cout << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << m[i][j] << ' ';
		}
		cout << '\n';
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> m[i][j];

	//1회 인구이동
	int res = 0;

	int idx = 0;
	
	while (1) {
		updated = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (bor[i][j] == 0) {
					idx++;
					bfs({ i, j }, idx);
				}
				//열린 국경이 있으면
				if (v.size() >= 2) {
					updated = true;
					//변화 반영
					int val = idxSum / v.size();
					for (int i = 0; i < v.size(); i++) {
						m[v[i].first][v[i].second] = val;
					}
				}
				Print();
			}
		}
		if (updated) res++;
		else break;
		init();
	}
	cout << res << '\n';
	return 0;
}
////여기서 불필요한 검색이 많이 일어남 -> 벡터에 미리 박아놓자
//for (int i = 1; i <= idx; i++) {
//	int val = mem[i].Sum / mem[i].cnt;
//	for (int j = 0; j < N; j++) {
//		for (int k = 0; k < N; k++) {
//			if (bor[j][k] == i) {
//				m[j][k] = val;
//			}
//		}
//	}
//}