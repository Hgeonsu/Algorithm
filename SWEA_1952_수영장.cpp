
#include<iostream>
#define INF 987654321;
using namespace std;

int price[4], plan[15], Min = INF;

void dfs(int month, int fee) {
	if (month >= 12) {
		if (fee < Min) Min = fee;
		
		return;
	}
	
	//(month + 1)월 어떻게 낼건지 결정

	if (plan[month + 1] == 0) //그 달에 이용 내역이 없으면 비용 추가 없이 월 추가
		dfs(month + 1, fee);
	
	else {
		dfs(month + 1, fee + price[0] * plan[month + 1]); //1일
		dfs(month + 1, fee + price[1]); //1달
		dfs(month + 3, fee + price[2]); //3달
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		for (int i = 0; i < 4; i++)
			cin >> price[i]; // 1일, 1달, 3달 1년
		
		
		for (int i = 1; i <= 12; i++)
			cin >> plan[i];
		
		if (Min > price[3]) Min = price[3]; // 1년치
		
		dfs(0, 0);
		cout << "#" << tc << ' ' <<  Min << '\n';
		Min = INF; //Min 초기화
	}
	return 0;
}

