#pragma warning(disable :4996)
#include<iostream>
#include<string>
using namespace std;
int alp[26];
int main(void) {
	//ios::sync_with_stdio(false);
	cin.tie(0);
	
	string str;
	cin >> str;

	for (int i = 0; i < 26; i++)
		alp[i] = -1;
	for (int i = 0; i < str.length(); i++) {
		if (alp[str[i] - 'a'] == -1)
			alp[str[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++)
		if (alp[i] >= 0) cout << alp[i] << ' ';
		else
			cout << -1 << ' ';

	return 0;
}
