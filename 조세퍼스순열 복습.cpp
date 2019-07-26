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
//	////3삭제
//	//it = L.erase(it);
//
//	////it가 4가리킴. 
//	////삭제하면 뒤쪽 리스트들이 앞으로 붙는다고 생각. 마지막꺼 삭제하면 리스트 바깥 성분 가리킴.
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
//	//it가 k를 가리킴
//
//	int cnt = k - 1;
//	cout << '<';
//	while (!L.empty()) {
//		cnt = k - 1;
//		while (cnt--) { //k-1번 움직임. 어짜피 삭제하면 한 칸 움직이는 효과
//			//cout << *it << "루프안";
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