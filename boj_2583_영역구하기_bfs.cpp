#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int map[102][102]; //������ �ʱ�ȭ
int dis[102][102]; //���������� ������ �ʱ�ȭ
int res[102];
int cnt = 0;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = {1,-1,0,0};
int M, N;
queue<pair<int, int> > q;
int bfs(pair<int,int> start) {
	int finDis = 0;
	q.push(start);
	dis[start.first][start.second] = 1;
	finDis++;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dy[i];
			int nc = cur.second + dx[i];

			// �������� 1�̰ų�, ���������� continue
			if (nr < 0 || nr >= M || nc < 0 || nc >= N)continue;
			if (map[nr][nc] == 1)continue;
			if (dis[nr][nc] > 0)continue; //�湮�߾ ���

			//�������� 0�̸鼭 �湮 �� ���� ���� �Ʒ� ����
			q.push({ nr,nc });
			dis[nr][nc] = 1;
			finDis++;
			//printf("\n[%d][%d]���� = %d\n", nr, nc, finDis);
		}
	}
	return finDis;
}
int main(void) {
	int time; // ��� ������ ��
	//cin >> time;
	time = 1;
	while (time > 0) {
		
		cin >> M >> N;
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			int lx, ly, rx, ry;
			cin >> lx >> ly >> rx >> ry;
			int lux = lx, luy = ry;
			int rbx = rx, rby = ly;
			for (int j = M - luy; j <= M - 1 - rby; j++) {
				for (int p = lux; p <= rbx - 1; p++) {
					if(map[j][p] == 1)continue;
					//printf("\nmap[%d][%d] = 1", j, p);
					map[j][p] = 1;
				}
			}
		}
		/*printf("\n");
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d", map[i][j]);
			}
			printf("\n");
		}*/

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (dis[i][j] == 0 && map[i][j] == 0) {
					//�湮 ���߰�, ���� �󿡼� 0�̸�
					res[cnt] = bfs({ i, j });
					cnt++;
				}
			}
			//printf("\n");
		}
		
		cout << cnt << '\n';
		sort(res, res + cnt);
		for (int i = 0; i < cnt; i++) {
			cout << res[i] << ' ';
		}

		//�ʱ�ȭ
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = 0;
				dis[i][j] = 0;
			}
		}
		cnt = 0;
		time--;
	}
	return 0;
}