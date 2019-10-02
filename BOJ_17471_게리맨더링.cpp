#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
using namespace std;
int n;
int pop[11], tot = 0, Min = 987654321;
bool vis[11], map[11][11], used[11];
queue<int> q;

vector<int> v; //조합으로 뽑은 구역 저장

int st = 1, restSum;

int bfs(int st, bool usedCheck) { //true인 경우가 처음 뽑은 구역들 연결 확인하는 경우
	q.push(st);
	vis[st] = true;
	int restSum = pop[st];
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (usedCheck)
				if (!used[i]) continue; //뽑은 곳들에 대해서만 연결 관계 확인
			
			if (!map[cur][i] || vis[i]) continue;
			
			q.push(i);
			vis[i] = true;
			restSum += pop[i];
		}
	}
	return restSum; //선거구 인원 반환
}

void process() {
	int pickedSum, restSum;
	

	//처음에 뽑은 게 모두 연결되어 있는지 확인
	for (int i = 1; i <= n; i++) {
		if (used[i]) {
			pickedSum = bfs(i, true);
			break;
		}
	}

	bool firCon = true;
	for (int i = 1; i <= n; i++) {
		if (used[i]) { //뽑은 것중에
			if (!vis[i]) firCon = false; //연결 안 된거 하나라도 있으면 거르기
		}
	}

	for (int i = 1; i <= n; i++) //방문 처리 배열 초기화
		vis[i] = false;

	if (!firCon) return;


	for (int i = 1; i <= n; i++) 
		if (used[i]) vis[i] = true; //확정된 선거구 방문처리
	
	for(int i = 1; i <= n; i++) {
		if (!vis[i]) {
			restSum = bfs(i, false); //나머지 선거구 인원 계산 + 연결 관계 확인
			break;
		}
	}

	bool allCon = true;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) { //선거구 형셩 불가
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
		//전부 다 뽑은 경우 제외
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