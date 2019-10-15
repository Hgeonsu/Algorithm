
#include<iostream>
#include<vector>
using namespace std;

typedef pair<int, int> pii;
const int dr[4] = { 1, 1, -1, -1 };
const int dc[4] = { 1, -1, -1, 1 };
int n, map[21][21];
bool vis[21][21], used[101];

pii src;
vector<int> arr;
int Max = -1;
void dfs(pii cur, int dir, int cnt) {

	if (cur.first == src.first && cur.second == src.second && cnt > 1) { //���������� �ٷ� �ǵ��ư��� ��� ����
		if (Max < cnt) Max = cnt;
		return;
	}


	for (int i = 0; i < 2; i++) { //�״�� ���ų� ���ų�

		if (dir + i >= 4) //�� �̻� ȸ���ϴ� ���� �簢���� �ƴϴ�
			break;

		int nr = cur.first + dr[dir + i];
		int nc = cur.second + dc[dir + i];
	
		if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;

		if (!vis[nr][nc] && !used[map[nr][nc]]) {

			used[map[nr][nc]] = true;
			//arr.push_back(map[nr][nc]);
			dfs({ nr, nc }, dir + i, cnt + 1);
			//arr.pop_back();
			vis[nr][nc] = false;
			used[map[nr][nc]] = false;

		}
		else if (nr == src.first && nc == src.second)
			dfs({ nr, nc }, dir + i, cnt + 1);
	}
}

int main(void) {
	//	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];

		//cout << '\n';

		for (int i = 0; i < n - 1; i++) {
			for (int j = 1; j < n - 1; j++) {
				src.first = i;
				src.second = j;

				used[map[i][j]] = true; // ��� ���� ���ó��
				//vis[i][j] = true; �������� �湮ó�� ���� ���� ���߿� �ٽ� ���ƿ;� �ϴϱ�

				//arr.push_back(map[i][j]); //� ��带 �湮�ߴ��� ������ϱ� ���� �뵵 

				dfs({ i, j }, 0, 0); //��ǥ, ����, ���İ� ����, ������ȯȽ��

				used[map[i][j]] = false;
				arr.clear();

			}
		}

		cout << "#" << tc << ' ' << Max << '\n';
		Max = -1;

	}
	return 0;
}

