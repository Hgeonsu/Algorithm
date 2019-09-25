#pragma warning(disable :4996)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> grp[20001];

int vis[20001]; //초기 0, 두종류 1,2 -> 인접한 정점간에 다른 vis 값을 가지면 이분그래프
int vCnt, eCnt;
bool isBigrp = true;
queue<int> q;
void bfs(int st) {
	q.push(st);
	vis[st] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < grp[cur].size(); i++) {
			
			int next = grp[cur][i]; //확인할 지점
			
			if (vis[next] != 0 && vis[cur] == vis[next]) { //인접한 정점과 같은 vis값을 가지는 경우
				cout << "NO\n";
				isBigrp = false;
				return;
			}
			if (vis[next] > 0) continue; //재방문 못하게
			q.push(next);
			vis[next] = vis[cur] % 2 + 1; //cur이 1이면 next는 2가되고, vice versa
			
		}
	}
	
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> vCnt >> eCnt;
		for (int i = 0; i < eCnt; i++) {
			int src, dst;
			cin >> src >> dst;
			grp[src].push_back(dst);
			grp[dst].push_back(src);
		}
		
		for (int i = 1; i <= vCnt; i++) {
			if (vis[i] == 0) {
				bfs(i);
				if (!isBigrp) break; // 이분그래프가 아니라는 결론이 났으면 더 진행할 필요가 없다
			}
		}
		if(isBigrp)
			cout << "YES\n";

		//이 아래로는 초기화 부분
		while (!q.empty()) q.pop();
		for (int i = 1; i <= vCnt; i++) {
			vis[i] = 0;
			grp[i].clear();
		}
		isBigrp = true;
	}
	return 0;
}
