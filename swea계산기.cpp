//#include<iostream>
//#include<string>
//#include<stack>
//
//using namespace std;
//int main(void) {
//	string str;
//	
//	stack<char> stk;
//
//	//���ÿ� �ִ� ���� int ��ȯ �ʿ�
//	
//
//	
//	for (int T = 1; T <= 10; T++) {
//		cout << '#' << T << ' ';
//		cin >> str;
//
//		string sn = "";
//		for (int i = 0; i < str.length(); i++) {
//			if (str[i] >= '0' && str[i] <= '9')
//				sn += str[i];
//
//			//������ ������� �ʰ�, ���� �켱������ ���ų� ������ top�� �̾� ���̰� pop�ض�
//
//			//�׷��� ������ Ǫ��
//			else if (str[i] == '+') {
//				while (!stk.empty()) {
//					sn = sn + stk.top();
//					stk.pop();
//				}
//				stk.push(str[i]);
//			}
//
//			else if (str[i] == '*') {
//				while (!stk.empty() && stk.top() == '*') {
//					sn += stk.top();
//					stk.pop();
//				}
//				stk.push('*');
//			}
//
//		}
//		while (!stk.empty()) {
//			sn += stk.top();
//			stk.pop();
//		}
//		//cout << sn << '\n';
//
//		//������� postorder ��ȯ
//
//		//������� ���
//		for (int i = 0; i < sn.length(); i++) {
//			if (sn[i] >= '0' && sn[i] <= '9')
//				stk.push(sn[i]);
//			else if (sn[i] == '+') {
//				int num2 = stk.top() - '0';
//				stk.pop();
//				int num1 = stk.top() - '0';
//				stk.pop();
//				int res = num1 + num2;
//				char cr = res + '0';
//				stk.push(cr);
//			}
//			else if (sn[i] == '*') {
//				int num2 = stk.top() - '0';
//				stk.pop();
//				int num1 = stk.top() - '0';
//				stk.pop();
//				int res = num1 * num2;
//				char cr = res + '0';
//				stk.push(cr);
//			}
//		}
//		cout << stk.top() - '0';
//		stk.pop();
//	}
//	return 0;
//}