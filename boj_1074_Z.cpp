//#include<iostream>
//using namespace std;
//int cnt = 0;
//int n, r, c;
//void func(int len, int row, int col) {
//	//base condition: n = 2¿œ ∂ß
//	if (len == 2) {
//		if (row == r && col == c) {
//			cout << cnt << '\n';
//			return;
//		}
//		else
//			cnt++;
//
//		if (row == r && col + 1 == c)
//		{
//			cout << cnt << '\n';
//			return;
//		}
//		else
//			cnt++;
//
//		if (row + 1 == r && col == c)
//		{
//			cout << cnt << '\n';
//			return;
//		}
//		else
//			cnt++;
//
//		if (row + 1== r && col + 1 == c)
//		{
//			cout << cnt << '\n';
//			return;
//		}
//		else
//			cnt++;
//
//		return;
//		
//	}
//	func(len / 2, row, col);
//	func(len / 2, row, col + len / 2);
//	func(len / 2, row + len / 2, col);
//	func(len / 2, row + len / 2, col + len / 2);
//
//}
//int main(void) {
//
//	
//	cin >> n >> r >> c;
//	func(1 << n, 0, 0);
//
//	return 0;
//}