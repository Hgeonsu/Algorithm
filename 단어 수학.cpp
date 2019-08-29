#pragma warning(disable :4996)
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int cnt[26], n;

bool cmp(int a, int b) {
	return a > b;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;

	vector<string> wrd;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		wrd.push_back(tmp);
	}

	
	for (int i = 0; i < wrd.size(); i++) {
		int val = 1; //°¡ÁßÄ¡
		for (int j = wrd[i].length()-1; j >= 0; j--) {
			cnt[wrd[i][j] - 'A'] += val;
			val *= 10;
		}
	}
	

	vector<int> usedAlpha;
	for (int i = 0; i < 26; i++) 
		if (cnt[i] > 0) 
			usedAlpha.push_back(cnt[i]);
	
	
	sort(usedAlpha.begin(), usedAlpha.end(), cmp);
	
	ll ans = 0; int num = 9;
	for (int i = 0; i < usedAlpha.size(); i++)
		ans += usedAlpha[i] * num--;

	cout << ans;

	return 0;
}
