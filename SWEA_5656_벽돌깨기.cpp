#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int n, w, h, org[17][17], map[17][17], Min = 987654321;
bool vis[17][17];
struct Info {
	pii pos;
	int dis;
};

const int dr[4] = { 0,0,1,-1 };
const int dc[4] = { 1,-1,0,0 };
queue<Info> bomb;

vector<int> dropCol;

queue<pii> emp;

bool allZero() {
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] != 0) return false;
		}
	}
	return true;
}
void pick(int k) {
	if (k == n) {

		for (int i = 0; i < dropCol.size(); i++) {
			int c = dropCol[i];
			for (int r = 0; r < h; r++) {
				//구슬투하하고 터트리고 칸맞추고
				if (map[r][c] == 1 ) {
					map[r][c] = 0;
					break;
				}
				else if (map[r][c] > 1) {
					bomb.push({ { r, c }, map[r][c] });
					vis[r][c] = true;

					while (!bomb.empty()) {
						Info cur = bomb.front();
						bomb.pop();
						int dis = cur.dis;
						map[cur.pos.first][cur.pos.second] = 0;

						//4방향
						for (int j = 1; j < dis; j++) {
							for (int m = 0; m < 4; m++) {
								int nr = cur.pos.first + dr[m] * j;
								int nc = cur.pos.second + dc[m] * j;
								
								if (nr < 0 || nc < 0 || nr >= h || nc >= w) continue;
								if (map[nr][nc] == 0 || vis[nr][nc]) continue;
								if (map[nr][nc] >= 1) bomb.push({ { nr, nc }, map[nr][nc]});
								else map[nr][nc] = 0;
								vis[nr][nc] = true;
							}
						}
						
					}

					for (int i = 0; i < h; i++)
						for (int j = 0; j < w; j++)
							vis[i][j] = false;

					break;
				}
				
			}
			
			if (allZero()) {
				Min = 0;
				return;
			}
			
			//중력 처리
			for (int allCol = 0; allCol < w; allCol++) {
				for (int r = h - 1; r >= 0; r--) {
					if (map[r][allCol] == 0) {
						emp.push({ r, allCol });
					}
					else {
						if (emp.empty()) continue;
						pii dst = emp.front();
						emp.pop();
						map[dst.first][dst.second] = map[r][allCol];
						map[r][allCol] = 0;
						emp.push({ r, allCol });
					}
				}
				while (!emp.empty()) emp.pop();
				
			}
			
		}
		

		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] != 0) cnt++;
				map[i][j] = org[i][j];
			}
		}
		if (Min > cnt) Min = cnt;
	
		return;
	}

	if (Min == 0) return;
	for (int i = 0; i < w; i++) {
		dropCol.push_back(i);
		pick(k + 1);
		dropCol.pop_back();
	}
}

int main(void) {
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		cin >> n >> w >> h;
		for (int i = 0; i < h; i++) 
			for (int j = 0; j < w; j++) {
				cin >> org[i][j];
				map[i][j] = org[i][j];
			}
		
		//cout << '\n';
		//0~w-1까지 수중에 n개 중복 허용하고 고르기 (순서 상관 X)
		pick(0);
		
		cout << "#" << tc << ' ' << Min << '\n';
		Min = 987654321;

	}
	return 0;
}
