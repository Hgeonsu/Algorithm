#include<iostream>
#include<queue>
using namespace std;
int lev, cur, des, up, down;
// 전체층, 현재, 목적지, 위, 아래
int dis[1000002];
int nlev[2];
queue<int> q;

void bfs(int start) {
	q.push(start);
	dis[start]++;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		//엘리베이터 움직임
		for (int i = 0; i < 2; i++) {
			int nMove = cur + nlev[i];
			if (nMove <= 0 || nMove > lev)continue;
			if (dis[nMove] >= 0)continue; 

			dis[nMove] = dis[cur] + 1;
			q.push(nMove);
		}


	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> lev >> cur >> des >> up >> down;

	//위아래층 움직임 
	nlev[0] = up;
	nlev[1] = -down;

	//방문처리 배열 -> 거리 배열
	for (int i = 1; i <= lev; i++) {
		dis[i] = -1;
	}

	bfs(cur);

	if (dis[des] != -1) {
		cout << dis[des] << '\n';
	}
	else {
		cout << "use the stairs" << '\n';
	}

	return 0;
}