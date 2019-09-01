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

void dfs(pii here, int k) { //���ݱ��� k�� ������
	
	if (Max < k) Max = k; 
	for (int i = 0; i < 4; i++) {
		int nr = here.first + dr[i];
		int nc = here.second + dc[i];
		if (nr < 1 || nc < 1 || nr > row || nc > col) continue;
		
		if (!used[m[nr][nc] - 'A'] && !vis[nr][nc]) { //�� ���ڸ� �� ��� �� ������ ���� ���� �ʾ�����
			used[m[nr][nc] - 'A'] = true; //�ش� ���� ����� 
			vis[nr][nc] = true; //�湮
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

	used[m[1][1] - 'A'] = true; //�������� �׻� �����
	vis[1][1] = true; //�׻� �湮��
	dfs({ 1, 1 }, 1);
	cout << Max;
	return 0;
}
