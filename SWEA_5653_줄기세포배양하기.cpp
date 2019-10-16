#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
struct Info {
	int actTime, deathTime, duration = -1, state = -3; //0 1 -1, -2 비활 활 죽음 방금생김
};// 활성화시작시간, 비활시간, 유지기간,   상태
const int dr[4] = { 0,0,1,-1 };
const int dc[4] = { 1,-1,0,0 };
typedef pair<int, int> pii;

int  row, col, k;
Info map[701][701];

queue<pii> q;
vector<pii> v;

vector<pii> pos; //위치정보


void bfs(int Time) {
	int qs = q.size();
	while (qs--) {
		pii cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];
			
			//나가는 경우 없음
			//if (vis[nr][nc]) continue;
			if (map[nr][nc].state == 0 || map[nr][nc].state == -1 || map[nr][nc].state == 1) continue;
			if (map[nr][nc].duration == -1 || 
				(map[nr][nc].state == -2 && map[cur.first][cur.second].duration >map[nr][nc].duration)) {
				Info tmp;
				tmp.duration = map[cur.first][cur.second].duration;
				tmp.actTime = Time + map[cur.first][cur.second].duration;
				tmp.deathTime = tmp.actTime + tmp.duration;
				tmp.state = -2; //방금생김
				map[nr][nc] = tmp;
				v.push_back({ nr, nc }); // 나중에 state 바꾸기 위함
				pos.push_back({ nr, nc }); //위치 정보에 추가
			}
			
		}
	}
	for (int i = 0; i < v.size(); i++) { //state 바꾸고 bfs 종료
		map[v[i].first][v[i].second].state = 0;
	}
	v.clear();
}	


void process() {

	for (int  tm = 1 ; tm <= k; tm++) { //i = 시간
		
		for (int i = 0; i < pos.size(); i++) {
			int r = pos[i].first;
			int c = pos[i].second;
			if (map[r][c].state == 1) q.push({ r, c });
		}
		bfs(tm); //활성된애들 bfs
		
		//활성시간, 비활성시간 체크해서 업데이트
		for (int i = 0; i < pos.size(); i++) {
			int r = pos[i].first;
			int c = pos[i].second;
			if (map[r][c].actTime == tm) map[r][c].state = 1;
			if (map[r][c].deathTime == tm) map[r][c].state = -1;
		}
		
	}

}

int main(void) {
	//setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		
		cin >> row >> col >> k;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				Info tmp;
				cin >> tmp.duration;
				if (tmp.duration == 0) continue;
				tmp.actTime = tmp.duration;
				tmp.deathTime = tmp.actTime + tmp.duration;
				
				pos.push_back({ 350 + i, 350 + j }); //위치 저장
				map[i + 350][j + 350] = tmp;
			}

		process();
		int ans = 0;
	
		for (int i = 0; i < pos.size(); i++) {
			int r = pos[i].first;
			int c = pos[i].second;
			if (map[r][c].state == 0 || map[r][c].state == 1) ans++; //죽지 않은 것들
		}

		cout << "#" << t << ' ' << ans << '\n';
	
		//map 초기화
		for (int i = 0; i < pos.size(); i++) {
			int r = pos[i].first;
			int c = pos[i].second;
			Info tmp;
			map[r][c] = tmp;
		}
		pos.clear();
	}

	return 0;
}
