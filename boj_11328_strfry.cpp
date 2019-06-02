#include<iostream>
#include<string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	while (N--) {
		string src="", des="";
		int srcA[26] = { 0, };
		int desA[26] = { 0, };
		cin >> src >> des;
		if (src.length() != des.length()) {
			cout << "Impossible\n";
			continue;
		}
		for (int i = 0; i < src.length(); i++) {
			srcA[src[i] - 'a']++;
			desA[des[i] - 'a']++;
		}
		bool eq = true;
		for (int i = 0; i < 26; i++) {
			if (srcA[i] != desA[i]) {
				eq = false;
				break;
			}
		}
		if (eq) {
			cout << "Possible\n";
		}
		else {
			cout << "Impossible\n";
		}
	}
	return 0;
}
/*알파벳마다 개수를 파악하는 방법으로 a-'a' = 0, b-'a' = 1 이 특징을 이용해서 배열로 개수를 파악
배열 초기화 시켜줘야 하는 것에 주의*/



//#include<iostream>
//#include<string>
//using namespace std;
//int n;
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	
//	cin >> n;
//	while (n--) {
//		string str1="", str2="";
//		cin >> str1 >> str2;
//		/*if (str1.length() != str2.length()) {
//			cout << "Impossible\n";
//			continue;
//		}*/
//		bool flag = false;
//		
//		for (int i = 0; i < str1.length(); i++) {
//			flag = false;
//			for (int j = 0; j < str2.length(); j++) {
//				if (str1[i] == str2[j]) {
//					flag = true;
//					break;
//				}
//			}
//			if (!flag) {
//				cout << "Impossible\n";
//				break;
//			}
//		}
//		if (flag) {
//			cout << "Possible\n";
//		}
//	}
//	/*이 풀이는 문자열 내에 중복되는 문자가 있으면 틀린 풀이
//	aatt aaat 이런거*/
//
//	return 0;
//}