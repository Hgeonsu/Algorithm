#include<iostream>

using namespace std;

int grp[11][11]; //1-indexed
bool vis[11]; //�湮ó��
int n, m, Max = 1;

void dfs(int len, int cur) {
	vis[cur] = true;

	if (Max < len) Max = len;
	for (int i = 1; i <= n; i++) {
		if (grp[cur][i] == 1 && !vis[i])
			dfs(len + 1, i);
	}
	vis[cur] = false;
}

void initGrp() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			grp[i][j] = 0;
}

int main(void) {

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		
		cin >> n >> m;
		
		for (int i = 0; i < m; i++) {
			int src, dst;
			cin >> src >> dst;
			
			grp[src][dst] = 1;
			grp[dst][src] = 1;
			
		}

		for (int i = 1; i <= n; i++) 
			dfs(1, i); // i�� �������� ���� 
		
		printf("#%d %d\n", tc, Max);
		Max = 1;
		initGrp();
	}

	return 0;
}