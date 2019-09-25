#pragma warning(disable :4996)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> grp[20001];

int vis[20001]; //�ʱ� 0, ������ 1,2 -> ������ �������� �ٸ� vis ���� ������ �̺б׷���
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
			
			int next = grp[cur][i]; //Ȯ���� ����
			
			if (vis[next] != 0 && vis[cur] == vis[next]) { //������ ������ ���� vis���� ������ ���
				cout << "NO\n";
				isBigrp = false;
				return;
			}
			if (vis[next] > 0) continue; //��湮 ���ϰ�
			q.push(next);
			vis[next] = vis[cur] % 2 + 1; //cur�� 1�̸� next�� 2���ǰ�, vice versa
			
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
				if (!isBigrp) break; // �̺б׷����� �ƴ϶�� ����� ������ �� ������ �ʿ䰡 ����
			}
		}
		if(isBigrp)
			cout << "YES\n";

		//�� �Ʒ��δ� �ʱ�ȭ �κ�
		while (!q.empty()) q.pop();
		for (int i = 1; i <= vCnt; i++) {
			vis[i] = 0;
			grp[i].clear();
		}
		isBigrp = true;
	}
	return 0;
}
