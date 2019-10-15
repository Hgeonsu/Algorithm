#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int dr[4] = { -1,1,0,0 };
const int dc[4] = { 0,0,-1,1 };

struct Info {
	int num;
	int dir; //상하좌우 1234
};

vector<Info> map[101][101];
vector<Info> tmp[101][101]; //이동할 때 사용
int n, Time, k;

bool cmp(Info a, Info b) {
	return a.num > b.num;
}
int main(void) {
	//setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n >> Time >> k;
		for (int i = 0; i < k; i++) {
			int r, c, cnt, dir;
			cin >> r >> c >> cnt >> dir;
			map[r][c].push_back({ cnt, dir });
		}


		for (int i = 0; i < Time; i++) {
			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					//이동
					if (map[i][j].size() != 0) {
						Info cur = map[i][j][0];

						int nr = i + dr[cur.dir - 1];
						int nc = j + dc[cur.dir - 1];

						if (nr == 0) {
							cur.dir = 2;
							cur.num /= 2;
						}
						else if (nr == n - 1) {
							cur.dir = 1;
							cur.num /= 2;
						}
						else if (nc == 0) {
							cur.dir = 4;
							cur.num /= 2;
						}
						else if (nc == n - 1) {
							cur.dir = 3;
							cur.num /= 2;
						}
						tmp[nr][nc].push_back({ cur.num, cur.dir });

						map[i][j].clear(); //초기화
					}

				}
			}

			//tmp에 들어있는 복수개 병합, 방향 설정
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (tmp[i][j].size() >= 2) {
						sort(tmp[i][j].begin(), tmp[i][j].end(), cmp);
						//개체수 내림차순

						int Sum = 0;
						for (int k = 0; k < tmp[i][j].size(); k++)
							Sum += tmp[i][j][k].num;

						Info merged = { Sum, tmp[i][j][0].dir }; //가장 많이 가진 것의 방향
						map[i][j].push_back(merged);
						tmp[i][j].clear(); //초기화
					}
					else if (tmp[i][j].size() == 1) {
						map[i][j].push_back(tmp[i][j][0]);
						tmp[i][j].clear(); //초기화
					}
				}
			}

		}

		int ans = 0;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				if (map[i][j].size() != 0) {
					ans += map[i][j][0].num;
					map[i][j].clear(); //초기화
				}
			
		cout << "#" << t << ' ' << ans << '\n';
	}

	
	return 0;
}
