#include<iostream>
typedef long long ll;
using namespace std;

ll d[91]; //i�ڸ� ��ģ���� ����
int main(void) {
	
	d[1] = 1; // 1
	d[2] = 1; //10
	for (int i = 3; i <= 90; i++) {
		d[i] = 1;
		for (int j = i - 2; j >= 1; j--) {
			d[i] += d[j]; 
		}//�Ǿ� 1�θ� �ٷο��� ������ 0�̰�, ���� �ڸ��� ��ģ���� ä���ش�
	}
	
	int val;
	cin >> val;
	cout << d[val];
	return 0;
}