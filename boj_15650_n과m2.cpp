//#include<iostream>
//using namespace std;
//int N, M;
//void func(int* arr, bool* used, int k) {
//	//base condition
//	if (k == M) {
//		for (int i = 1; i <= k; i++)
//			cout << arr[i] << ' ';
//		cout << '\n';
//		return;
//	}
//	
//	int init;
//	if (k == 0) init = 1;
//	else
//		init = arr[k] + 1;
//
//	for (int i = init; i <= N; i++) {
//		if (!used[i]) {
//			arr[k + 1] = i;
//			used[i] = true;
//			func(arr, used, k + 1);
//			used[i] = false;
//		}
//	}
//}
//int main(void) {
//	
//	cin >> N >> M;
//	
//	int arr[10]; //���� 8�� �ִ� 1 - indexed
//	bool used[10]; // 1~9
//
//	for (int i = 1; i <= 9; i++) {
//		arr[i] = 0;
//		used[i] = false;
//	}
//	
//	func(arr, used, 0);// 0��° �ڸ����� �� ��������. �̹��� 1��° �ڸ� ���� ���ʴ�
//	return 0;
//}