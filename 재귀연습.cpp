////N! 함수
///*
//#include<iostream>
//using namespace std;
//int facto(int n) {
//	if (n == 1) return 1;
//	return n * facto(n - 1);
//}
//int main(void) {
//	int n;
//	cin >> n;
//	cout << facto(n);
//	return 0;
//}*/
//#include<iostream>
//#include<math.h>
//using namespace std;
//
//void hanoi(int src, int dst, int n) {
//	if (n == 1) {
//		cout << src << ' ' << dst << '\n';
//		return;
//	}
//	int temp = 6 - src - dst;
//	hanoi(src, temp, n - 1); //1 ~ n-1 링을 중간지점에 옮긴다
//	cout << src << ' ' << dst << '\n'; //가장 커다란 링을 목적지로 옮긴다.
//	hanoi(temp, dst, n - 1); //중간지점에 있던 n - 1 개의 링들을 목적지로 옮긴다.
//}
//
//int main(void) {
//	int n;
//	cin >> n; //옮기는 링의 개수
//	//cout << pow(2, n) - 1 << '\n';// 이렇게 쓰면 틀림 n = 20일때 output이 이상해짐
//	cout << (1 << n) - 1 << '\n'; // 2의 n승 -1
//	//hanoi(1, 3, n);
//
//	return 0;
//}