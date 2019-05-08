#include<iostream>
#include<queue>
using namespace std;

int map[1001][1001], vis[1001][1001];
int M, N; //N = row, M = col
int day = 0;

queue<pair<int, int> > q;

int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0, };

bool updated = false;

void bfs() {
	while (!q.empty()) {
		int size = q.size();
		
		//ť�� ũ�⸸ŭ pop �ؼ� �ֺ� Ȯ��
		for (int i = 0; i < size; i++) {
			pair<int, int> cur = q.front();
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nr = cur.first + dr[j];
				int nc = cur.second + dc[j];

				//���� ����� continue
				if (nr < 0 || nc < 0 || nr >= N || nc >= M)continue;
				if (map[nr][nc] == -1)continue; //�丶�� ������ ���
				if (vis[nr][nc] == 1)continue; // �̹� �ֺ� �丶�並 ���� ��ġ�� �丶��� ���
				
				map[nr][nc] = 1;
				q.push({ nr,nc });
				vis[nr][nc] = 1;
				updated = true;
			}
		}
		if (updated) { //���Ӱ� ���� �丶�䰡 ������
			day++;
			updated = false;
		}
		else { // ���� �� �ִ� �丶�並 �� ���� ���
			return;
		}
	}
}

int main(void) {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) { //���ÿ� ���� ��ǥ���� bfs ������ �� idiom
				q.push({ i,j });
				vis[i][j] = 1;
			}
		}
	}
	
	bfs();

	//�� ���� �丶�䰡 ���� ���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				day = -1;
			}
		}
	}

	cout << day << '\n';
	return 0;
}