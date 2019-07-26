//#include<iostream>
//using namespace std;
//int d[1002];
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//	int arr[1002];
//	for (int i = 1; i <= n; i++) {
//		cin >> arr[i];
//	}
//
//	for (int i = 1; i <= n; i++) {
//		int Max = 0;
//		for (int j = 0; j < i; j++) {
//			if (arr[i] < arr[j]) {
//				//작은 인덱스의 값보다 더 작은 값이 들어오면
//				if (d[j] > Max) {
//					Max = d[j];
//				}
//			}
//		}
//		d[i] = Max + 1;
//	}
//	
//	int Max = 0;
//	for (int i = 1; i <= n; i++) {
//		if (Max < d[i]) {
//			Max = d[i];
//		}
//	}
//	cout << Max << '\n';
//	
//	return 0;
//}
