#pragma warning(disable :4996)
#include<iostream>
#include<queue>
using namespace std;

int grp[101][101]; //1-indexed
int vis[101]; //양수면 방문한 것
queue<int> q;

int n, st, en, m; //n명의 사람, m개의 관계

void bfs() {
	q.push(st);
	vis[st]++;
	
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int cur = q.front();
			q.pop();
			for (int i = 1; i <= n; i++) {
				if (grp[cur][i] != 1 || vis[i] >= 0) continue;
				
				q.push(i);
				vis[i] = vis[cur] + 1;
				if (i == en) { //종료 조건
					cout << vis[i];
					return;
				}
			}
		}
	}
	cout << -1; // 연결이 되지 않은 것
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> st >> en >> m;
	for (int i = 1; i <= m; i++) {
		int src, dst;
		cin >> src >> dst;
		grp[src][dst] = 1;
		grp[dst][src] = 1; //무방향성
	}

	for (int i = 1; i <= n; i++)
		vis[i] = -1; //양수면 방문한 것으로 처리

	bfs();

	return 0;
}
