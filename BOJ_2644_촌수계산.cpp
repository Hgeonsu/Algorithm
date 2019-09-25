#pragma warning(disable :4996)
#include<iostream>
#include<queue>
using namespace std;

int grp[101][101]; //1-indexed
int vis[101]; //����� �湮�� ��
queue<int> q;

int n, st, en, m; //n���� ���, m���� ����

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
				if (i == en) { //���� ����
					cout << vis[i];
					return;
				}
			}
		}
	}
	cout << -1; // ������ ���� ���� ��
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> st >> en >> m;
	for (int i = 1; i <= m; i++) {
		int src, dst;
		cin >> src >> dst;
		grp[src][dst] = 1;
		grp[dst][src] = 1; //�����⼺
	}

	for (int i = 1; i <= n; i++)
		vis[i] = -1; //����� �湮�� ������ ó��

	bfs();

	return 0;
}
