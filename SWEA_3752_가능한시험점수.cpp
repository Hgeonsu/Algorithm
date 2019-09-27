#pragma warning(disable :4996)
#include<iostream>
#include<vector>
using namespace std;
bool vis[10001]; //최대 만점
int n;
vector<int> v;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> n;

		v.push_back(0);
		vis[0] = true;
		int val;
		for (int i = 0; i < n; i++) {
			cin >> val;
			int curSize = v.size(); //새로운 숫자 넣기 직전에 백터 크기
			for (int j = 0; j < curSize; j++) {
				int candi = val + v[j]; //추가될 수 있는 수
				if (!vis[candi]) { //이미 추가된 수면 pass
					v.push_back(candi);
					vis[candi] = true;
				}
			}
		}
		cout << '#' << tc << ' ' << v.size() << '\n';
		v.clear();
		for (int i = 0; i <= 10000; i++)
			vis[i] = false;
	}

	return 0;
}
