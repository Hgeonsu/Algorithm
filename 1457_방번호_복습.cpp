//#include<iostream>
//#include<string>
//using namespace std;
//
//int arr[10];
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	string s = to_string(n); //각 숫자의 개수를 파악하기 위해 string으로 변환
//
//	for (int i = 0; i < s.length(); i++) //개수 파악
//		arr[s[i] - '0']++;
//
//	int sum69 = 0, max = -1;
//	for (int i = 0; i < 10; i++) { //6과 9의 개수를 파악
//		if (i == 6 || i == 9)
//			sum69 = sum69 + arr[i];
//		else {
//			if (arr[i] > max) //6과 9를 제외한 숫자의 최대의 빈도 파악
//				max = arr[i];
//		}
//	}
//	if (sum69 % 2 == 0) {
//		sum69 = sum69 / 2;
//	}
//	else {
//		sum69 = sum69 / 2 + 1;
//	}
//	if (sum69 > max) {
//		cout << sum69;
//	}
//	else {
//		cout << max;
//	}
//
//	return 0;
//}
