//#include<iostream>
//
//using namespace std;
//typedef long long ll;
//const int INF = 1000000;
//int main(void) {
//	ll arr[100001];
//	double s;
//	int n;
//	cin >> n >> s;
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//	
//	int l = 0, h = 0, len = 0, Min = INF;
//	ll Sum = 0;
//	while (1) {
//		if (Sum < s) {
//			if (h > n - 1) break; //h가 n인데, 쿼리를 실행하게 하면 안된다
//			Sum += arr[h];
//			h++;
//			len++;
//		}
//		else {
//			if (len < Min) Min = len;
//			
//			Sum -= arr[l];
//			l++; 
//			len--;
//		}
//	}
//	if (Min != INF)
//		cout << Min << '\n';
//	else
//		cout << 0 << '\n';
//	
//	return 0;
//}