//#include<iostream>
//#include<string>
//using namespace std;
//bool isPrime(int n) {
//	if (n == 1) return false;
//	for (int i = 2; i * i <= n; i++)
//		if (n % i == 0) return false;
//	return true;
//}
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	int tc;
//	cin >> tc;
//	for (int T = 1; T <= tc; T++) {
//		cout << "Case #" << T << '\n';
//		
//		int a, b;
//		cin >> a >> b;
//
//		string Astr = to_string(a);
//		int Alen = Astr.length();
//		int Acnt = 0;
//		
//		for (int i = Alen; i >= 1; i--) {
//			if (!isPrime(a))
//				break;
//			else {
//				Acnt++;
//				if (Alen == 1)
//					break;
//			}
//			string temp = Astr.substr(0, i - 1) + Astr.substr(i, Alen - i);
//			cout << "A temp " << temp << '\n';
//			if (isPrime(stoi(temp)))
//				Acnt++;
//			else
//				break;
//		}
//
//		string Bstr = to_string(b);
//		int Blen = Bstr.length();
//		int Bcnt = 0;
//
//		for (int i = Blen; i >= 1; i--) {
//			if (!isPrime(b))
//				break;
//			else {
//				Bcnt++;
//				if (Blen == 1)
//					break;
//			}
//			string temp = Bstr.substr(0, i - 1) + Astr.substr(i, Blen - i);
//			cout << "B temp " << temp << '\n';
//			if (isPrime(stoi(temp)))
//				Bcnt++;
//			else
//				break;
//		}
//
//		if (Acnt > Bcnt)
//			cout << 1 << '\n';
//		else if (Acnt < Bcnt)
//			cout << 2 << '\n';
//		else
//			cout << 3 << '\n';
//		
//	}
//	return 0;
//}
