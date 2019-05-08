#include<iostream>
#include<queue>
using namespace std;
int dh[6] = { 0,0,0,0,-1,1 }; //�����������Ʒ�
int dr[6] = { 0,0,1,-1,0,0 };
int dc[6] = { 1,-1,0,0,0,0 };
queue<pair<int, pair<int, int> > > q;
int map[101][101][101];
int vis[101][101][101];
int M, N, H;
int day = 0;

bool bfs() {
	//������ ť�� �ְ� �湮ó�� �ϴ� �� �ʿ� ����
	bool changed = false;

	while (!q.empty()) {
		pair<int, pair<int, int> > cur = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nh = cur.first + dh[i];
			int nr = cur.second.first + dr[i];
			int nc = cur.second.second + dc[i];

			if (nh < 0 || nr < 0 || nc < 0 || nh >= H || nr >= N || nc >= M)continue;
			if (vis[nh][nr][nc] == 1 || map[nh][nr][nc] == -1)continue; //�丶�䰡 ���� ��ġ�ų�, �̹� Ȯ���� �� �丶��� continue

			//q.push({ nh,{nr, nc} });
			//vis[nh][nr][nc] = 1;
			map[nh][nr][nc] = 1;
			changed = true;
		}
	}
	return changed;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N >> H;
	// N�� row, M�� col
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> map[i][j][k];
			}
		}
	}
	bool again = true;
	
	while (1) {
		

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					//�丶�䰡 �ְ�, ������ Ȯ�������� ���� ���̸�
					if (map[i][j][k] == 1 && vis[i][j][k] == 0) {
						q.push({ i, {j, k} });
						//ť�� ������ �ٽ� �� �ʿ䰡 ����
						vis[i][j][k] = 1;
					}
				}
			}
		}
		again = bfs();
		/*cout << "again :  " << again << "\nday : " << day<<'\n';
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					cout << vis[i][j][k];
				}
				cout << '\n';
			}
			cout << '\n';
		}*/
		if (again == false)break;
		
		day++;
	}

	
	//cout << "\n��� map\n";
	//cout << "day = " << day << '\n';
	//for (int i = 0; i < H; i++) {
	//	for (int j = 0; j < N; j++) {
	//		for (int k = 0; k < M; k++) {
	//			cout << map[i][j][k];
	//		}
	//		cout << '\n';
	//	}
	//	cout << '\n';
	//}

	//int result;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (map[i][j][k] == 0)
					day = -1;
			}
		}
	}

	cout << day << '\n';
	return 0;
}