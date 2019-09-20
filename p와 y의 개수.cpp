#include <string>
#include <iostream>
#include<algorithm>
using namespace std;

int cnt[2];
bool solution(string s)
{
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'p') cnt[0]++;
		else if (s[i] == 'y') cnt[1]++;
	}
	if (cnt[0] == cnt[1]) return 1;
	else return 0;

}

int main(void) {
	solution("pPoooyY");
	return 0;
}