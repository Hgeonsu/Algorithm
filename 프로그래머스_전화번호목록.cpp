#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(string a, string b) {
	return a.length() < b.length();
}
bool solution(vector<string> pb) {
	sort(pb.begin(), pb.end(), cmp);
	for (int i = 0; i < pb.size(); i++)
		cout << pb[i] << ' ';
	return false;
}

int main(void) {
	solution({  "97674223", "1195524421", "119" });
	return 0;
}

