#include<iostream>
#include<algorithm>
#include<queue>
#pragma warning(disable:4996)
using namespace std;
int map[26][26], vis[26][26];
int N;
queue<pair<int, int> > q;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int res[625]; //���� 25�����ѵ�, 1�� �� ����Ʈ �ִ� �� �ִ�ϱ� ũ��[13 * 13][13 * 13]�ϵ� -> �ƴ� ��Ÿ�ӿ����� ����

int bfs(pair<int, int> start) {
	q.push(start);
	vis[start.first][start.second] = 1;
	int homeCnt = 1;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];

			//���� ����� continue
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)continue;
			if (map[nr][nc] == 0 || vis[nr][nc] == 1)continue; //���� �ƴϰų�, �湮������ continue

			q.push({ nr,nc });
			vis[nr][nc] = 1;
			homeCnt++;
		}
	}

	//for�� ��� ȸ�� return
	return homeCnt;
}

int main(void) {
	int time;
	time = 1;
	cin >> time;
	while (time > 0) {
		int cnt = 0; // ��ü ������ ��

		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &map[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1 && vis[i][j] == 0) {
					res[cnt] = bfs({ i, j }); //res ũ�� ���� �� ���� -> 
					cnt++;
				}
			}
		}
		
		//res �迭�� �� ������ ũ�� ����, cnt = ��ü ������ ����
		
		cout << cnt << '\n';
		sort(res, res + cnt);
		for (int i = 0; i < cnt; i++) {
			cout << res[i] << '\n';
		}

		//�ʱ�ȭ
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = 0;
				vis[i][j] = 0;
			}
		}
		//res�� ���� �������ϱ� �������
		time--;
	}
	return 0;
}