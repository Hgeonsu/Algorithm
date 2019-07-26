//#include<iostream>
//#include<algorithm>
//using namespace std;
//int N, M, num[8], arr[8];
//
//void func(int k) {
//	if (k == M + 1) {
//		for (int i = 1; i <= M; i++) {
//			cout << arr[i] << ' ';
//		}
//		cout << '\n';
//		return;
//	}
//	
//	for (int i = 1; i <= N; i++) {
//		arr[k] = num[i]; //k번째 자리로 i번째 숫자 선택
//		func(k + 1); //k+1번째 자리 정하기
//	}
//}
//int main(void) {
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++)
//		cin >> num[i];
//	sort(num + 1, num + N + 1); //수열이 오름차순으로 나오게 하기 위해 오름차순 정렬
//	func(1); //1번째 자리를 선택할 차례
//
//	return 0;
//}