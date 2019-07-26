//#include<iostream>
//using namespace std;
//int N, M;
//void func(int* arr, bool* isused, int k) {
//	if (k == M) {
//		for (int i = 1; i <= M; i++)
//			cout << arr[i] << ' ';
//		cout << '\n';
//		return;
//	}
//
//	for (int i = 1; i <= N; i++) {
//		if (!isused[i]) {
//			arr[k + 1] = i;
//			isused[i] = true;
//			func(arr, isused, k + 1);
//			isused[i] = false;
//		}
//	}
//}
//
//int main(void) {
//	int arr[10];
//	bool isused[10];
//	for (int i = 1; i <= 9; i++) {
//		arr[i] = 0;
//		isused[i] = false;
//	}
//
//	int k = 0;
//
//	cin >> N >> M;
//	
//	func(arr, isused, k);
//
//	return 0;
//}