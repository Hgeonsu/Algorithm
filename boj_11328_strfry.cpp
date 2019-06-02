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
/*���ĺ����� ������ �ľ��ϴ� ������� a-'a' = 0, b-'a' = 1 �� Ư¡�� �̿��ؼ� �迭�� ������ �ľ�
�迭 �ʱ�ȭ ������� �ϴ� �Ϳ� ����*/



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
//	/*�� Ǯ�̴� ���ڿ� ���� �ߺ��Ǵ� ���ڰ� ������ Ʋ�� Ǯ��
//	aatt aaat �̷���*/
//
//	return 0;
//}