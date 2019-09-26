#pragma warning(disable :4996)
#include<iostream>
#include<string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	cin >> str;
	
	int i = 0, cnt = 0;
	while (i < str.length()) {

		if (str[i] == 'c') {
			if (i < str.length() - 1 &&  str[i + 1] == '=' || str[i + 1] == '-') 
				i += 2;
			else 
				i++;
			
			cnt++;
		}
		else if (str[i] == 'd') {
			if (i < str.length() - 2 && str[i + 1] == 'z' && str[i + 2] == '=') {
				i += 3;
			}
			else if (i < str.length() - 1 && str[i + 1] == '-') {
				i += 2;
			}
			else {
				i++;
			}
			cnt++;
		}
		else if (str[i] == 'l') {
			
			if (i < str.length() - 1 && str[i + 1] == 'j')
				i += 2;
			else
				i++;
			cnt++;
		}
		else if (str[i] == 'n' ) {
			if (i < str.length() - 1 && str[i + 1] == 'j')
				i += 2;
			else
				i++;
			cnt++;
		}
		else if (str[i] == 's' ) {
			if (i < str.length() - 1 && str[i + 1] == '=')
				i += 2;
			else
				i++;
			cnt++;
		}
		else if (str[i] == 'z' && str[i + 1] == '=') {
			if (str[i + 1] == '=')
				i += 2;
			else
				i++;
			cnt++;
		}
		else {
			cnt++;
			i++;
		}
	}
	cout << cnt;
	return 0;
}

