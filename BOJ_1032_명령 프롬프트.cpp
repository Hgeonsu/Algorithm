#pragma warning(disable :4996)
#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> v;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//ù �Է����� �ʱ�ȭ �ϰ�, �ٸ� �κ� ?�� �� �ٲٱ�(�̹� ?�� �ƴ� ��쿡)
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

