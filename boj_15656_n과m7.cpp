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
//		arr[k] = num[i]; //k��° �ڸ��� i��° ���� ����
//		func(k + 1); //k+1��° �ڸ� ���ϱ�
//	}
//}
//int main(void) {
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++)
//		cin >> num[i];
//	sort(num + 1, num + N + 1); //������ ������������ ������ �ϱ� ���� �������� ����
//	func(1); //1��° �ڸ��� ������ ����
//
//	return 0;
//}