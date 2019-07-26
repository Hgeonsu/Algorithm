//#define ll long long
//#include<iostream>
//#include<vector>
//using namespace std;
//
//ll lmax[300001], rmin[300001];
//int solution(vector<int> &T) {
//	ll Max = T[0];
//	for (int i = 0; i < T.size(); i++) {
//		if (T[i] > Max)
//			Max = T[i];
//		lmax[i] = Max;
//	}
//
//	ll Min = T.at(T.size() - 1);
//	for (int i = T.size() - 1; i >= 0; i--) {
//		if (T[i] < Min)
//			Min = T[i];
//		rmin[i] = Min;
//	}
//
//	for (int i = 0; i < T.size() - 1; i++) {
//		if (lmax[i] < rmin[i + 1]) {
//			//len = i + 1;
//			return i + 1;
//		}
//	}
//}
//int main(void) {
//	vector<int> vec{ -5, -5, -5, -42, 6, 12 };
//	solution(vec);
//	return 0;
//}