#include<iostream>
#include<string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string str;
	str = to_string(n);
	int arr[10] = { 0, }; //�ڸ���
	for (int i = 0; i < str.length(); i++) {
		arr[str[i] - '0']++;
	}

	int max = -1, maxIdx = 0;
	for (int i = 0; i < 10; i++) {
		
		if (max < arr[i]) {
			if (i == 6 || i == 9)continue;
			max = arr[i];
			maxIdx = i;
		}
	}
	int snSum;
	if ((arr[6] + arr[9]) % 2 == 0) {
		snSum = (arr[6] + arr[9]) / 2;
	}
	else {
		snSum = (arr[6] + arr[9]) / 2 + 1;
	}
	if (max > snSum) {
		cout << max << '\n';
	}
	else {
		cout << snSum << '\n';
	}

	return 0;
}
/*��������, ���ڰ� �� �������� � �������� Ȯ��. int�� string���� ����ȯ
6�� 9�� ���� ���� �� �����Ƿ� �̸� �̿�*/