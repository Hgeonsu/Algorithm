#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;

int pathA[101], pathB[101];

vector<pii> map[11][11];

const int dr[4] = { 0,0,1,-1 };
const int dc[4] = { 1,-1,0,0 };
struct BC {
	int r, c, range, pwr;
} bc[9];

queue<pii> q;
int dis[11][11];
void bfs(BC st, int num) {
	q.push({st.r, st.c});

	dis[st.r][st.c]++;
	map[st.r][st.c].push_back({ st.pwr, num});

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		if (dis[cur.first][cur.second] >= st.range) continue;
		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];
			if (dis[nr][nc] >= 0)continue;
			
			q.push({ nr, nc });
			dis[nr][nc] = dis[cur.first][cur.second] + 1;
			map[nr][nc].push_back({st.pwr, num});
		}
	}
}

bool cmp(pii a, pii b) { //������ �������� ����
	return a.first > b.first;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int moves, cnt;
		cin >> moves >> cnt;
		for (int i = 0; i < moves; i++) 
			cin >> pathA[i];
		for (int i = 0; i < moves; i++)
			cin >> pathB[i];
		
		for (int i = 0; i < cnt; i++) {
			cin >> bc[i].c >> bc[i].r >> bc[i].range >> bc[i].pwr;

			for (int i = 1; i <= 10; i++)
				for (int j = 1; j <= 10; j++)
					dis[i][j] = -1;
			bfs(bc[i], i); //���͸� ���� ���� �׸���
		}
		
		//������ ū �ͺ��� �������� ����
		for (int i = 1; i <= 10; i++)
			for (int j = 1; j <= 10; j++)
				if (map[i][j].size() > 1)
					sort(map[i][j].begin(), map[i][j].end(), cmp);

		
		int Sum = 0, ar = 1, ac = 1, br = 10, bc = 10; //a�� row, a�� col ...
		for (int i = 0; i <= moves; i++) {
			
			int difA = 0 , difB = 0; //������ ����
			
			if (map[ar][ac].size() >= 1 && map[br][bc].size() >= 1) {
				//�Ѵ� 1�� �̻� ���� ����
				int Max = -1;
				for (int k = 0; k < map[ar][ac].size(); k++) {
					difA = map[ar][ac][k].first;
					for (int p = 0; p < map[br][bc].size(); p++) {
						difB = map[br][bc][p].first;
						if (map[ar][ac][k].second == map[br][bc][p].second)
							difB = 0; //a���� ����� �� b������ ����ϴ� ���
						if (difA + difB > Max) Max = difA + difB;
					}
				}
				Sum += Max;
			}
			else if (map[ar][ac].size() == 0 && map[br][bc].size() > 0) 
				Sum += map[br][bc][0].first; //B�� ���� ������ �� ���

			else if (map[ar][ac].size() > 0 && map[br][bc].size() == 0)
				Sum += map[ar][ac][0].first; //A�� ���� ������ �� ��� 

			//printf("%d��  A = %d B = %d\n", i, difA, difB);

			if (i == moves) break; //n�� ���ķδ� ���ŵ��� �ʵ���


			//��ġ �̵�
			if (pathA[i] == 1)
				ar--;
			else if (pathA[i] == 2)
				ac++;
			else if (pathA[i] == 3)
				ar++;
			else if (pathA[i] == 4)
				ac--;

			if (pathB[i] == 1)
				br--;
			else if (pathB[i] == 2)
				bc++;
			else if (pathB[i] == 3)
				br++;
			else if (pathB[i] == 4)
				bc--;
		}

		cout << "#" << tc << ' ' << Sum << '\n';
		//map�ʱ�ȭ
		for (int i = 1; i <= 10; i++)
			for (int j = 1; j <= 10; j++)
				if (map[i][j].size() != 0)
					map[i][j].clear();
	}

	return 0;
}

