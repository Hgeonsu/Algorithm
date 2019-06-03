#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string org, cpr;
	int orgA[26] = { 0, }, cprA[26] = { 0, };

	cin >> org >> cpr;

	for (int i = 0; i < org.length(); i++) {
		orgA[org[i] - 'a']++;
	}
	for (int i = 0; i < cpr.length(); i++) {
		cprA[cpr[i] - 'a']++;
	}

	int cnt = 0;
	
	for (int i = 0; i < 26; i++) {
		cnt = cnt + abs(orgA[i] - cprA[i]);
	}
	cout << cnt << '\n';

	return 0;
}
/*
strfry와 같은 원리. 단어에 쓰인 알파벳별 개수를 파악해서 비교.
입력 문자열의 길이가 다른 경우도 생각해줘야함
*/