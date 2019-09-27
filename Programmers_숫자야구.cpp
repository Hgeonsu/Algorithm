#include <string>
#include <vector>
#include<iostream>
#include<set>
using namespace std;

set<int> candi; //중복 방지를 위해 set 이용
vector<char> v;
bool used[10];
int Sz, arr[8];

bool isPrime(int k) {
	if (k == 0 || k == 1) return false;
	
	for (int i = 2; i*i <= k; i++) {
		if (k % i == 0) return false;
	}
	return true;
}
void btk(int k, int cnt, string &nums) {
	if (k == cnt) {
		
		string tmp = "";
		for (int i = 0; i < k; i++) 
			tmp += nums[arr[i]];
		
		int intTmp = stoi(tmp);
		
		if(isPrime(intTmp)) //만든 숫자가 소수인 경우에만 set에 추가
			candi.insert(intTmp);
	
		return;
	}
	
	for (int i = 0; i < Sz; i++) {
		if (!used[i]) {
			arr[k] = i; //nums의 인덱스를 넣음
			used[i] = true;
			btk(k + 1, cnt, nums);
			used[i] = false;
		}
	}
}

int solution(string nums) {
	Sz = nums.length();
	for (int i = 1; i <= nums.length(); i++) 
		btk(0, i, nums);
	
	return (int)candi.size();
}

int main(void) {
	solution("011");
}