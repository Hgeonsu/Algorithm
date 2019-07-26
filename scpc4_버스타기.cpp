//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int arr[200001];
//int main(void) {
//
//	int tc;
//	cin >> tc;
//	for (int t = 1; t <= tc; t++) {
//
//		int n, k;
//		cin >> n >> k;
//		for (int i = 0; i < n; i++) {
//			cin >> arr[i];
//		}
//
//		sort(arr, arr + n); //오름차순 정렬
//		
//		int bus = 1;
//
//		for (int i = 1; i < n; i++) {
//			if (arr[i] - arr[i - bus] <= k)
//				bus++;
//		}
//		cout << "Case #" << t << '\n' << bus << '\n';
//	}
//	return 0;
//}