#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define INF 987654321

int Min = INF;
int food[18][18], arr[2];
int st = 1, n;
bool used[18], usedP[18];

vector<int> candi, others;
int Sum = 0;

void per(int K, vector<int>& useable) {
	if (K == 2) {
		Sum += food[arr[0]][arr[1]]; //실제로 시너지 계산하는 부분
		return;
	}
	
	for (int i = 0; i < useable.size(); i++) {
		if (!usedP[i]) {
			arr[K] = useable[i];
			usedP[i] = true;
			per(K + 1, useable);
			usedP[i] = false;
		}
	}
}
void com(int k, int goal) {
	if (k == goal) { //n/2개 뽑으면

		////candi에서 2개 순열로 뽑아서 시너지 계산
		Sum = 0;
		per(0, candi);
		int sumA = Sum;
		
		
		//다른 음식에 쓰이는 재료도 마찬가지로 시너지 계산
		others.clear();
		for (int i = 1; i <= n; i++) 
			if (!used[i]) others.push_back(i);
		

		Sum = 0;
		per(0, others);
		int sumB = Sum;

		int dif = abs(sumA - sumB);
		if (dif < Min) Min = dif; //맛의 차이 업데이트

		return;
	}

	if (k == 0) st = 1;
	for (int i = st; i <= n; i++) {
		if (!used[i]) {
			st = i;
			used[i] = true;
			candi.push_back(i); //음식 하나에 쓰일 재료에 추가
			com(k + 1, goal);
			used[i] = false;
			candi.pop_back();
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
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> food[i][j];
		
		com(0, n / 2); //절반을 조합으로 뽑는다(음식 하나에 쓰일 재료 선택)

		cout << "#" << tc << ' ' << Min << '\n';
		Min = INF;
		candi.clear();
		
	}

	return 0;
}

