//#include<iostream>
//#include<vector>
//#include<unordered_set>
//#include<set>
//using namespace std;
//int N, M, arr[9], n[9];
//bool isused[9];
//set<vector<int> > st;
//vector<int> v;
//void func(int k) {
//
//	if (k == M + 1) {
//		for (int i = 1; i <= M; i++) {
//			v.push_back(arr[i]);
//		}
//		st.insert(v);
//		v.clear();
//		return;
//	}
//
//	for (int i = 1; i <= N; i++) {
//		if (!isused[i] && arr[k - 1] <= n[i]) {
//			isused[i] = true;
//			arr[k] = n[i];
//			func(k + 1);
//			isused[i] = false;
//		}
//	}
//}
//int main() {
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++) {
//		cin >> n[i];
//	}
//	func(1);
//	for (set<vector<int> >::iterator it = st.begin(); it != st.end(); it++) {
//		for (int i = 0; i < (*it).size(); i++) {
//			cout << (*it)[i] << ' ';
//		}
//		cout << '\n';
//	}
//	return 0;
//}