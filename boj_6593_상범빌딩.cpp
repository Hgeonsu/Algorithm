#include<iostream>
#include<queue>
using namespace std;
char map[31][31][31]; //��,row, col
int vis[31][31][31];
int dr[6] = { 0,0,-1,1,0,0 }; // �������ϻ���
int dc[6] = { 1, -1, 0,0,0,0 };
int dh[6] = { 0,0,0,0,1,-1 };
int h, r, c;
pair<int, pair<int, int> > start;
pair<int, pair<int, int> > dest;
int time = 0;
bool done = false;

queue<pair<int, pair<int, int> > > q;

void bfs() {
	q.push(start);
	vis[start.first][start.second.first][start.second.second]++;
	while (!q.empty()) {
		pair<int, pair<int, int> > cur = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nh = cur.first + dh[i];
			int nr = cur.second.first + dr[i];
			int nc = cur.second.second + dc[i];

			if (nh < 0 || nr < 0 || nc < 0 || nh >= h || nr >= r || nc >= c)continue;
			if (vis[nh][nr][nc] > 0 || map[nh][nr][nc] == '#')continue;
		
			vis[nh][nr][nc] = vis[cur.first][cur.second.first][cur.second.second] + 1;
			q.push({ nh, {nr, nc} });
			if (nh == dest.first && nr == dest.second.first && nc == dest.second.second) {
				done = true;
				return;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//���ڷ� �ް� 6����
	
	while (1) {
		cin >> h >> r >> c;
		if (h == 0 && r == 0 && c == 0)
			break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S') {
						start = { i, {j, k} };
					}
					else if (map[i][j][k] == 'E') {
						dest = { i, {j, k} };
					}
				}
			}
		}
		bfs();

		if (done) {
			cout << "Escaped in " << vis[dest.first][dest.second.first][dest.second.second] - 1 << " minute(s).\n";
		}
		else {
			cout << "Trapped!\n";
		}
		//�ʱ�ȭ
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					vis[i][j][k] = 0;
					map[i][j][k] = NULL;
				}
			}
		}
		done = false;
		while (!q.empty()) {
			q.pop();
		}
	}

	return 0;
}
/*
�������� 6���e Ž��. queue�� ������ ����� �ʰ� bfs���� while���� Ż���ϱ� ������ �ʱ�ȭ ��ų �� queue�� ������ �ϴ� �� ����
*/