#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define INF 987654321

int Min = INF;
int food[18][18], arr[2];
int st = 1, n;
bool used[18], usedP[18];

vector<int> candi, others;
int Sum = 0;

void per(int K, vector<int>& useable) {
	if (K == 2) {
		Sum += food[arr[0]][arr[1]]; //������ �ó��� ����ϴ� �κ�
		return;
	}
	
	for (int i = 0; i < useable.size(); i++) {
		if (!usedP[i]) {
			arr[K] = useable[i];
			usedP[i] = true;
			per(K + 1, useable);
			usedP[i] = false;
		}
	}
}
void com(int k, int goal) {
	if (k == goal) { //n/2�� ������

		////candi���� 2�� ������ �̾Ƽ� �ó��� ���
		Sum = 0;
		per(0, candi);
		int sumA = Sum;
		
		
		//�ٸ� ���Ŀ� ���̴� ��ᵵ ���������� �ó��� ���
		others.clear();
		for (int i = 1; i <= n; i++) 
			if (!used[i]) others.push_back(i);
		

		Sum = 0;
		per(0, others);
		int sumB = Sum;

		int dif = abs(sumA - sumB);
		if (dif < Min) Min = dif; //���� ���� ������Ʈ

		return;
	}

	if (k == 0) st = 1;
	for (int i = st; i <= n; i++) {
		if (!used[i]) {
			st = i;
			used[i] = true;
			candi.push_back(i); //���� �ϳ��� ���� ��ῡ �߰�
			com(k + 1, goal);
			used[i] = false;
			candi.pop_back();
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> food[i][j];
		
		com(0, n / 2); //������ �������� �̴´�(���� �ϳ��� ���� ��� ����)

		cout << "#" << tc << ' ' << Min << '\n';
		Min = INF;
		candi.clear();
		
	}

	return 0;
}

