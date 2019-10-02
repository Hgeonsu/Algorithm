#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
using namespace std;
int n;
int pop[11], tot = 0, Min = 987654321;
bool vis[11], map[11][11], used[11];
queue<int> q;

vector<int> v; //�������� ���� ���� ����

int st = 1, restSum;

int bfs(int st, bool usedCheck) { //true�� ��찡 ó�� ���� ������ ���� Ȯ���ϴ� ���
	q.push(st);
	vis[st] = true;
	int restSum = pop[st];
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (usedCheck)
				if (!used[i]) continue; //���� ���鿡 ���ؼ��� ���� ���� Ȯ��
			
			if (!map[cur][i] || vis[i]) continue;
			
			q.push(i);
			vis[i] = true;
			restSum += pop[i];
		}
	}
	return restSum; //���ű� �ο� ��ȯ
}

void process() {
	int pickedSum, restSum;
	

	//ó���� ���� �� ��� ����Ǿ� �ִ��� Ȯ��
	for (int i = 1; i <= n; i++) {
		if (used[i]) {
			pickedSum = bfs(i, true);
			break;
		}
	}

	bool firCon = true;
	for (int i = 1; i <= n; i++) {
		if (used[i]) { //���� ���߿�
			if (!vis[i]) firCon = false; //���� �� �Ȱ� �ϳ��� ������ �Ÿ���
		}
	}

	for (int i = 1; i <= n; i++) //�湮 ó�� �迭 �ʱ�ȭ
		vis[i] = false;

	if (!firCon) return;


	for (int i = 1; i <= n; i++) 
		if (used[i]) vis[i] = true; //Ȯ���� ���ű� �湮ó��
	
	for(int i = 1; i <= n; i++) {
		if (!vis[i]) {
			restSum = bfs(i, false); //������ ���ű� �ο� ��� + ���� ���� Ȯ��
			break;
		}
	}

	bool allCon = true;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) { //���ű� ���� �Ұ�
			allCon = false;
			break;
		}
	}
	
	if(allCon) {
		int dif = abs(tot - restSum - restSum);
		if (Min > dif) Min = dif;
	}
	for (int i = 1; i <= n; i++)
		vis[i] = false;
}
void btk(int cnt) {
	if (cnt >= 1) {
		if (cnt >= 6) return;
		//���� �� ���� ��� ����
		process();
	}
	
	if (cnt == 0) st = 1;
	for (int i = st; i <= n; i++) {
		if (!used[i]) {
			st = i;
			used[i] = true;
			btk(cnt + 1);
			used[i] = false;
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> pop[i];
		tot += pop[i];
	}

	for (int i = 1; i <= n; i++) {
		int edgeCnt;
		cin >> edgeCnt;
		while (edgeCnt--) {
			int dst;
			cin >> dst;
			map[dst][i] = true;
			map[i][dst] = true;
		}
	}

	btk(0);

	if (Min == 987654321) cout << -1;
	else
		cout << Min;

	return 0;
}