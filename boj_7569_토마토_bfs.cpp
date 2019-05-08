#include<iostream>
#include<queue>
using namespace std;
int H, N, M; //N = row, N = col
int map[101][101][101], vis[101][101][101];
int dh[6] = { 0,0,0,0,1,-1 };
int dc[6] = { 1,-1,0,0,0,0 };
int dr[6] = { 0,0,1,-1,0,0 };
int day = 0;
queue<pair<int, pair<int, int> > > q;
bool updated = false;
void bfs() {
	
	while (!q.empty()) {
		int size = q.size();//하루 단위로 bfs실행하기위해@@@@
		for (int i = 0; i < size; i++) {
		pair<int, pair<int, int> > cur = q.front();
		q.pop();
		
		// 큐에 있는만큼만 실행해야 하루 단위로 계산 가능
		//cout << q.size() << '
		
			for (int j = 0; j < 6; j++) {
				int nh = cur.first + dh[j];
				int nr = cur.second.first + dr[j];
				int nc = cur.second.second + dc[j];
				
				//박스 밖으로 나가는 경우 continue
				if (nh < 0 || nr < 0 || nc < 0 || nh >= H || nr >= N || nc >= M)continue;
				//빈 박스인 경우 continue
				if (map[nh][nr][nc] == -1 || vis[nh][nr][nc] ==1) continue;
				map[nh][nr][nc] = 1;
				updated = true;
				q.push({ nh,{nr, nc} });
				vis[nh][nr][nc] = 1;

			}
		}
		if (updated) {
			day++;
			updated = false;
		}
		else {
			return;
		}
	}
}
int main(void) {
	
	cin >> M >> N >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push({ i,{j,k} });
					vis[i][j][k] = 1;
				}
			}
		}
	}

	bfs();

	//익지 않은 토마토가 있으면
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (map[i][j][k] == 0) {
					day = -1;
				}
			}
		}
	}
	cout << day << '\n';
	return 0;
}