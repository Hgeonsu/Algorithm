#include<iostream>
#include<queue>
#define INF 987654321

using namespace std;
typedef pair<int, int> pii;
const int dr[4] = { 0,0,1,-1 };
const int dc[4] = { 1,-1,0,0 };

struct Info{
	int isl = -1;
	int val = 0;
};

struct Bridge {
	int src, dst, len;
};

vector<Bridge> v;

Info m[101][101];
int R, C, islCnt = 0;

queue<pii> q;
bool vis[101][101];

int brg[7][7]; //�ٸ� ���� ����

int st = 0;
bool used[40];
int arr[100]; //�̴´ٸ�
int ans = INF;

bool vis2[7];

int map[7][7];

queue<int> q2;

void bfs(pii st) { //�� ��ȣ �ű�� �뵵
	q.push(st);
	vis[st.first][st.second] = true;
	m[st.first][st.second].isl = islCnt;
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];
			
			if (nr < 0 || nc < 0 || nr >= R || nc >= C || vis[nr][nc]) continue;
			if (m[nr][nc].val == 0) continue;
			
			q.push({ nr, nc });
			vis[nr][nc] = true;
			m[nr][nc].isl = islCnt;
		}
	}
}

void bfsCon(int st) { //�ٸ� ����� �� ���� ���� Ȯ��
	q2.push(st);
	vis2[st] = true;
	while (!q2.empty()) {
		int cur = q2.front();
		q2.pop();
		for (int i = 0; i < islCnt; i++) {
			if (map[cur][i] == 0) 
				continue;
			if (vis2[i]) 
				continue;
			q2.push(i);
			vis2[i] = true;
			
		}
	}
}

void btk(int k, int goal) {
	if (k == goal) {
	
		int len = 0;
		for (int i = 0; i < k; i++) {
			Bridge b = v[arr[i]];
			map[b.src][b.dst] = b.len;
			map[b.dst][b.src] = b.len;
			len += b.len;
		}

	
		bool isBreak = false;
		for (int i = 0; i < islCnt; i++) {
			for (int j = 0; j < islCnt; j++) {
				if (i == j) continue;
				if (map[i][j] != 0) {
					bfsCon(i);
					isBreak = true;
					break;
				}

			}
			if (isBreak) break; //���� ���� Ȯ���� �� �� ����
		}
		
		bool suc = true;
		for (int i = 0; i < islCnt; i++) {
			if (!vis2[i]) //����
				suc = false;

			vis2[i] = false; //�ʱ�ȭ
			for (int j = 0; j < islCnt; j++) 
				map[i][j] = 0;
			
		}

		if (suc) 
			if (ans > len) ans = len;
			
		return;
	}

	if (k == 0) st = 0;
	for (int i = st; i < v.size(); i++) {
		if (!used[i]) {
			st = i;
			used[i] = true;
			arr[k] = i;
			btk(k + 1, goal);
			used[i] = false;
		}
	}
}

int main(void) {
	//setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//���̳����� �� ������ ���� 2 �̻��� �ٸ��� ���ᰡ���� �� ã�Ƽ�
	//�� ���� ���� ������ ������ �� �ִ� ���� �߰�
	//v[k].pushback n  -> k�� ������ n������ �� �� �ִ�. ���� ������
	
	cin >> R >> C;
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) 
			cin >> m[i][j].val;
		
	

	//�� ��ȣ �ο�
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++) 
			if (m[i][j].val == 1 && !vis[i][j]) {
				bfs({ i, j });
				islCnt++;
			}
		
	//�ٸ� ���� ���Ѵ�� �ʱ�ȭ
	for (int i = 0; i < islCnt; i++) 
		for (int j = 0; j < islCnt; j++) 
			brg[i][j] = INF;
		
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (m[i][j].val == 0) continue;
			//�ٴٴ� pass
			
			for (int k = 0; k < 4; k++) { //4�������� �ٸ� ������
				//���� ����� �ٸ� ���
				// 1�̸鼭 ���� �ٸ� ���̾�� �ٸ��� �߰�

				for (int p = 1; p < 101; p++) {
					int nr = i + dr[k] * p;
					int nc = j + dc[k] * p;
					if (nr < 0 || nc < 0 || nr >= R || nc >= C || (m[nr][nc].isl == m[i][j].isl)) break;
					if (m[nr][nc].val == 1 && p <= 2) break; //���� 1 ������ �ٸ�
					if (m[nr][nc].val == 1 && (m[nr][nc].isl != m[i][j].isl) && p >= 3) {
						//p-1�� �ٸ�����
						if (brg[m[nr][nc].isl][m[i][j].isl] > p - 1) {
							brg[m[nr][nc].isl][m[i][j].isl] = p - 1;
							brg[m[i][j].isl][m[nr][nc].isl] = p - 1;
						}
						break;
					}
				}
			}
		}
	}

	
	for (int i = 0; i < islCnt; i++) 
		for (int j = i; j < islCnt; j++) 
			if (brg[i][j] != INF) 
				v.push_back({ i, j, brg[i][j]}); //�ٸ� ����
	
	for (int i = islCnt - 1; i <= v.size(); i++) //�ּ� ������-1���� �ٸ��� ���� or ��� �ٸ� ���
		btk(0, i);
	

	if (ans == INF) cout << -1;
	else cout << ans;

	return 0;
}
