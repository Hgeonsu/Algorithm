//#include<iostream>
//using namespace std;
//int n;
//bool isused[3][40];
//int cnt = 0;
//void func(int k) {
//	//k-1개 까지 다 놓은 상태
//	if (k == n + 1) {
//		cnt++;
//		return;
//	}
//	for (int i = 1; i <= n; i++) {
//		if (isused[0][i] || isused[1][k + i] || isused[2][k - i + n - 1])
//			continue;
//		isused[0][i] = true;
//		isused[1][k + i] = true;
//		isused[2][k - i + n - 1] = true;
//		func(k + 1);
//		isused[0][i] = false;
//		isused[1][k + i] = false;
//		isused[2][k - i + n - 1] = false;
//	}
//}
//int main(void) {
//	cin >> n;
//	func(1);
//	cout << cnt;
//	return 0;
//}