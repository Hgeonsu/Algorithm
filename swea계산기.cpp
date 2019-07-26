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
//	//스택에 있는 숫자 int 변환 필요
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
//			//스택이 비어있지 않고, 내가 우선순위가 같거나 낮으면 top을 이어 붙이고 pop해라
//
//			//그렇지 않으면 푸쉬
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
//		//여기까지 postorder 변환
//
//		//여기부터 계산
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