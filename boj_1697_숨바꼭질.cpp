//#include<iostream>
//#include<queue>
//using namespace std;
//int n, k;
//int vis[300000];
//queue<int> q;
//int sec = 0;
//void bfs(int start) {
//	q.push(start);
//	vis[start]++;
//
//	while (!q.empty()) {
//		int cur = q.front();
//		q.pop();
//		for (int i = 0; i < 3; i++) {
//			int np;
//			if (i == 0)
//				np = cur - 1;
//			else if (i == 1)
//				np = cur + 1;
//			else
//				np = 2 * cur;
//
//			if (np < 0 || np > 100000 || vis[np] >= 0) continue;
//
//			q.push(np);
//			vis[np] = vis[cur] + 1;
//			if (np == k) return;
//		}
//	}
//}
//int main(void) {
//	cin >> n >> k;
//	for (int i = 0; i < 300000; i++)
//		vis[i] = -1;
//	bfs(n);
//	cout << '\n';
//	for (int i = 0; i < 30; i++)
//		printf("%d ¿¡¼­ %d\n", i, vis[i]);
//	cout << '\n';
//	cout << vis[k] << '\n';
//	return 0;
//}
