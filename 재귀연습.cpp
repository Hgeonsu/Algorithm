////N! �Լ�
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
//	hanoi(src, temp, n - 1); //1 ~ n-1 ���� �߰������� �ű��
//	cout << src << ' ' << dst << '\n'; //���� Ŀ�ٶ� ���� �������� �ű��.
//	hanoi(temp, dst, n - 1); //�߰������� �ִ� n - 1 ���� ������ �������� �ű��.
//}
//
//int main(void) {
//	int n;
//	cin >> n; //�ű�� ���� ����
//	//cout << pow(2, n) - 1 << '\n';// �̷��� ���� Ʋ�� n = 20�϶� output�� �̻�����
//	cout << (1 << n) - 1 << '\n'; // 2�� n�� -1
//	//hanoi(1, 3, n);
//
//	return 0;
//}