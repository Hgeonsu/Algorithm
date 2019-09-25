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
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z')
			alp[str[i] - 'a']++;
		else
			alp[str[i] - 'A']++;
	}
	/*for (int i = 0; i < 26; i++) {
		cout << alp[i] << ' ';
	}
	cout << '\n';*/
	int Max = 0, idx =0;
	for (int i = 0; i < 26; i++) {
		if (Max < alp[i]) {
			idx = i;
			Max = alp[i];
		}
	}
	//cout << idx;
	for (int i = 0; i < 26; i++) {
		if (alp[i] == Max && i != idx) {
			//cout << (char)(alp[i] + 'a') << '\n';
			cout << "?";
			return 0;
		}
	}
	char ans = idx + 'A';
	cout << ans;
	return 0;
}
