//#include<iostream>
//using namespace std;
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//	int arr[200];
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//
//	int d[200];
//	int Max = 0;
//	for (int i = 0; i < n; i++) { //LIS(최장 부분 증가 수열)구하기
//		d[i] = 1;
//		for (int j = 0; j < i; j++) {
//			if (arr[i] > arr[j] && d[i] < d[j] + 1) {
//				d[i]++;
//			}
//		}
//		if (Max < d[i]) Max = d[i];
//		
//	}
//
//	cout << n - Max << '\n';
//	return 0;
//}
