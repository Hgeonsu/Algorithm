//#include<iostream>
//#include<string>
//#include<math.h>
//using namespace std;
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	string org, cpr;
//	int orga[26] = { 0, }, cpra[26] = { 0, };
//
//	cin >> org >> cpr;
//
//	for (int i = 0; i < org.length(); i++) {
//		orga[org[i] - 'a']++;
//	}
//	for (int i = 0; i < cpr.length(); i++) {
//		cpra[cpr[i] - 'a']++;
//	}
//
//	int cnt = 0;
//	
//	for (int i = 0; i < 26; i++) {
//		cnt = cnt + abs(orga[i] - cpra[i]);
//	}
//	cout << cnt << '\n';
//
//	return 0;
//}
///*
//strfry�� ���� ����. �ܾ ���� ���ĺ��� ������ �ľ��ؼ� ��.
//�Է� ���ڿ��� ���̰� �ٸ� ��쵵 �����������
//*/