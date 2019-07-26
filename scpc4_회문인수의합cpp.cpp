//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//using namespace std;
//vector<int> v; //회문수 벡터
//int res[3];
////int sol(int n) {
////	int cnt = 0;
////	
////	for (int i = 0; i < v.size(); i++) {
////		if (v[i] == n &&( cnt == 0 || cnt == 2 || cnt == 3)) {
////			if (cnt == 0 || cnt == 2 || cnt == 3) {
////				cnt = 1;
////				res[0] = i;
////			}
////			//printf("\ncnt = %d i j k %d\n", cnt, i);
////			//return cnt;
////		}
////		for (int j = 0; j < v.size(); j++) {
////			if (v[i] + v[j] == n &&( cnt == 0 || cnt == 3)) {
////				cnt = 2;
////				res[0] = i;
////				res[1] = j;
////				//printf("\ncnt = %d i j k %d %d\n", cnt, i, j);
////				//return cnt;
////			}
////			for (int k = 0; k < v.size(); k++) {
////				if (v[i] + v[j] + v[k] == n &&( cnt == 0 || cnt == 3)) {
////					cnt = 3;
////					res[0] = i;
////					res[1] = j;
////					res[2] = k;
////					//printf("\ncnt = %d i j k %d %d %d\n", cnt, i, j, k);
////					//return cnt;
////				}
////			}
////		}
////	}
////	return cnt;
////}
//int fir(int n) {
//	for (int i = 0; i < v.size(); i++) {
//		if (v[i] == n) {
//			cout << 1 << ' ' << v[i] << '\n';
//			return 1;
//		}
//	}
//	return 0;
//}
//int sec(int n) {
//	for (int i = 0; i < v.size(); i++) {
//		for (int j = 0; j < v.size(); j++) {
//			if (v[i] + v[j] == n) {
//				cout << 2 << ' ' << v[j] << ' ' << v[i] << '\n';
//				return 1;
//			}
//		}
//	}
//	return 0;
//}
//int thi(int n) {
//	for (int i = 0; i < v.size(); i++) {
//		for (int j = 0; j < v.size(); j++) {
//			for (int k = 0; k < v.size(); k++) {
//				if (v[i] + v[j] + v[k] == n) {
//					cout << 3 << ' ' << v[k] << ' ' << v[j] << ' ' << v[i] << '\n';
//					return 1;
//				}
//			}
//		}
//	}
//	return 0;
//}
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	int tc;
//	cin >> tc;
//	for (int t = 1; t <= tc; t++) {
//		int n;
//		cin >> n;
//		//모든 회문수 구하기
//		
//		for (int i = 1; i <= 10000; i++) {
//			string str = to_string(i);
//			int len = str.length();
//			bool isCir = true;
//			for (int j = 0; j < len/2; j++) {
//				if (str[j] != str[len - 1 - j]) {
//					isCir = false;
//					break;
//				}
//			}
//			if (isCir)
//				v.push_back(i);
//		}
//		
//		cout << "Case #" << t << '\n';
//		if (fir(n) == 1)
//			continue;
//		else if (sec(n) == 1)
//			continue;
//		else if (thi(n) == 1)
//			continue;
//		else
//		{
//			cout << 0 << '\n';
//		}
//	}
//
//	
//	return 0;
//}
