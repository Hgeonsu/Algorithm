
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;

int map[11][11], n, m, c;

bool cmp(int a, int b) {
	return a > b;
}

struct Info {
	pii pos;
	int pft;
};

bool cmpCandi(Info a, Info b) {
	return a.pft > b.pft;
}


bool vis[11];
vector<int> arr;

int tmpMax = -1;
void dfs(int k, int Sum, int bef, vector<int>& tmp) {
	if (Sum >= c || k == m) {
		//최대이윤인지 확인
		
		bool reduce = false;
		if (Sum > c) { //수집 가능한 양을 초과했으면 직전 수집 양을 감소 시켜줘야함
			Sum -= bef;
			reduce = true; //종료 조건에서 arr벡터 pop을 해주면 다른 부분에서 중복 pop이 되기 때문에 이렇게 처리함
		}

		int Size = arr.size();
		if (reduce) Size--; //하나 덜 검사하도록 처리

		int tmpPft = 0;
		for (int i = 0; i < Size; i++)
			tmpPft = tmpPft + arr[i] * arr[i];

		if (tmpMax < tmpPft) tmpMax = tmpPft; //최대 이윤 갱신
		return;
	}


	for (int i = 0; i < tmp.size(); i++) {
		if (vis[i]) continue;
		vis[i] = true;
		
		arr.push_back(tmp[i]);
		
		dfs(k+1, Sum+tmp[i], tmp[i], tmp);
		vis[i] = false;
		arr.pop_back();
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> m >> c;
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];

		vector<Info> candi; //시작지점, 가능 꿀

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n-m; j++) {
				//시작점 i행j열
				vector<int> tmp;
				for (int k = j; k < j + m; k++) 
					tmp.push_back(map[i][k]); //꿀 후보 추가
				
				//최대 이윤내는 꿀 골라서 이윤 계산

				tmpMax = -1;
		
				dfs(0, 0, 0, tmp); //인덱스, 합, 이전까지합,

				Info tmpInfo;
				tmpInfo.pos = { i, j };
				tmpInfo.pft = tmpMax;
				candi.push_back(tmpInfo); //시작지점, 이익 push
				
				tmp.clear();
			}
		}

		sort(candi.begin(), candi.end(), cmpCandi);

		int Max = -1;
		for (int i = 0; i < candi.size(); i++) {
			for (int j = i + 1; j < candi.size(); j++) {
				if (candi[i].pos.first == candi[j].pos.first) { //같은 칸에서 두명이 채집한 경우 pass
					if (candi[j].pos.second <= candi[i].pos.second + m - 1 ||
						candi[i].pos.second <= candi[j].pos.second + m - 1) continue;
				}
				if (candi[i].pft + candi[j].pft > Max) Max = candi[i].pft + candi[j].pft;

			}
		}

		printf("#%d %d\n", tc, Max);
		candi.clear();
	}
	
	return 0;
}

