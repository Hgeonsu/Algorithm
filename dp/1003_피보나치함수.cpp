#include<iostream>
using namespace std;

int zero[41], one[41];
int main(void) {
	
	zero[0] = 1;
	zero[1] = 0;
	zero[2] = 1;
	one[0] = 0;
	one[1] = 1;
	one[2] = 1;
	
	for (int i = 3; i < 41; i++) {
		zero[i] = zero[i - 1] + zero[i - 2];
		one[i] = one[i - 1] + one[i - 2];
	}
	int n;
	cin >> n;
	while (n--) {
		int val;
		cin >> val;
		cout << zero[val] << ' ' << one[val] << '\n';
	}
	return 0;
}