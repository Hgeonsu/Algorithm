#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;

int map[13][13], n;
bool con[13];
vector<pii> v;

int pwrCnt = 0, st = 0;


pii makeWire(pii pos, int dir) { //동서남북 0123
	int len = 0;

	if (dir == 0) {
		for (int j = pos.second + 1; j < n; j++) {
			if (map[pos.first][j] != 0)
				return {0, 0};
		}
		for (int j = pos.second + 1; j < n; j++) {
			map[pos.first][j] = 1;
			len++;
		}
		
	}
	else if (dir == 1) {
		for (int j = pos.second - 1; j >= 0; j--) {
			if(map[pos.first][j] != 0)
				return { 0, 0 };
		}
		for (int j = pos.second - 1; j >= 0; j--) {
			map[pos.first][j] = 1;
			len++;
		}
	}
	else if (dir == 2) {
		for (int i = pos.first + 1; i < n; i++) {
			if (map[i][pos.second] != 0)
				return { 0, 0 };
		}
		for (int i = pos.first + 1; i < n; i++) {
			map[i][pos.second] = 1;
			len++;
		}
		
	}
	else {
		for (int i = pos.first -1 ; i >= 0; i--) {
			if (map[i][pos.second] != 0)
				return { 0, 0 };
		}
		for (int i = pos.first - 1; i >= 0; i--) {
			map[i][pos.second] = 1;
			len++;
		}
	}

	return {1, len};
}

void removeWire(pii pos, int dir) {
	if (dir == 0) 
		for (int j = pos.second + 1; j < n; j++)
			map[pos.first][j] = 0;

	else if (dir == 1) 
		for (int j = pos.second - 1; j >= 0; j--)
			map[pos.first][j] = 0;
			
	else if (dir == 2) 
		for (int i = pos.first + 1; i < n; i++) 
			map[i][pos.second] = 0;
		
	else 	
		for (int i = pos.first - 1; i >= 0; i--) 
			map[i][pos.second] = 0;
			
}

int tot = 0;
int Max = 0;
bool neverChosen = true;
vector<int> lenCandi;
void dfs(int k, int conCnt) {
	if (k == (int)v.size()) {
		
		if (Max < conCnt) {
			Max = conCnt;
			lenCandi.clear();
			lenCandi.push_back(tot);
		}
		else if (Max == conCnt) 
			lenCandi.push_back(tot);
		
		return;
	}

	//지금까지 연결한것 + 앞으로 연결할 수 있는거 < Max라면 할 필요가없음
	if (conCnt + (v.size() - k) < Max) return;

	if (k == 0) st = 0;
	for (int i = st; i < v.size(); i++) {
		if (con[i]) continue;
		neverChosen = true;
		for (int j = 0; j < 4; j++) {
			pii res = makeWire(v[i], j);
			
			if (res.first == 1) { //연결가능
				neverChosen = false;
				con[i] = true;
			//	printf("%d 연결됨 %d쪽 깊이 %d\n", i, j, k);
				tot += res.second; //길이
				st = i;
				dfs(k + 1, conCnt+1);
				removeWire(v[i], j);
				con[i] = false;
				tot -= res.second;
			}
			
			if (j == 3 && neverChosen) { //4방으로 모두 연결할수 없는 지점
				st = i;
				dfs(k + 1, conCnt);
			}

		}
	}
}

int main(void) {
	//setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					if (i == 0 || j == 0)
						pwrCnt++; //자동 전원 연결 상태
					else
						v.push_back({ i, j });
				}
			}
		}

		dfs(0, 0);

		sort(lenCandi.begin(), lenCandi.end());
		if (lenCandi.size() == 0) lenCandi.push_back(0);
		cout << "#" << t << ' ' << lenCandi[0] << '\n';
		//초기화
		v.clear();
		pwrCnt = 0;
		tot = 0;
		Max = 0;
		lenCandi.clear();
		neverChosen = true;
	}

	return 0;
}
