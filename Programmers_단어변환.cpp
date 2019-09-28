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
		if (wrds[i] == src) { //시작 단어와 같은 단어가 목록에 존재
			st = i;
			addOne = false; //결과에 1 더해줄 필요가 없음
		}
		if (wrds[i] == dst) en = i;

		if (st == -1) { //시작 단어와 같은 단어가 목록에 없는 경우
			int dif = 0;
			for (int k = 0; k < len; k++) {
				if (wrds[i][k] != src[k]) dif++;
				if (dif > 1) break;
			}
			if (dif == 1) {
				st = i;
				addOne = true; //결과에 1을 더해준다. 시작부터 한번 바꾸고 시작했으니까
			}
		}

		//단어를 노드로 인접행렬 만들기
		for (int j = i + 1; j < wrds.size(); j++) {
			int dif = 0;
			for (int k = 0; k < len; k++) {
				if (wrds[i][k] != wrds[j][k]) dif++;
				if (dif > 1) break;
			}
			if (dif == 1) { //철자 하나 다를때만 연결
				m[i][j] = 1;
				m[j][i] = 1;
			}
		}
	}

	//목표 단어가 목록에 없으면 0 반환
	if (en != -1)
		bfs(wrds);
	else return 0;

	if (dis[en] != -1) { //바꿀 수 있으면
		if (!addOne)
			return dis[en];
		else
			return dis[en] + 1;
	}
	else
		return 0;
}