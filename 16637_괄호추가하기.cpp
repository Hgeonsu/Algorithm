#include<iostream>
#include<string>
#include<limits.h>
#include<vector>

using namespace std;
typedef long long ll;
int n, maxBrac, arr[20], st = 1, num[20];
vector<ll> numV; //피연산자
vector<char> oprV; //연산자

char opr[20];
string cmd;
bool isused[20], picked[20], done[20];
int ans = -1 * INT_MAX;

void init() {
	for (int i = 0; i < n; i++) {
		picked[i] = false;
		done[i] = false;
	}
}
ll cal(int a, char op, int b) { //계산 과정에서 int 범위를 벗어날 수 있다
	if (op == '+')
		return (ll)(a + b);
	else if (op == '*')
		return (ll)(a*b);
	else if (op == '-')
		return (ll)(a - b);
}
void btk(int k, int maxBr) {
	if (k == maxBr) {
		for (int i = 0; i < maxBr; i++) {
		
			picked[arr[i]-1] = true;
			picked[arr[i]] = true;
			picked[arr[i]+1] = true;
		}
		
		for (int i = 0; i < n; i++) { //괄호로 묶인 값들 계산하면서 연산자, 피연산자 벡터에 삽입
			if (!picked[i]) {
				if (num[i] != -1)
					numV.push_back(num[i]);
				else
					oprV.push_back(opr[i]);
			}
			else if(picked[i]){
				if (done[i]) continue;
				else {
					numV.push_back(cal(num[i], opr[i + 1], num[i + 2]));
					done[i] = true;
					done[i + 1] = true;
					done[i + 2] = true;
				}
			}
		}

		ll res = numV[0]; //수식 계산
		for (int i = 1; i < numV.size(); i++) {
			res = cal(res, oprV[i - 1], numV[i]);
		}
	
		if (ans < res) ans = res;
		init();
		oprV.clear();
		numV.clear();
		return;
	}
	if (k == 0) st = 1;
	for (int i = st; i < n; i += 2) {
		if (!isused[i]) {
			arr[k] = i;
			st = i;
			isused[i] = true;
			isused[i + 2] = true; //연산자를 선택하면, 바로 인접한 연산자는 고를 수 없음
			btk(k + 1, maxBr);
			isused[i + 2] = false;
			isused[i] = false;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> cmd;

	maxBrac = (n + 1) / 4; //수식의 길이가 n일 때, 넣을 수 있는 괄호의 최대 개수
	for (int i = 0; i < cmd.length(); i++) {
		if (i % 2 == 0) num[i] = cmd[i]-'0'; //입력은 문자로 들어온다
		else {
			opr[i] = cmd[i];
			num[i] = -1; //입력이 음수가 들어오는 경우는 없으므로 -1로 초기화
		}
	}
	for(int i = 0 ; i <= maxBrac ; i++)
		btk(0, i);
	cout << ans;
	return 0;
}
