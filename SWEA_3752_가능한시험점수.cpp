#pragma warning(disable :4996)
#include<iostream>
#include<vector>
using namespace std;
bool vis[10001]; //�ִ� ����
int n;
vector<int> v;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> n;

		v.push_back(0);
		vis[0] = true;
		int val;
		for (int i = 0; i < n; i++) {
			cin >> val;
			int curSize = v.size(); //���ο� ���� �ֱ� ������ ���� ũ��
			for (int j = 0; j < curSize; j++) {
				int candi = val + v[j]; //�߰��� �� �ִ� ��
				if (!vis[candi]) { //�̹� �߰��� ���� pass
					v.push_back(candi);
					vis[candi] = true;
				}
			}
		}
		cout << '#' << tc << ' ' << v.size() << '\n';
		v.clear();
		for (int i = 0; i <= 10000; i++)
			vis[i] = false;
	}

	return 0;
}
