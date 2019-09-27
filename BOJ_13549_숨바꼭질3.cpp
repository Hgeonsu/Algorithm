#pragma warning(disable :4996)
#include<iostream>
#include<queue>
#include<functional>
#include<limits.h> //이 헤더로 해야 백준에서 돌아감

using namespace std;
typedef pair<int, int> pii;

int dis[100001], src, dst;
bool vis[100001];
priority_queue<pii, vector<pii>, greater<pii> > pq;

void dijk() {
	pq.push({ 0, src }); //{그 지점까지 가는 비용, 지점}
	dis[src] = 0;

	while (!pq.empty()) {
		int here = pq.top().second; //현재 확인하는 지점
		pq.pop();
		vis[here] = true; //방문처리
		
		int there, moveCost; //다음 방문지점, here에서 there로 가는 비용

		for (int i = 0; i < 3; i++) {
			//0앞으로 걷기, 1뒤로걷기, 2점프
			if (i == 0)
				there = here + 1;
			else if (i == 1) there = here - 1;
			else
				there = here * 2;

			if (i != 2)
				moveCost = 1;
			else
				moveCost = 0;

			if (there < 0 || there > 100000 || vis[there]) continue;

			//이미 계산된 src에서 there까지 가는 비용이
			//src~here 비용 + here~there비용보다 크면 갱신하고 pq에 삽입
			if (dis[there] > dis[here] + moveCost) { 
				dis[there] = dis[here] + moveCost;
				pq.push({ dis[there], there });
			}
		}
		if (here == dst) return; //목적지가 방문처리 되었으므로 확인 그만
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i <= 100000; i++)
		dis[i] = INT_MAX; //무한대로 초기화

	cin >> src >> dst;

	dijk();

	cout << dis[dst];
	return 0;
}

