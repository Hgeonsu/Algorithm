//#include<iostream>
//#include<list>
//using namespace std;
//
//int main(void) {
//
//	list<int> L = { 1, 2 };
//	list<int>::iterator it = L.begin(); //iterator�� �����Ͷ�� �����ϸ� ���ϴ�
//	
//	cout << *it << '\n';
//	L.push_back(3);
//	it++;
//	it++; //��ĭ�� �����δ�
//	cout << *it << '\n'; //3�� ����Ŵ
//
//	//������� 1,2,3
//
//	L.insert(it, 10); //it�� 3 ����Ű���־��µ� ���ʿ� 10�� �߰���. it�� ������ 3 ����Ŵ
//
//	L.insert(it, 15); //3����Ű�� it���ʿ� 15�߰�
//
//					  //��ü ����Ʈ ���
//	for (list<int>::iterator itor = L.begin(); itor != L.end(); itor++) {
//		cout << *itor << ' ';
//	}
//	
//	cout <<'\n' << *it << '\n';
//
//	it = L.erase(it);
//	it--;
//
//	
//	for (list<int>::iterator itor = L.begin(); itor != L.end(); itor++) {
//		cout << *itor << ' ';
//	}
//
//	cout << '\n' << *it << '\n';
//
//	it = L.end(); // ����Ʈ�� ������ ��ĭ �� �������� ���� ����Ų��
//	it--; //�׷��ϱ� �ϳ� ����ְ� 
//	cout << '\n' << *it << '\n'; //����ؾ� ������ ���� ���´�
//
//	it = L.begin();
//	cout << '\n' << *it << '\n'; //ó�� ��
//	return 0;
//}