//#include<iostream>
//#include<algorithm>
//using namespace std;
//int n, num[50], arr[7];
//bool isused[50];
//int st;
//void func(int k) {
//	//���⼭ ������ ���� k
//	if (k == 6) {
//		for (int i = 0; i < k; i++) {
//			cout << arr[i] << ' ';
//		}
//		cout << '\n';
//		return;
//	}
//	
//	if (k == 0) st = 0; //0�϶� �ʱ�ȭ
//	for (int i = st; i < n; i++) { //�������� ����� ���� st����. 0���� ������ ����(������ �ٸ��� �ٸ� ����)
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