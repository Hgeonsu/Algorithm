//���� ������ ���ϱ� ���� bfs,
//�� ������ �ٸ� �������� �Ÿ��� ���ϱ� ���� bfs
#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
int N;
int map[101][101], idx[101][101], dis[101][101];
queue<pair<int, int> > q;
int index = -1;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int Min = 999;
void bfs(pair<int, int> start) { //���� ���� ���ϴ� bfs
	q.push(start);
	idx[start.first][start.second] = index;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= N)continue;

			if (map[nr][nc] == 0 || idx[nr][nc] >= 0)continue; //�湮���� �ְų� ������ �ƴϸ� continue;

			q.push({ nr, nc });
			idx[nr][nc] = index;
		}

	}
}

void bfsDis() {

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= N)continue;
			if (idx[nr][nc] == idx[cur.first][cur.second]) continue; //���� ���̸� �Ÿ� ����� continue
			if (dis[nr][nc] < 0 && idx[nr][nc] < 0) {
				//�Ÿ��� ������ ���� �ʾ����鼭 �ٴ��� ���
				dis[nr][nc] = dis[cur.first][cur.second] + 1; //�湮ó��(�Ÿ�����)
				q.push({ nr,nc });
				idx[nr][nc] = idx[cur.first][cur.second]; //dis�迭�� ����, ��� �����κ��� ������ ���� �˾ƾ��ϱ� ������ idx ���� ���� �ٲ���
			}
			if (dis[nr][nc] > 0 && idx[cur.first][cur.second] != idx[nr][nc]) { //�ٸ� �����κ��� �Ÿ��� ������ ������ ���� ���
				if (Min > dis[nr][nc] + dis[cur.first][cur.second]) {
					Min = dis[nr][nc] + dis[cur.first][cur.second];

				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			idx[i][j] = -1;
			if (map[i][j] == 0) {
				dis[i][j] = -1; //�ٴ��� ��� dis �� -1�� �ʱ�ȭ
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && idx[i][j] < 0) {
				//�� index �Ҵ� �ȵȰŸ� �湮 ���ѰŴϱ�
				index++; //index�� ���� �ʱ�ȭ �س��Ŀ� ���� ������ �ٸ�
				bfs({ i,j });
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (idx[i][j] >= 0) {
				q.push({ i, j });
				dis[i][j] = 0; //�̹� 0���� �ʱ�ȭ �Ǿ��ֱ� ��
			}
		}
	}
	bfsDis();

	cout << Min << '\n';

}
