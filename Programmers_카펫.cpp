#pragma warning(disable :4996)
#include<iostream>
#include<vector>
using namespace std;

int Sum;
vector<int> solution(int br, int red) {
	vector<int> ans;

	Sum = br + red; //��ü ������ ��
	int h; //����
	for (int w = Sum; w >= 1; w--) {

		if (Sum % w == 0) {
			h = Sum / w;
			if (w < h) break; //���ΰ� ���κ��� ��ų� �������� �����
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
