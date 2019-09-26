#pragma warning(disable :4996)
#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

set<string> lis;
vector<string> see;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		lis.insert(temp);
	}
	
	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;
		if (lis.find(temp) != lis.end()) //lis set에 존재하면 결과에 push
			see.push_back(temp);
	}
	
	sort(see.begin(), see.end());

	for (int i = 0; i < see.size(); i++)
		cout << see[i] << '\n';
	
	return 0;
}

