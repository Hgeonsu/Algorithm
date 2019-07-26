//#include<iostream>
//using namespace std;
//int N, M;
//int arr[9];
//void func(int k) {
//	if (k > M) {
//		for (int i = 1; i <= M; i++) {
//			cout << arr[i] << ' ';
//		}
//		cout << '\n';
//		return;
//	}
//	int st = 1;
//	if (k != 1) st = arr[k - 1];
//	for (int i = st ; i <= N; i++) {
//		
//		arr[k] = i;
//		func(k + 1);
//	}
//}
//int main(void) {
//	cin >> N >> M;
//	func(1);
//	return 0;
//}