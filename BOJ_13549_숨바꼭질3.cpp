#pragma warning(disable :4996)
#include<iostream>
#include<queue>
#include<functional>
#include<limits.h> //�� ����� �ؾ� ���ؿ��� ���ư�

using namespace std;
typedef pair<int, int> pii;

int dis[100001], src, dst;
bool vis[100001];
priority_queue<pii, vector<pii>, greater<pii> > pq;

void dijk() {
	pq.push({ 0, src }); //{�� �������� ���� ���, ����}
	dis[src] = 0;

	while (!pq.empty()) {
		int here = pq.top().second; //���� Ȯ���ϴ� ����
		pq.pop();
		vis[here] = true; //�湮ó��
		
		int there, moveCost; //���� �湮����, here���� there�� ���� ���

		for (int i = 0; i < 3; i++) {
			//0������ �ȱ�, 1�ڷΰȱ�, 2����
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

			//�̹� ���� src���� there���� ���� �����
			//src~here ��� + here~there��뺸�� ũ�� �����ϰ� pq�� ����
			if (dis[there] > dis[here] + moveCost) { 
				dis[there] = dis[here] + moveCost;
				pq.push({ dis[there], there });
			}
		}
		if (here == dst) return; //�������� �湮ó�� �Ǿ����Ƿ� Ȯ�� �׸�
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i <= 100000; i++)
		dis[i] = INT_MAX; //���Ѵ�� �ʱ�ȭ

	cin >> src >> dst;

	dijk();

	cout << dis[dst];
	return 0;
}

