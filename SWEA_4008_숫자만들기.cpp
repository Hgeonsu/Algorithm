#include<vector>
#include<iostream>
#include<set>
#include<climits>
using namespace std;
int n;
long long Min = LONG_MAX;
long long Max = LONG_MAX * -1;
vector<int> opr;
vector<int> arr;

set<vector<int> > st;
int num[13];
bool used[13];

void pick(int k) {
	if (k == n - 1) {
		long long res = num[0];
		for (int i = 0; i < arr.size(); i++) {
			int cmd = arr[i];

			if (cmd == 0)
				res += num[i + 1];
			else if (cmd == 1)
				res -= num[i + 1];
			else if (cmd == 2)
				res *= num[i + 1];
			else
				res /= num[i + 1];
		}

		if (res < Min) Min = res;
		if (res > Max) Max = res;
		//st.insert(arr);
		return;
	}
	

	for (int i = 0; i < 4; i++) {
		if (opr[i] > 0) {
			arr[k] = i;
			opr[i]--;
			pick(k + 1);
			opr[i]++;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;

		//더하기, 뺴기, 곱하기, 나누기
		for (int i = 0; i < 4; i++) {
			int cnt;
			cin >> cnt;
			
			opr.push_back(cnt);
		}
		for (int i = 0; i < n; i++)
			cin >> num[i];
	
		for (int i = 0; i < n - 1; i++)
			arr.push_back(0);

		pick(0);
		

		long long dif = Max - Min;
		if (dif < 0) dif *= -1;
		cout << "#" << tc << ' ' << dif << '\n';

		Min = LONG_MAX;
		Max = LONG_MAX * -1;
		opr.clear();
		st.clear();
		arr.clear();
	}
	return 0;
}

