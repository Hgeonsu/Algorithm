#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define INF 987654321

using namespace std;
typedef pair<int, int> pii;
struct Person {
	int idx;
	int dis0, dis1;
	pii pos;
};

int n, map[11][11]; //i번 사람의 j번 계단까지 소요시간
vector<pii> stair; //계단 위치
vector<Person> people;

int pickedStair[11]; //i번째 사람이 고른 계단
int Min = INF;
int d[11];

bool cmp0(Person a, Person b) {
	return a.dis0 < b.dis0;
}

bool cmp1(Person a, Person b) {
	return a.dis1 < b.dis1;
}
void dfs(int k) {
	if (k == (int)people.size()) {
	
		vector<Person> use0, use1; //~번 계단 사용하는 사람들

		for (int i = 0; i < k; i++) {
			if (pickedStair[i] == 0) use0.push_back(people[i]);
			else use1.push_back(people[i]);
		}

		
		//0번부터
		sort(use0.begin(), use0.end(), cmp0);
		for (int i = 0; i < use0.size(); i++) {
			if (i < 3) //세명 이하라면 입구 도착 시간 + 계단 내려가는 시간
				d[i] = use0[i].dis0 + map[stair[0].first][stair[0].second];
			
			else { 
				//if가 계단 꽉차서 기다려야 하는 경우
				if (use0[i].dis0 < d[i - 3]) d[i] = d[i - 3] + map[stair[0].first][stair[0].second];
				else //도착하자마자 계단에 들어갈 수 있는 경우
					d[i] = use0[i].dis0 + map[stair[0].first][stair[0].second];
			}
		}

		int time0 = d[use0.size() - 1] + 1;
		
		for (int i = 0; i < use0.size(); i++)
			d[i] = 0;


		//1번
		sort(use1.begin(), use1.end(), cmp1);

		for (int i = 0; i < use1.size(); i++) {
			if (i < 3) 
				d[i] = use1[i].dis1 + map[stair[1].first][stair[1].second];
			
			else {
				if (use1[i].dis1 < d[i - 3]) d[i] = d[i - 3] + map[stair[1].first][stair[1].second];
				else
					d[i] = use1[i].dis1 + map[stair[1].first][stair[1].second];
			}
		}

		int time1 = d[use1.size() - 1] + 1; //대기 시간 추가

		for (int i = 0; i < use1.size(); i++)
			d[i] = 0;

		int tmp = max(time0, time1);
		if (tmp < Min) Min = tmp;
		
		//초기화
		use0.clear();
		use1.clear();
		return;
	}

	for (int i = 0; i < 2; i++) {
		pickedStair[k] = i;
		dfs(k + 1);
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
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] > 1) stair.push_back({ i, j }); //계단 추가
				else if (map[i][j] == 1) {
					people.push_back({ cnt,0,0, {i, j} }); //사람 추가
					cnt++;
				}
			}
		}

		//모든 사람의 계단까지 이동 시간
		for (int i = 0; i < people.size(); i++) {
			for (int j = 0; j < 2; j++) {
				if (j == 0)
					people[i].dis0 = abs(people[i].pos.first - stair[j].first) +
					abs(people[i].pos.second - stair[j].second);
				else
					people[i].dis1 = abs(people[i].pos.first - stair[j].first) +
					abs(people[i].pos.second - stair[j].second);
			}
		}
		
	
		dfs(0);

		cout << "#" << t << ' ' << Min << '\n';

		//초기화
		Min = INF;
		people.clear();
		stair.clear();
	}

	return 0;
}
