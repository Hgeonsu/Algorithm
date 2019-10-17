#include<iostream>
#include<vector>
using namespace std;

int h, w, k, m[14][21], org[14][21], st = 0;

bool used[14], findAns = false;

vector<int> v;

void changeRow(int r, int val) {
	for (int j = 0; j < w; j++)
		m[r][j] = val;
}

void toOrg(int r) {
	for (int j = 0; j < w; j++)
		m[r][j] = org[r][j];
}

void dfs(int cnt) { //������
	if (cnt == (int)v.size()) {
		
		//������ �˻� -> �����ϸ� �ٷ�����. ������ cnt
		for (int j = 0; j < w; j++) {
			int sameCnt = 0;
			bool contin = false;
			for (int i = 0; i < h-1; i++) {
				if (m[i][j] == m[i + 1][j]) sameCnt++;
				else sameCnt = 0;

				if (sameCnt == k - 1) {
					contin = true;
					break;
				}
				
				
			}
			if (!contin) return; //��������
			
			else if (contin && j == w - 1) 
				findAns = true; //���� ã��
		}
		
		return;
	}

		for (int j = 0; j < 2; j++) {
			changeRow(v[cnt], j); //v[cnt]���� i�� �ٲٱ�
			dfs(cnt + 1);
			if (findAns) return; //���� ����
			toOrg(v[cnt]); //v[cnt]�� ���󺹱�
		}
	
}

void pickRow(int cnt, int goal) { //����
								  
	if (cnt == goal) {
		
		dfs(0); //������ 0�ƴϸ� 1��
		return;
	}

	if (cnt == 0) st = 0;
	for (int i = st; i < h; i++) {
		if (!used[i]) {
			//row[cnt] = i;
			st = i;
			v.push_back(i);
			used[i] = true;
			pickRow(cnt + 1, goal);
			if (findAns) return;
			used[i] = false;
			v.pop_back();
		}
	}
}

void initMap() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			m[i][j] = org[i][j];
	}
}
int main(void) {

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> h >> w >> k;
		//a�� 0, b�� 1
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				cin >> m[i][j];
				org[i][j] = m[i][j]; //���� �迭
			}

	
		int ans = 0;
		for (int i = 0; i < h; i++) {
			pickRow(0, i);
			//�ʱ�ȭ
			if (findAns) {
				ans = i;
				break;
			}
			initMap();
		}

		cout << "#" << t << ' ' << ans << '\n';
 		
		for (int i = 0; i < h; i++) 
			used[i] = false;

		v.clear();

		findAns = false;
		st = 0;
		
	}

	return 0;
}
