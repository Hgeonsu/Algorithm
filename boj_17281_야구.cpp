//#include<iostream> //2�鸸
//#include<vector>
//using namespace std;
//int n, res[52][10], num[10], ord[10], pos[10], Max = -1;
//bool isused[10];
//void play() {
//	int hitter = 1, score = 0;
//	for (int i = 1; i <= n; i++) { //i�̴׿�
//		int outCnt = 0;
//
//		while (1) {
//			if (res[i][ord[hitter]] == 0) { //�ƿ��� ���
//				hitter++;
//				if (hitter >= 10) hitter = 1;
//				outCnt++;
//				if (outCnt == 3) {
//					//�̴� ��ü
//					for (int j = 1; j <= 9; j++) pos[j] = 0;
//					break;
//				}
//			}
//			else {
//				//����Ÿ
//				for (int j = 1; j <= 9; j++) {
//					if (pos[j] > 0 || j == ord[hitter]) { //Ÿ���� ���� �ִ� �������
//						pos[j] += res[i][ord[hitter]];
//						if (pos[j] >= 4) {
//							//Ȩ�� ������
//							pos[j] = 0;
//							score++;
//						}
//					}
//				}
//				hitter++;
//				if (hitter >= 10) hitter = 1;
//			}
//		}
//	}
//	if (Max < score) Max = score;
//}
//void func(int k) {
//	if (k > 9) { //base condition
//		play();
//		return;
//	}
//	for (int i = 2; i <= 9; i++) {
//		if (!isused[i]) {
//			ord[k] = i;
//			isused[i] = true;
//			if (k == 3) func(k + 2); //3���� ���� 4���� �ƴ϶� 5���� ����
//			else func(k + 1);
//			isused[i] = false;
//		}
//	}
//}
//int main(void) {
//	for (int i = 1; i <= 9; i++)
//		num[i] = i;
//	isused[1] = true; //1�� �׻� �����
//	ord[4] = 1; // 4�� ������ �׻� 1
//	cin >> n;
//	
//	for (int i = 1; i <= n; i++) 
//		for (int j = 1; j <= 9; j++) 
//			cin >> res[i][j];
//	
//	func(1);
//	cout << Max << '\n';
//	return 0;
//}