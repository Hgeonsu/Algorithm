//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//bool isPrime(int n) {
//	if (n == 1) return false;
//	for (int i = 2; i * i <= n; i++)
//		if (n % i == 0) return false;
//	return true;
//}
//vector<int> allPrime(int n) {
//	vector<int> ret;
//	for (int i = 1; i <= n; i++)
//		if (isPrime(i)) ret.push_back(i);
//	return ret;
//}
//int main(void) {
//	vector<int> ret = allPrime(30000);
//	for (int i = 0; i < ret.size(); i++)
//		cout << ret[i] << ' ';
//	return 0;
//}