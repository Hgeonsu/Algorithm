#include<iostream>

using namespace std;
int arr[11]; //1,2,3�� ������ ���ؼ� i�� ����� ����� �� (���� �ٸ��� �ٸ� ���� ��)
int main(void) {
	
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i <= 10; i++) {
		arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
	}
	
	int n;
	cin >> n;
	while (n--) {
		int val;
		cin >> val;
		cout << arr[val] << '\n';
	}
	return 0;
}