#pragma warning(disable :4996)
#include<iostream>
#include<string>

using namespace std;

string org, tmp;
int n; //n번 스왑
int Max;
void dfs(int here, int cnt) { //인덱스 here과 바꿀곳 검색
	if (cnt == n) {
		int candi = stoi(org);
		if (Max < candi) Max = candi;

		return;
	}
	
	for (int i = here; i < org.length(); i++) {
		for (int j = i + 1; j < org.length(); j++) {
			if (org[i] <= org[j]) {
				int temp = org[i];
				org[i] = org[j];
				org[j] = temp;
				
				dfs(i, cnt + 1);

				temp = org[i];
				org[i] = org[j];
				org[j] = temp;
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> org >> n;
		Max = stoi(org);
		dfs(0, 0);
		cout << '#'<<tc<< ' ' << Max << '\n';
	}
	return 0;
}

