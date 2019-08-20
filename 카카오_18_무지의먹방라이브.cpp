//#include <string>
//#include <vector>
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//typedef pair<int, int> pii;
//typedef long long ll;
//
//bool cmp(pii a, pii b) {
//	return a.second < b.second;
//}
//int solution(vector<int> ft, long long k) {
//	vector<pii> foods;
//	for (int i = 0; i < ft.size(); i++) 
//		foods.push_back({ ft[i], i + 1 }); //음식의 번호는 1부터
//	
//	sort(foods.begin(), foods.end());
//	int remain = foods.size();
//	ll spend, preTime = 0; //spend = 현 시점에서 한번에 지울 수 있는 시간, pretime = 이전에 봤던 음식의 소요 시간
//	for (vector<pii>::iterator itr = foods.begin(); itr != foods.end(); itr++, remain--) {
//		spend = (itr->first-preTime) * remain;
//		preTime = itr->first;
//		if (spend == 0) continue;
//		else if (spend <= k) { //한번에 spend만큼 지울 수 있으면
//			k -= spend;
//		}
//		else { //한번에 먹을 수 있는 양보다 k가 작으면
//			sort(itr, foods.end(), cmp);//다시 음식들 원위치로 정렬
//			k %= remain;
//			return (itr + k)->second;
//		}
//	}
//	return -1; //먹을 수 있는 게 없어서, spend가 k보다 커진적 없이, 계속 0이라 스킵된 경우
//}
//int main(void) {
//	vector<int> v;
//	v = { 3,5,1,6,5,3 };
//	int k = 20;
//	solution(v, 20);
//	return 0;
//}