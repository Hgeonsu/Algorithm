#include<iostream>
#include<string>

using namespace std;

string ans = "";
int main(void) {
	string str, bomb;
	cin >> str >> bomb;
	
	int k = 0; //str의 길이만큼 확인 (확인할 인덱스)
	while (k < (int)str.length()) {

		//단어폭탄의 마지막 문자와 같으면서, 단어 폭탄의 길이 이상의 단어가 ans 문자열에 들어 있을 때만 검사
		if (str[k] == bomb[bomb.length() - 1] && ans.length() >= bomb.length()-1) {
			bool isBomb = true;
			int idx = 0;
			for (int j = 1; j <= bomb.length()-1; j++) { //마지막 문자는 어짜피 같으니까, 제외하고 검사
				if (ans[ans.length() - bomb.length() + j] != bomb[idx]) {
					isBomb = false;
					break;
				}
				else
					idx++;
			}
			if (isBomb) { //단어 폭탄인 경우 
				for (int i = 0; i < bomb.length() - 1; i++)
					ans.pop_back();
			}
			else //폭탄검사를 했는데 아닌 경우
				ans += str[k];
		}
		else { //단어 폭탄의 마지막 철자와 글자가 달랐던 (평범한) 경우
			ans += str[k];
		}
		k++; //확인하는 문자열 위치 증가
	}
	if ((int)ans.length() != 0)
		cout << ans;
	else
		cout << "FRULA"; 
	return 0;
}