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
//	while (n--) { //n명의 정보를 2차원 배열에 저장
//		cin >> s >> y;
//		arr[s][y]++;
//	}
//
//	int room = 0;
//
//	for (int i = 0; i < 2; i++) {
//		for (int j = 1; j <= 6; j++) {
//			if (!arr[i][j]) //특정 학년과 성별의 학생수가 0이면 continue
//				continue;
//			
//			if (arr[i][j] < k) // k보다 작으므로 방은 하나만 있으면 됨
//				room++;
//			else { //k보다 크거나 같을 때
//				if (arr[i][j] % k == 0) {
//					//k로 나눠 떨어질 때
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
