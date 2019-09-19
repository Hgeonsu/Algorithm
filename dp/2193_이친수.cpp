#include<iostream>
typedef long long ll;
using namespace std;

ll d[91]; //i자리 이친수의 개수
int main(void) {
	
	d[1] = 1; // 1
	d[2] = 1; //10
	for (int i = 3; i <= 90; i++) {
		d[i] = 1;
		for (int j = i - 2; j >= 1; j--) {
			d[i] += d[j]; 
		}//맨앞 1두면 바로옆은 무조건 0이고, 남은 자리에 이친수를 채워준다
	}
	
	int val;
	cin >> val;
	cout << d[val];
	return 0;
}