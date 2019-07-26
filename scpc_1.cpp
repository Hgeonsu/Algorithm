//#include <iostream>
//
//using namespace std;
//int d[1000001];
//int Answer;
//
//int main(int argc, char** argv)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	//setbuf(stdout, NULL); //주석풀고제출
//
//	int T, test_case;
//	
//	d[2] = 1;
//
//	int i = 4;
//	while (i <= 1000000) {
//		if (i % 2 == 0) {
//			d[i] = d[i / 2] + 1;
//			i--;
//			continue;
//		}
//		else {
//			d[i] = d[i + 1] + 1;
//			i += 3;
//			continue;
//		}
//	}
//
//	cin >> T;
//	
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		int n1, n2;
//		cin >> n1 >> n2;
//		Answer = 0;
//		
//		for (int i = n1; i <= n2; i++) {
//			Answer = Answer + d[i];
//		}
//		
//		cout << "Case #" << test_case + 1 << '\n';
//		cout << Answer << '\n';
//	}
//
//	return 0;
//}