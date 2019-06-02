#include<iostream>
#include<string>
using namespace std;
int A, B, C, arr[10];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B >> C;
	long long res = A * B*C;	
	string str = to_string(res);
	for (int i = 0; i < str.length(); i++) {
		arr[str[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}
/*
각 자리수의 숫자를 확인하기 위해 계산 결과를 long long에서 string 으로 변환
string으로 변환된 값의 각 자리수인 char에서 int로 변환을 -'0'을 활용
*/