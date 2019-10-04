
#include<iostream>
#define INF 987654321;
using namespace std;

int price[4], plan[15], Min = INF;

void dfs(int month, int fee) {
	if (month >= 12) {
		if (fee < Min) Min = fee;
		
		return;
	}
	
	//(month + 1)�� ��� ������ ����

	if (plan[month + 1] == 0) //�� �޿� �̿� ������ ������ ��� �߰� ���� �� �߰�
		dfs(month + 1, fee);
	
	else {
		dfs(month + 1, fee + price[0] * plan[month + 1]); //1��
		dfs(month + 1, fee + price[1]); //1��
		dfs(month + 3, fee + price[2]); //3��
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		for (int i = 0; i < 4; i++)
			cin >> price[i]; // 1��, 1��, 3�� 1��
		
		
		for (int i = 1; i <= 12; i++)
			cin >> plan[i];
		
		if (Min > price[3]) Min = price[3]; // 1��ġ
		
		dfs(0, 0);
		cout << "#" << tc << ' ' <<  Min << '\n';
		Min = INF; //Min �ʱ�ȭ
	}
	return 0;
}

