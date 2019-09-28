#pragma warning(disable :4996)
#include<iostream>
#include<vector>
using namespace std;

int Sum;
vector<int> solution(int br, int red) {
	vector<int> ans;

	Sum = br + red; //전체 격자의 수
	int h; //높이
	for (int w = Sum; w >= 1; w--) {

		if (Sum % w == 0) {
			h = Sum / w;
			if (w < h) break; //가로가 세로보다 길거나 같을때만 보면됨
			if ((w - 2)*(h - 2) == red) {
				ans.push_back(w);
				ans.push_back(h);
			}
		}
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solution(5000, 2000000);
	return 0;
}
