//��� ���� = 0, ������ ������ 1�� �ؼ� ���ο� map �ʿ�
//�ƹ� ������ ���� ����� ���� ���� ����
#include<iostream>
#include<queue>
using namespace std;

int N; //N*N ���
int map[101][101], fld[101][101], vis[101][101];
int hmax = -1;
int maxCnt = 0; //������ ���� ���� �ִ밪

queue<pair<int, int> > q;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0, };

void bfs(pair<int, int> start) {
	q.push(start);
	vis[start.first][start.second] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)continue;
			if (fld[nr][nc] == 0 || vis[nr][nc] == 1)continue;

			q.push({ nr, nc });
			vis[nr][nc] = 1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int time = 1; //TC ���� ���� ��
	//cin >> time;
	while (time > 0) {

		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (hmax < map[i][j]) {
					hmax = map[i][j];
				}
			}
		}
		//�� ���� 0 ~ hmax ���� ����, map[i][j] ���� ���ؼ� fld[i]][j]ä��� bfs �ؼ� ������ ���� ���� ã��
		for (int h = 0; h <= hmax; h++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (map[i][j] <= h) {
						fld[i][j] = 0; //��� �����̸� fld = 0
					}
					else {
						fld[i][j] = 1; //������ �����̸� fld = 1
					}
				}
			}

			//�������� fld �ϼ�

			int cnt = 0; //���� �� ������ ������ ����
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (fld[i][j] == 1 && vis[i][j] == 0) {
						bfs({ i, j });
						cnt++;
					}
				}
			}

			if (maxCnt < cnt) {
				maxCnt = cnt;
			}

			//vis �迭 �ʱ�ȭ �� �ؼ� ó���� ��� ����� �ȳ���
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					vis[i][j] = 0;
				}
			}
		}
		cout << maxCnt << '\n'; //��� ���

		//map, fld, vis�ʱ�ȭ
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = 0;
				fld[i][j] = 0;
				vis[i][j] = 0;
			}
		}
		hmax = -1;
		maxCnt = 0;
		time--;
	}
	return 0;
}