#pragma warning(disable :4996)
#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> v;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//첫 입력으로 초기화 하고, 다른 부분 ?로 다 바꾸기(이미 ?가 아닌 경우에)
	int n;
	cin >> n;
	string str;
	cin >> str;
	for (int i = 0; i < n - 1; i++) {
		string val;
		cin >> val;
		
		for (int i = 0; i < str.length(); i++) {
			if (str[i] != '?' && str[i] != val[i])
				str[i] = '?';
		}

	}
	cout << str;
	return 0;
}

