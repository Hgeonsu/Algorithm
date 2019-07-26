//#include<iostream>
//#include<algorithm>
//using namespace std;
//int n, num[50], arr[7];
//bool isused[50];
//int st;
//void func(int k) {
//	//여기서 수열의 길이 k
//	if (k == 6) {
//		for (int i = 0; i < k; i++) {
//			cout << arr[i] << ' ';
//		}
//		cout << '\n';
//		return;
//	}
//	
//	if (k == 0) st = 0; //0일때 초기화
//	for (int i = st; i < n; i++) { //조합으로 만들기 위해 st부터. 0부터 뽑으면 순열(순서가 다르면 다른 수열)
//		if (!isused[i]) {
//			isused[i] = true;
//			arr[k] = num[i];
//			st = i;
//			func(k + 1);
//			isused[i] = false;
//		}
//	}
//}
//int main(void) {
//	while (1) {
//		cin >> n;
//		if (n == 0) break;
//		for (int i = 0; i < n; i++) {
//			cin >> num[i];
//		}
//		sort(num, num + n);
//		func(0);
//		cout << '\n';
//	}
//}