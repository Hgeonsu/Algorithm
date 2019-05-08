#include<iostream>
#include<queue>
using namespace std;

int map[1001][1001], vis[1001][1001];
int M, N; //N = row, M = col
int day = 0;

queue<pair<int, int> > q;

int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0, };

bool updated = false;

void bfs() {
	while (!q.empty()) {
		int size = q.size();
		
		//큐의 크기만큼 pop 해서 주변 확인
		for (int i = 0; i < size; i++) {
			pair<int, int> cur = q.front();
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nr = cur.first + dr[j];
				int nc = cur.second + dc[j];

				//범위 벗어나면 continue
				if (nr < 0 || nc < 0 || nr >= N || nc >= M)continue;
				if (map[nr][nc] == -1)continue; //토마토 없으면 통과
				if (vis[nr][nc] == 1)continue; // 이미 주변 토마토를 익힌 위치의 토마토는 통과
				
				map[nr][nc] = 1;
				q.push({ nr,nc });
				vis[nr][nc] = 1;
				updated = true;
			}
		}
		if (updated) { //새롭게 익은 토마토가 있으면
			day++;
			updated = false;
		}
		else { // 익힐 수 있는 토마토를 다 익힌 경우
			return;
		}
	}
}

int main(void) {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) { //동시에 여러 좌표에서 bfs 실행할 때 idiom
				q.push({ i,j });
				vis[i][j] = 1;
			}
		}
	}
	
	bfs();

	//덜 익은 토마토가 남은 경우
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				day = -1;
			}
		}
	}

	cout << day << '\n';
	return 0;
}