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
//		foods.push_back({ ft[i], i + 1 }); //������ ��ȣ�� 1����
//	
//	sort(foods.begin(), foods.end());
//	int remain = foods.size();
//	ll spend, preTime = 0; //spend = �� �������� �ѹ��� ���� �� �ִ� �ð�, pretime = ������ �ô� ������ �ҿ� �ð�
//	for (vector<pii>::iterator itr = foods.begin(); itr != foods.end(); itr++, remain--) {
//		spend = (itr->first-preTime) * remain;
//		preTime = itr->first;
//		if (spend == 0) continue;
//		else if (spend <= k) { //�ѹ��� spend��ŭ ���� �� ������
//			k -= spend;
//		}
//		else { //�ѹ��� ���� �� �ִ� �纸�� k�� ������
//			sort(itr, foods.end(), cmp);//�ٽ� ���ĵ� ����ġ�� ����
//			k %= remain;
//			return (itr + k)->second;
//		}
//	}
//	return -1; //���� �� �ִ� �� ���, spend�� k���� Ŀ���� ����, ��� 0�̶� ��ŵ�� ���
//}
//int main(void) {
//	vector<int> v;
//	v = { 3,5,1,6,5,3 };
//	int k = 20;
//	solution(v, 20);
//	return 0;
//}