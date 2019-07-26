//#include<iostream>
//#include<algorithm>
//#include<set>
//#include<vector>
//using namespace std;
//int m, n, arr[7], num[7];
//set<vector<int > > st;
//vector<int> v;
//void func(int k) {
//	if (k == m) {
//		for (int i = 0; i < m; i++) {
//			v.push_back(arr[i]);
//		}
//		st.insert(v);
//		v.clear();
//		return;
//	}
//	for (int i = 0; i < n; i++) {
//		arr[k] = num[i];
//		func(k + 1);
//	}
//}
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//		cin >> num[i];
//	sort(num, num + 1);
//	func(0); //0번까지 채워져있다
//	set<vector<int> >::iterator itr;
//	for (itr = st.begin(); itr != st.end(); itr++) {
//		vector<int> tmp = *itr;
//		for (int i = 0; i < tmp.size(); i++)
//			cout << tmp[i] << ' ';
//		cout << '\n';
//	}
//	return 0;
//}