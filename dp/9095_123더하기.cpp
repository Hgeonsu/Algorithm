#include<iostream>

using namespace std;
int arr[11]; //1,2,3을 적절히 더해서 i를 만드는 방법의 수 (순서 다르면 다른 경우로 봄)
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