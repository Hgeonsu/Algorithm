#include<iostream>
#include<string>
using namespace std;
int A, B, C, arr[10];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B >> C;
	long long res = A * B*C;	
	string str = to_string(res);
	for (int i = 0; i < str.length(); i++) {
		arr[str[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}
/*
�� �ڸ����� ���ڸ� Ȯ���ϱ� ���� ��� ����� long long���� string ���� ��ȯ
string���� ��ȯ�� ���� �� �ڸ����� char���� int�� ��ȯ�� -'0'�� Ȱ��
*/