//#include<iostream>
//#include<list>
//using namespace std;
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	//list<int> L = { 1,2,3,4,5 };
//
//	//list<int>::iterator it = L.begin();
//	//it++;
//	//it++;
//	//cout << *it << '\n';
//
//	////3����
//	//it = L.erase(it);
//
//	////it�� 4����Ŵ. 
//	////�����ϸ� ���� ����Ʈ���� ������ �ٴ´ٰ� ����. �������� �����ϸ� ����Ʈ �ٱ� ���� ����Ŵ.
//	//cout << *it << '\n';
//
//
//	list<int> L;
//
//	int n, k;
//	cin >> n >> k;
//
//	for (int i = 1; i <= n; i++) {
//		L.push_back(i);
//	}
//
//	for (list<int>::iterator ite = L.begin(); ite != L.end(); ite++) {
//		cout << *ite << ' ';
//	}
//	
//
//	list<int>::iterator it = L.begin();
//	
//	/*for (int i = 0; i < k - 1; i++) {
//		it++;
//	}*/
//	//it�� k�� ����Ŵ
//
//	int cnt = k - 1;
//	cout << '<';
//	while (!L.empty()) {
//		cnt = k - 1;
//		while (cnt--) { //k-1�� ������. ��¥�� �����ϸ� �� ĭ �����̴� ȿ��
//			//cout << *it << "������";
//			it++;
//			if (it == L.end())
//				it = L.begin();
//		}
//		cout << *it << ', ';
//		it = L.erase(it);
//	}
//	cout << '>';
//	
//	
//
//	return 0;
//}