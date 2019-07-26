//#include<iostream>
//#include<vector>
//#include<math.h>
//using namespace std;
//
//char arr[2188][2188] = { ' ', };
//
//void func(int len, int row, int col) {
//	if (len == 3) {
//		int cur = 0;
//		for (int i = row; i < row + len; i++) {
//			for (int j = col; j < col + len; j++) {
//				if (cur == 4) {
//					cur++;
//					continue;
//				}
//				arr[i][j] = '*';
//				cur++;
//			}
//		}
//		return;
//	}
//	func(len / 3, row, col);
//	func(len / 3, row, col + len / 3);
//	func(len / 3, row, col + len / 3 * 2);
//	func(len / 3, row + len / 3, col);
//	//func(len / 3, row + len / 3, col + len / 3, ' ');
//	func(len / 3, row + len / 3, col + len / 3 * 2);
//	func(len / 3, row + len / 3 * 2, col);
//	func(len / 3, row + len / 3 * 2, col + len / 3);
//	func(len / 3, row + len / 3 * 2, col + len / 3 * 2);
//
//}
//int main(void) {
//	
//	//cout << pow(3, 7);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	int n;
//	cin >> n;
//	func(n, 0, 0);
//	
//	//별이 아닌 부분 공백으로 채워줘야한다.
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (arr[i][j] != '*')
//				arr[i][j] = ' ';
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << arr[i][j];
//		}
//		cout << '\n';
//	}
//	return 0;
//}