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
//		for (int i = 0; i < k - 1; i++) { //pop�� ��, �ѹ��� �ǳʶٴ� ȿ���� �� �� �ִ�. �׷��� k-1���� �ǳʶڴ�.
//			q.push(q.front()); //front�� �ִ� ���� �ٽ� push ���ְ�
//			q.pop(); //�������ָ� ���� �ø��� ȿ��
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