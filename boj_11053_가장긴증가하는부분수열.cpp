//#include<iostream>
//using namespace std;
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//	int arr[1000];
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//
//	int d[1000];
//	int Max = 0;
//	for (int i = 0; i < n; i++) {
//		d[i] = 1;
//		for (int j = 0; j < i; j++) {
//			if (arr[i] > arr[j] && d[i] < d[j] + 1)
//				d[i]++;
//		}
//		if (Max < d[i]) Max = d[i];
//	}
//	cout << Max << '\n';
//
//	return 0;
//}
