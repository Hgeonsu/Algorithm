#include<iostream>
#include<cmath>
using namespace std;

int n, len, map[21][21];
bool used[21][21];

bool rowCheck(int i) {

	for (int j = 0; j < n-1; j++) {
		if (used[i][j + 1]) continue; //���� ������ �̹� ���� ������
		if (abs(map[i][j] - map[i][j + 1]) >= 2) return false; //2�̻� ����
		
		if (map[i][j] == map[i][j + 1] + 1) {
			if (j + len >= n) return false; //���� ������ ������ ������ ���

			for (int k = j + 1; k <= j + 1 + len - 2; k++) {
				if (map[i][k] != map[i][k + 1]) return false;
			}

			for (int k = j + 1; k <= j + 1 + len - 1; k++) { //�̹� ���ΰ� ���� ���
				if (used[i][k]) return false;
			}
			
			for (int k = j + 1; k <= j + len; k++) //���� ǥ��
				used[i][k] = true;
		}

	}

	for (int j = 0; j < n-1; j++) {
		if (used[i][j + 1]) continue; //���� ������ �̹� ���� ������
		
		if (map[i][j] == map[i][j + 1] - 1) {
			if (j + 1 - len < 0) return false; //���� ������ ������ ������ ���

			for (int k = j + 1 - len; k <= j - 1 ; k++) {
				if (map[i][k] != map[i][k + 1]) return false;
			}

			for (int k = j + 1 - len; k <= j; k++) { //�̹� ���ΰ� ���� ���
				if (used[i][k]) return false;
			}

			for (int k = j + 1 - len; k <= j ; k++) //���� ǥ��
				used[i][k] = true;
		}
	}
	return true;
}

bool colCheck(int j) {
	for (int i = 0; i < n - 1; i++) {
		if (used[i+1][j]) continue; //���� ������ �̹� ���� ������
		if (abs(map[i][j] - map[i+1][j]) >= 2) return false; //2�̻� ����

		if (map[i][j] == map[i+1][j] + 1) {
			if (i + len >= n) return false; //���� ������ ������ ������ ���

			for (int k = i + 1; k <= i + 1 + len - 2; k++) {
				if (map[k][j] != map[k+1][j]) return false;
			}

			for (int k = i + 1; k <= i + 1 + len - 1; k++) {
				if (used[k][j]) return false;
			}

			for (int k = i + 1; k <= i + len; k++) //���� ǥ��
				used[k][j] = true;
		}

	}

	for (int i = 0; i < n - 1; i++) {
		if (used[i+1][j]) continue; //���� ������ �̹� ���� ������

		if (map[i][j] == map[i+1][j] - 1) {
			if (i + 1 - len < 0) return false; //���� ������ ������ ������ ���

			for (int k = i + 1 - len; k <= i - 1; k++) {
				if (map[k][j] != map[k+1][j]) return false;
			}

			for (int k = i + 1 - len; k <= i; k++) {
				if (used[k][j]) return false;
			}

			for (int k = i + 1 - len; k <= i; k++) //���� ǥ��
				used[k][j] = true;
		}
	}

	return true;
}

int process() {
	int ret = 0; //Ȱ�ַη� ��밡���� ��

	for (int i = 0; i < n; i++) {
		if (!rowCheck(i)) //���ι��� Ȯ��
			continue;
		ret++;
	}

	//���� �ʱ�ȭ
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			used[i][j] = false;


	for (int j = 0; j < n; j++) {
		if (!colCheck(j)) 
			continue;
		ret++;
	}
	
	return ret;
}

int main(void) {
	//setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		cin >> n >> len;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];

		int res = process();

		cout << "#" << t << ' ' << res << '\n';

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				map[i][j] = 0;

		//���� �ʱ�ȭ
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				used[i][j] = false;

	}

	return 0;
}
