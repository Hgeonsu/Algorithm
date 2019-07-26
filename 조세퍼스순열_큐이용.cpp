//#include<iostream>
//#include<queue>
//using namespace std;
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	queue<int> q;
//	int n, k;
//	
//	cin >> n >> k;
//	for (int i = 1; i <= n; i++)
//		q.push(i);
//
//	cout << '<';
//	while (n--) {
//
//		for (int i = 0; i < k - 1; i++) { //pop할 때, 한번의 건너뛰는 효과를 볼 수 있다. 그래서 k-1번만 건너뛴다.
//			q.push(q.front()); //front에 있는 것을 다시 push 해주고
//			q.pop(); //삭제해주면 위로 올리는 효과
//		}
//		cout << q.front();
//		q.pop();
//		if (!q.empty())
//			cout << ", ";
//	}
//	cout << '>';
//
//	return 0;
//}