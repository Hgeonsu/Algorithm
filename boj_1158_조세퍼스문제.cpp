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
��ũ�帮��Ʈ ���� ���� �ʰ� ���ͷ� Ǯ �� ����
���� ������ pos�� �� �� �����ص� ������ size ���� ū ��찡 �־ RTE�� �߻��� �� ����
size���� �۾��� ������ pos�� �����������
*/