#include <string>
#include <vector>
#include<iostream>
#include<queue>
using namespace std;

int m[51][51], dis[51], st = -1, en = -1;
bool addOne = false;
queue<int> q;
void bfs(vector<string>& grp) {
	q.push(st);
	dis[st]++;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int cur = q.front();
			q.pop();

			for (int i = 0; i < grp.size(); i++) {
				if (m[cur][i] == 0 || dis[i] >= 0) continue;
				q.push(i);
				dis[i] = dis[cur] + 1;
				if (i == en) return;
			}
		}
	}
}
int solution(string src, string dst, vector<string> wrds) {

	int len = wrds[0].length();

	for (int i = 0; i < wrds.size(); i++) {
		dis[i] = -1;
		if (wrds[i] == src) { //���� �ܾ�� ���� �ܾ ��Ͽ� ����
			st = i;
			addOne = false; //����� 1 ������ �ʿ䰡 ����
		}
		if (wrds[i] == dst) en = i;

		if (st == -1) { //���� �ܾ�� ���� �ܾ ��Ͽ� ���� ���
			int dif = 0;
			for (int k = 0; k < len; k++) {
				if (wrds[i][k] != src[k]) dif++;
				if (dif > 1) break;
			}
			if (dif == 1) {
				st = i;
				addOne = true; //����� 1�� �����ش�. ���ۺ��� �ѹ� �ٲٰ� ���������ϱ�
			}
		}

		//�ܾ ���� ������� �����
		for (int j = i + 1; j < wrds.size(); j++) {
			int dif = 0;
			for (int k = 0; k < len; k++) {
				if (wrds[i][k] != wrds[j][k]) dif++;
				if (dif > 1) break;
			}
			if (dif == 1) { //ö�� �ϳ� �ٸ����� ����
				m[i][j] = 1;
				m[j][i] = 1;
			}
		}
	}

	//��ǥ �ܾ ��Ͽ� ������ 0 ��ȯ
	if (en != -1)
		bfs(wrds);
	else return 0;

	if (dis[en] != -1) { //�ٲ� �� ������
		if (!addOne)
			return dis[en];
		else
			return dis[en] + 1;
	}
	else
		return 0;
}