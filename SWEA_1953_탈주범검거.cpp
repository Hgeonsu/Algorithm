#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;

int m[51][51], dis[51][51];
vector<vector<int> > dr = { {0,0,1,-1}, {1,-1}, {0,0}, {0, -1},{1, 0},{1,0}, {-1,0} }; //��������
vector<vector<int> > dc = { {1,-1,0,0}, {0,0}, {1,-1}, {1,0}, {0,1}, {0, -1}, {0,-1} };

queue<pii> q;

int r, c, mr, mc, Time; //m~ ��Ȧ ��ġ
int cnt = 0;

int findDir(int nr, int nc) {
	if (nr == 0 && nc == 1) return 1;
	else if (nr == 0 && nc == -1) return 2;
	else if (nr == 1 && nc == 0) return 3;
	else return 4;
}

bool dirCheck(int srcDir, int desIdx) {
	if (srcDir == 1) { //�������� �̵����� ���
		if (desIdx == 2 || desIdx == 4 || desIdx == 5) return false;
		else return true;
	}
	else if (srcDir == 2) { //�������� �̵����� ���
		if (desIdx == 2 || desIdx == 6 || desIdx == 7) return false;
		else return true;
	}
	else if (srcDir == 3) { //�������� �̵����� ���
		if (desIdx == 3 || desIdx == 5 || desIdx == 6) return false;
		else return true;
	}
	else { //�������� �̵����� ���
		if (desIdx == 3 || desIdx == 4 || desIdx == 7) return false;
		else return true;
	}
}

void bfs(pii st) {
	q.push(st);
	dis[st.first][st.second]++; //������ �ð� 1��
	cnt++;
	
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		if (dis[cur.first][cur.second] >= Time) return; //Ż������

		int deltaIdx = m[cur.first][cur.second]; //1������ 0���� �����(��ǥ �̵� ���� �ε���)
		
		for (int i = 0; i < dr[deltaIdx - 1].size(); i++) {
			int nr = cur.first + dr[deltaIdx - 1][i];
			int nc = cur.second + dc[deltaIdx - 1][i];

			if (nr < 0 || nc < 0 || nr >= r || nc >= c || dis[nr][nc] >= 1) continue;
			if (m[nr][nc] == 0) continue;

			int curDir = findDir(dr[deltaIdx - 1][i], dc[deltaIdx - 1][i]); //��� �������� �̵�������
			
			
			if (!dirCheck(curDir, m[nr][nc])) continue; //�̵��� �� ���� ����

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

		//�ʱ�ȭ
		cnt = 0;
		while (!q.empty()) q.pop();
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				dis[i][j] = 0;
	}
	return 0;
}

