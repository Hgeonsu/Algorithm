#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll grd[11][11];
int igr[11][11], n, m, k;
vector<ll> v[11][11];
int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int main(void) {
	//1-indexed
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> igr[i][j];
			grd[i][j] = 5;
		}
	}
	for (int i = 1; i <= m; i++) {
		int r, c, age;
		cin >> r >> c >> age;
		v[r][c].push_back(age);
	}
	for (int i = 1; i <= k; i++) {
		//봄
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				vector<ll> tmp;
				if (v[i][j].size() > 0) { //i행 j열에 나무가 존재하면
					sort(v[i][j].begin(), v[i][j].end()); //어린 나무부터
					//땅양분이 나이보다 많으면 나이 증가, 땅 양분 감소
					ll dead = 0;
					for (int t = 0; t < v[i][j].size(); t++) {
						if (v[i][j][t] <= grd[i][j]) {
							tmp.push_back(v[i][j][t] + 1);
							grd[i][j] -= v[i][j][t];
						}
						else {
							dead += v[i][j][t];
						}
					}
					//여름
					v[i][j].clear();
					v[i][j] = tmp;
					grd[i][j] += dead / 2;
				}
			}
		}

		//가을
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (v[i][j].size() > 0) {
					for (int t = 0; t < v[i][j].size(); t++) {
						if (v[i][j][t] % 5 == 0) {
							for (int ii = 0; ii < 8; ii++) {
								int nr = i + dr[ii];
								int nc = j + dc[ii];
								if (nr < 1 || nc < 1 || nr > n || nc > n) continue;
								v[nr][nc].push_back(1);
							}
						}
					}
				}
			}
		}

		//겨울
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				grd[i][j] += igr[i][j];
			}
		}
	}
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i][j].size() > 0) cnt += v[i][j].size();
		}
	}
	cout << cnt;
	return 0;
}
