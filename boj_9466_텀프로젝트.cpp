///*
//방문한적 없으면 방문
//방문처리
//다음방문(방문이 끝나면 방문 확정처리)
//이미 방문한 적이 있는 지점 -> 사이클
//방문 확정처리 된 지점 or 사이클로 판정된 지점 -> 더 이상 진행할 필요가 없음
//*/
//#include<iostream>
//using namespace std;
//int stu[100001], vis[100001];
//bool Done[100001];
//int n, cnt = 0;
//void cycle(int k) {
//	if (Done[k] == true || vis[k] == -1)
//		return;
//
//	if (vis[k] == 0)
//		vis[k] = 1;
//	else if (vis[k] == 1) {
//		Done[k] = true;
//		cnt++;
//	}
//	cycle(stu[k]);
//	vis[k] = -1;
//}
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	int T;
//	cin >> T;
//	while (T--) {
//		
//		cin >> n;
//		for (int i = 1; i <= n; i++)
//			cin >> stu[i];
//		for (int i = 1; i <= n; i++) {
//			if (vis[i] == 0)
//				cycle(i);
//		}
//		cout << n -cnt << '\n';
//		
//		for (int i = 1; i <= n; i++) {
//			stu[i] = 0;
//			vis[i] = 0;
//			Done[i] = false;
//		}
//		cnt = 0;
//	}
//	return 0;
//}