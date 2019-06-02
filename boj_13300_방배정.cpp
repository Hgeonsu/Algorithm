#include<iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int map[3][7] = { 0, };

	int n, max; 
	cin >> n >> max;

	int s, grade;
	for (int i = 0; i < n; i++) {
		cin >> s >> grade;
		map[s][grade]++;
	}
	int cnt = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= 6; j++) {
			if (map[i][j] == 0)
				continue;
			if (map[i][j] % max == 0) {
				cnt = cnt + map[i][j] / max;
			}
			else {
				cnt = cnt + map[i][j] / max + 1;
			}
		}
	}
	cout << cnt << '\n';

	return 0;
}
/*학년과 성별으로 이차원 배열 정의.
인원을 최대 인원으로 나눈 나머지가 0인지 0이 아닌지에 따라서 경우를 나눔
*/