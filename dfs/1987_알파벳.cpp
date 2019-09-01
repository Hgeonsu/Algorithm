#pragma warning(disable :4996)
#include<iostream>
#include<string>
using namespace std;
const int dr[4] = { 0,0,1,-1 };
const int dc[4] = { 1,-1,0,0 };
typedef pair<int, int> pii;
int row, col, Max = 0;
char m[21][21], arr[100];
bool vis[21][21], used[26];
void Print() {
	cout << '\n';
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cout << m[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void dfs(pii here, int k) { //지금까지 k개 지나옴
	
	if (Max < k) Max = k; 
	for (int i = 0; i < 4; i++) {
		int nr = here.first + dr[i];
		int nc = here.second + dc[i];
		if (nr < 1 || nc < 1 || nr > row || nc > col) continue;
		
		if (!used[m[nr][nc] - 'A'] && !vis[nr][nc]) { //그 문자를 안 썼고 그 지점을 거쳐 오지 않았으면
			used[m[nr][nc] - 'A'] = true; //해당 문자 사용중 
			vis[nr][nc] = true; //방문
			arr[k] = m[nr][nc];
			dfs({ nr, nc }, k + 1);
			vis[nr][nc] = false;
			used[m[nr][nc] - 'A'] = false;
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> row >> col;
	for (int i = 1; i <= row; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < col; j++) 
			m[i][j+1] = input[j];
	}

	used[m[1][1] - 'A'] = true; //시작점은 항상 사용중
	vis[1][1] = true; //항상 방문중
	dfs({ 1, 1 }, 1);
	cout << Max;
	return 0;
}
