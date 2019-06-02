#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		v.push_back(i + 1);
	}
	
	int pos = k - 1;

	cout << "<";
	while (!v.empty()) {
		
		cout << v[pos];
		if (v.size() > 1)
			cout << ", ";
		else
			cout << ">";

		v.erase(v.begin() + pos);
	
		pos = pos + k - 1;
		while (pos >= v.size()) {
			pos = pos - v.size();
			if (v.empty())break;
		}
		
	}
	return 0;
}
/*
링크드리스트 쓰고 싶지 않고 벡터로 풀 수 있음
삭제 지점인 pos를 한 번 수정해도 벡터의 size 보다 큰 경우가 있어서 RTE가 발생할 수 있음
size보다 작아질 때까지 pos를 수정해줘야함
*/