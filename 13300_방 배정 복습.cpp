//#include<iostream>
//using namespace std;
//
//int arr[2][7];
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	int n, k;
//	cin >> n >> k;
//
//	int s, y;
//	while (n--) { //n���� ������ 2���� �迭�� ����
//		cin >> s >> y;
//		arr[s][y]++;
//	}
//
//	int room = 0;
//
//	for (int i = 0; i < 2; i++) {
//		for (int j = 1; j <= 6; j++) {
//			if (!arr[i][j]) //Ư�� �г�� ������ �л����� 0�̸� continue
//				continue;
//			
//			if (arr[i][j] < k) // k���� �����Ƿ� ���� �ϳ��� ������ ��
//				room++;
//			else { //k���� ũ�ų� ���� ��
//				if (arr[i][j] % k == 0) {
//					//k�� ���� ������ ��
//					room = room + arr[i][j] / k;
//				}
//				else {
//					room = room + arr[i][j] / k + 1;
//				}
//			}
//		}
//	}
//
//	cout << room << '\n';
//
//	return 0;
//}
