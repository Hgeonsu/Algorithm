//#include<iostream>
//#include<string>
//using namespace std;
//
//int arr[10];
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	string s = to_string(n); //�� ������ ������ �ľ��ϱ� ���� string���� ��ȯ
//
//	for (int i = 0; i < s.length(); i++) //���� �ľ�
//		arr[s[i] - '0']++;
//
//	int sum69 = 0, max = -1;
//	for (int i = 0; i < 10; i++) { //6�� 9�� ������ �ľ�
//		if (i == 6 || i == 9)
//			sum69 = sum69 + arr[i];
//		else {
//			if (arr[i] > max) //6�� 9�� ������ ������ �ִ��� �� �ľ�
//				max = arr[i];
//		}
//	}
//	if (sum69 % 2 == 0) {
//		sum69 = sum69 / 2;
//	}
//	else {
//		sum69 = sum69 / 2 + 1;
//	}
//	if (sum69 > max) {
//		cout << sum69;
//	}
//	else {
//		cout << max;
//	}
//
//	return 0;
//}
