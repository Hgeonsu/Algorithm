#pragma warning(disable :4996)
#include<iostream>
#include<string>
using namespace std;

int alp[26];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	
	int n, ret = 0;
	cin >> n;
	while (n--) {
		cin >> str;
		bool isBreak = false;
		for (int i = 0; i < str.length(); i++) {
			if (alp[str[i] - 'a'] > 0 && str[i] != str[i-1]) {
				isBreak = true;
				break; //이전 문자와 다른데, 이전에 나온적이 있는 단어인 경우
			}
			alp[str[i] - 'a']++;
		}
		if (!isBreak) 
			ret++;

		for (int i = 0; i < 26; i++)
			alp[i] = 0;
	}
	cout << ret;
	return 0;
}
