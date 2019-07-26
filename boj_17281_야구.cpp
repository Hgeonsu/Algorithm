//#include<iostream> //2백만
//#include<vector>
//using namespace std;
//int n, res[52][10], num[10], ord[10], pos[10], Max = -1;
//bool isused[10];
//void play() {
//	int hitter = 1, score = 0;
//	for (int i = 1; i <= n; i++) { //i이닝에
//		int outCnt = 0;
//
//		while (1) {
//			if (res[i][ord[hitter]] == 0) { //아웃인 경우
//				hitter++;
//				if (hitter >= 10) hitter = 1;
//				outCnt++;
//				if (outCnt == 3) {
//					//이닝 교체
//					for (int j = 1; j <= 9; j++) pos[j] = 0;
//					break;
//				}
//			}
//			else {
//				//득점타
//				for (int j = 1; j <= 9; j++) {
//					if (pos[j] > 0 || j == ord[hitter]) { //타석에 나가 있는 선수라면
//						pos[j] += res[i][ord[hitter]];
//						if (pos[j] >= 4) {
//							//홈에 들어오면
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
//			if (k == 3) func(k + 2); //3번엔 다음 4번이 아니라 5번을 정함
//			else func(k + 1);
//			isused[i] = false;
//		}
//	}
//}
//int main(void) {
//	for (int i = 1; i <= 9; i++)
//		num[i] = i;
//	isused[1] = true; //1은 항상 사용중
//	ord[4] = 1; // 4번 선수는 항상 1
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