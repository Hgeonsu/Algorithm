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
//int Max = -1;
//int func(int n, int res) {
//	
//	string str = to_string(n);
//	
//	if (str.length() == 1) {
//		if (isPrime(n)) {
//			res++;
//			if (Max < res) Max = res;
//			//printf("\n %d 일 때 res는 %d\n", n, res);
//			return res;
//		}
//		else {
//			if (Max < res) Max = res;
//			return res;
//		}
//	}
//	
//	if (isPrime(n)) {
//		res++;
//		if (Max < res) Max = res;
//		//printf("\n %d 일 때 res는 %d\n", n, res);
//	}
//	else {
//		//cout << n << "은 소수가 아님\n";
//		if (Max < res) Max = res;
//		return res;
//	}
//	
//	//vector<int> a; //몇개의 수에서
//	int a[6];
//	
//	for (int i = 0; i < str.length(); i++) {
//		a[i] = stoi(str.substr(i, 1));
//	}
//	
//	int select[7] = { 0,1,1,1,1,1,1 };
//	
//	do {
//		string temp;
//		for (int i = 0; i < str.length(); i++) {
//		
//			if (select[i])
//				temp = temp + to_string(a[i]);
//		}
//		//cout << temp << ' ' << res << '\n';
//		func(stoi(temp.substr(0,temp.length())),res);
//	}while (next_permutation(select, select + str.length()));
//
//}
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	int tc;
//	cin >> tc;
//	for (int T = 1; T <= tc; T++) {
//		cout << "Case #" << T << '\n';
//		Max = -1;
//		int a, b;
//		cin >> a >> b;
//		func(a, 0);
//		int MaxA = Max;
//		Max = -1;
//		func(b, 0);
//		int MaxB = Max;
//
//		//printf("Amax = %d Bmax = %d\n", MaxA, MaxB);
//		if (MaxA > MaxB)
//			cout << 1 << '\n';
//		else if (MaxA < MaxB)
//			cout << 2 << '\n';
//		else
//			cout << 3 << '\n';
//	}
//	return 0;
//}
