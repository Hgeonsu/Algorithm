#include<iostream>
#include<queue>
using namespace std;
int lev, cur, des, up, down;
// ��ü��, ����, ������, ��, �Ʒ�
int dis[1000002];
int nlev[2];
queue<int> q;

void bfs(int start) {
	q.push(start);
	dis[start]++;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		//���������� ������
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

	//���Ʒ��� ������ 
	nlev[0] = up;
	nlev[1] = -down;

	//�湮ó�� �迭 -> �Ÿ� �迭
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