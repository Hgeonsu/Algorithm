//#include<iostream>
//#include<algorithm>
//using namespace std;
//int N, M;
//int arr[10], num[10];
//bool isused[10];
//
//void func(int k) {
//	if (k == M + 1) {
//		for (int i = 1; i <= M; i++)
//			cout << arr[i] << ' ';
//		cout << '\n';
//		return;
//	}
//	
//	for (int i = 1; i <= N; i++) {
//		if (!isused[i]) {
//			arr[k] = num[i];
//			isused[i] = true;
//			func(k + 1);
//			isused[i] = false;
//		}
//	}
//
//}
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++) {
//		cin >> num[i];
//	}
//	sort(num + 1, num + N + 1);
//
//	func(1);
//
//	return 0;
//}