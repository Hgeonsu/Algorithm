
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

	if (cur.first == src.first && cur.second == src.second && cnt > 1) { //시작점으로 바로 되돌아가는 경우 방지
		if (Max < cnt) Max = cnt;
		return;
	}


	for (int i = 0; i < 2; i++) { //그대로 가거나 꺾거나

		if (dir + i >= 4) //이 이상 회전하는 것은 사각형이 아니다
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

				used[map[i][j]] = true; // 출발 숫자 사용처리
				//vis[i][j] = true; 시작지점 방문처리 하지 않음 나중에 다시 돌아와야 하니까

				//arr.push_back(map[i][j]); //어떤 노드를 방문했는지 디버깅하기 위한 용도 

				dfs({ i, j }, 0, 0); //좌표, 방향, 거쳐간 노드수, 방향전환횟수

				used[map[i][j]] = false;
				arr.clear();

			}
		}

		cout << "#" << tc << ' ' << Max << '\n';
		Max = -1;

	}
	return 0;
}

