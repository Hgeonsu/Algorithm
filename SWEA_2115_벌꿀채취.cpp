
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
		//�ִ��������� Ȯ��
		
		bool reduce = false;
		if (Sum > c) { //���� ������ ���� �ʰ������� ���� ���� ���� ���� ���������
			Sum -= bef;
			reduce = true; //���� ���ǿ��� arr���� pop�� ���ָ� �ٸ� �κп��� �ߺ� pop�� �Ǳ� ������ �̷��� ó����
		}

		int Size = arr.size();
		if (reduce) Size--; //�ϳ� �� �˻��ϵ��� ó��

		int tmpPft = 0;
		for (int i = 0; i < Size; i++)
			tmpPft = tmpPft + arr[i] * arr[i];

		if (tmpMax < tmpPft) tmpMax = tmpPft; //�ִ� ���� ����
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

		vector<Info> candi; //��������, ���� ��

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n-m; j++) {
				//������ i��j��
				vector<int> tmp;
				for (int k = j; k < j + m; k++) 
					tmp.push_back(map[i][k]); //�� �ĺ� �߰�
				
				//�ִ� �������� �� ��� ���� ���

				tmpMax = -1;
		
				dfs(0, 0, 0, tmp); //�ε���, ��, ����������,

				Info tmpInfo;
				tmpInfo.pos = { i, j };
				tmpInfo.pft = tmpMax;
				candi.push_back(tmpInfo); //��������, ���� push
				
				tmp.clear();
			}
		}

		sort(candi.begin(), candi.end(), cmpCandi);

		int Max = -1;
		for (int i = 0; i < candi.size(); i++) {
			for (int j = i + 1; j < candi.size(); j++) {
				if (candi[i].pos.first == candi[j].pos.first) { //���� ĭ���� �θ��� ä���� ��� pass
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

