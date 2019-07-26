//#include<iostream>
//using namespace std;
//char arr[3073][6145];
//void func(int n, int r, int c) {
//	//base condition
//	if (n == 3) {
//		arr[r][c] = '*';
//		arr[r + 1][c - 1] = '*';
//		arr[r + 1][c + 1] = '*';
//		for (int i = c-2; i <= c+2; i++)
//			arr[r + 2][i] = '*';
//		return;
//	}
//	
//	func(n / 2, r, c);
//	func(n / 2, r + n / 2, c - n / 2);
//	func(n / 2, r + n / 2, c + n / 2);
//	
//}
//int main(void) {
//	
//	int N;
//	cin >> N;
//
//	//1-indexed;
//
//	func(N,1, N); //n, row, col
//	
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= 2 * N - 1; j++) {
//			if (arr[i][j] != '*')
//				arr[i][j] = ' ';
//		}
//	}
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= 2 * N - 1; j++) {
//			cout << arr[i][j];
//		}
//		cout << '\n';
//	}
//	return 0;
//
//}