#include<iostream>
#include<queue>
using namespace std;
int dis[300][300];
queue<pair<int, int> >q;
int dr[8] = { -2, -1, 1, 2, 2, 1, -1, -2 }; // ����Ʈ ���� �ѽú��� CW
int dc[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int l; //ü���� ����
int desx, desy;
void bfs(pair<int, int> start) {

	q.push(start);
	dis[start.first][start.second]++; 
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		
		for (int i = 0; i < 8; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i]; //����Ʈ�� ������ �� �ִ� ����� ��

			//ü���� ������ ������ continue
			if (nr < 0 || nr >= l || nc < 0 || nc >= l)continue;
			if (dis[nr][nc] >= 0)continue; //dis �迭 ���� 0�̻��̸� �湮�� ���� �ִ� ��
			q.push({ nr, nc });
			dis[nr][nc] = dis[cur.first][cur.second] + 1;
			if (nr == desx && nc == desy)
				return;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int time;
	cin >> time;

	while (time > 0) {

		cin >> l;
		int startx, starty;
		cin >> startx >> starty;
		cin >> desx >> desy;

		//dis �迭 �ʱ�ȭ
		for (int i = 0; i < 300; i++) {
			for (int j = 0; j < 300; j++) {
				dis[i][j] = -1;
			}
		}

		//queue �ʱ�ȭ
		while (!q.empty()) {
			q.pop();
		}
		
		bfs({ startx, starty });

		//���
		cout << dis[desx][desy] <<'\n';
		
		time--;
	}
	return 0;
}