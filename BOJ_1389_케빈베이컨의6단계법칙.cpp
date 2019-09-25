#pragma warning(disable :4996)
#include<iostream>
#include<queue>
using namespace std;

int grp[101][101]; // 1-indexed
int n, m; //蜡历荐, 包拌荐
int dis[101]; //规巩贸府 + 芭府
queue<int> q;

void bfs(int st) {
	q.push(st);
	dis[st]++;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int cur = q.front();
			q.pop();
			for (int i = 1; i <= n; i++) {
				if (grp[cur][i] != 1 || dis[i] >= 0) continue;
				q.push(i);
				dis[i] = dis[cur] + 1;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int src, dst;
		cin >> src >> dst;
		grp[src][dst] = 1;
		grp[dst][src] = 1; //公规氢己
	}

	int Min = 100000000, ans;
	for (int i = 1; i <= n; i++) {
		for (int i = 1; i <= n; i++) //规巩贸府 硅凯 檬扁拳
			dis[i] = -1;
		bfs(i);
		int Sum = 0;
		for (int i = 1; i <= n; i++)
			Sum += dis[i];
		if (Sum < Min) {
			Min = Sum;
			ans = i;
		}
	}
	cout << ans;
	
	return 0;
}
