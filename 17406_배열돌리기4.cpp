////47m 소요
//#include<iostream>
//#include<limits.h>
//struct Spin {
//	int r, c, size;
//}sp[8];
//using namespace std;
//
//int R, C, k, m[51][51],tmp[51][51], arr[8];
//bool isused[8];
//int Min = INT_MAX;
//
//void spin(int val) {
//	int rr = sp[val].r, cc = sp[val].c, size = sp[val].size;
//	for (int l = 1; l <= size; l++) {
//		int leftHigh = m[rr - l][cc - l]; //위쪽 변 넣을때 마지막에 넣어주기
//		
//		for (int row = rr - l; row <= rr + l-1; row++)  //왼쪽 변
//			m[row][cc - l] = m[row+1][cc - l];
//	
//		for (int col = cc - l; col <= cc + l - 1; col++)  //아래쪽 변
//			m[rr + l][col] = m[rr + l][col + 1];
//		
//
//		for (int row = rr + l; row >= rr - l + 1; row--)  //우측 
//			m[row][cc + l] = m[row - 1][cc + l];
//		
//
//		for (int col = cc + l; col >= cc - l + 2; col--)  //상단
//			m[rr - l][col] = m[rr - l][col - 1];
//		
//		m[rr - l][cc - l + 1] = leftHigh; //기억해 놨던 맨 왼쪽 상단 값 넣어줌
//	}
//	
//}
//
//void calMin() {
//	int inMin = INT_MAX;
//	for (int i = 1; i <= R; i++) {
//		int Sum = 0;
//		for (int j = 1; j <= C; j++) 
//			Sum += m[i][j];
//		
//		if (inMin > Sum) inMin = Sum;
//	}
//	if (inMin < Min) Min = inMin;
//	
//}
//void init() {
//	for (int i = 1; i <= R; i++)
//		for (int j = 1; j <= C; j++)
//			m[i][j] = tmp[i][j];
//}
//void backTracking(int num) {
//	if (num == k) {
//		for (int i = 0; i < k; i++)
//			spin(arr[i]);
//		calMin();
//		
//		init(); //배열 돌리기 이전으로 초기화
//		return;
//	}
//	for (int i = 0; i < k; i++) {
//		if (!isused[i]) {
//			arr[num] = i;
//			isused[i] = true;
//			backTracking(num + 1);
//			isused[i] = false;
//		}
//	}
//}
//int main(void) {
//	cin >> R >> C >> k;
//	for (int i = 1; i <= R; i++) {
//		for (int j = 1; j <= C; j++) {
//			cin >> m[i][j];
//			tmp[i][j] = m[i][j];
//		}
//	}
//
//	for (int i = 0; i < k; i++) 
//		cin >> sp[i].r >> sp[i].c >> sp[i].size;
//	
//	backTracking(0);
//	cout << Min;
//	return 0;
//}