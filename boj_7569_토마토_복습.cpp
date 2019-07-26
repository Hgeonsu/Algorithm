//#include<iostream>
//#include<queue>
//using namespace std;
//int col, row, H, m[100][100][100];
//bool vis[100][100][100];
//struct pt {
//	int h;
//	int row;
//	int col;
//};
//queue<pt> q;
//int dh[6] = { 0,0,0,0,1,-1 };
//int dr[6] = { 0,0,1,-1,0,0 };
//int dc[6] = { 1,-1,0,0,0,0 };
//int Day = 0;
//bool updated = false;
//
//void bfs() {
//	while (!q.empty()) {
//		int cnt = q.size();
//		updated = false;
//		while (cnt--) {
//			pt cur = q.front();
//			q.pop();
//			for (int i = 0; i < 6; i++) {
//				int nh = cur.h + dh[i];
//				int nr = cur.row + dr[i];
//				int nc = cur.col + dc[i];
//				
//				if (nh < 0 || nr < 0 || nc < 0 || nh >= H || nr >= row || nc >= col) continue; //범위 밖이면 pass
//				if (m[nh][nr][nc] != 0 || vis[nh][nr][nc]) continue; //토마토가 익지 않은 자리가 아니거나 이미 방문한 지점이면 pass
//				
//				m[nh][nr][nc] = 1;
//				q.push({ nh, nr, nc });
//				vis[nh][nr][nc] = true;
//				updated = true;
//			}
//		}
//		if (!updated) break; //하루 지났는데 변화가 없었으면 break;
//		Day++;
//	}
//}
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	for (int T = 1; T <= 1; T++) {
//
//
//		cin >> col >> row >> H;
//
//		for (int h = 0; h < H; h++) {
//			for (int i = 0; i < row; i++) {
//				for (int j = 0; j < col; j++) {
//					cin >> m[h][i][j];
//					if (m[h][i][j] == 1) {
//						q.push({ h, i, j });
//						vis[h][i][j] = true;
//					}
//				}
//			}
//		}
//		bfs();
//		for (int h = 0; h < H; h++) {
//			for (int i = 0; i < row; i++) {
//				for (int j = 0; j < col; j++) {
//					if (m[h][i][j] == 0) {
//						//cout << -1 << '\n';
//						//return 0;
//						Day = -1;
//					}
//				}
//			}
//		}
//		cout << Day << '\n';
//		
//
//		//초기화
//		for (int h = 0; h < H; h++) {
//			for (int i = 0; i < row; i++) {
//				for (int j = 0; j < col; j++) {
//					m[h][i][j] = 0;
//					vis[h][i][j] = false;
//				}
//			}
//		}
//		while (!q.empty())
//			q.pop();
//		Day = 0;
//		updated = false;
//
//	}
//	return 0;
//}