//#include<iostream>
//#include<list>
//using namespace std;
//
//int main(void) {
//
//	list<int> L = { 1, 2 };
//	list<int>::iterator it = L.begin(); //iterator를 포인터라고 생각하면 편하다
//	
//	cout << *it << '\n';
//	L.push_back(3);
//	it++;
//	it++; //한칸씩 움직인다
//	cout << *it << '\n'; //3을 가리킴
//
//	//여기까지 1,2,3
//
//	L.insert(it, 10); //it는 3 가리키고있었는데 왼쪽에 10이 추가됨. it는 여전히 3 가리킴
//
//	L.insert(it, 15); //3가리키는 it왼쪽에 15추가
//
//					  //전체 리스트 출력
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
//	it = L.end(); // 리스트의 끝보다 한칸 더 오른쪽의 값을 가리킨다
//	it--; //그러니까 하나 당겨주고 
//	cout << '\n' << *it << '\n'; //출력해야 마지막 값이 나온다
//
//	it = L.begin();
//	cout << '\n' << *it << '\n'; //처음 값
//	return 0;
//}