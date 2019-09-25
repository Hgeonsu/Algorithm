#pragma warning(disable :4996)
#include<iostream>
using namespace std;

int grp[1001][1001], n, m;
bool vis[1001];


void dfs(int cur) {
	for (int i = 1; i <= n; i++) {
		if (grp[cur][i] == 1 && !vis[i]) {
			vis[i] = true;
			dfs(i);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int src, dst;
		cin >> src >> dst;
		grp[src][dst] = 1;
	}

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			//printf("%d에서 실행\n", i);
			vis[i] = true;
			dfs(i);
			ret++;
		}
	}

	cout << ret;
	return 0;
}
