//#include<iostream>
//#include<map>
//#include<string>
//#include<vector>
//using namespace std;
//
//
//string solution(vector<string> participant, vector<string> completion) {
//	string answer = "";
//
//	multimap<string, int> mm;
//	for (int i = 1; i <= participant.size(); i++) {
//		mm.insert({ participant[i - 1], i });
//	}
//
//	/*for (auto iter : mm) {
//		cout << iter.first << ", " << iter.second << '\n';
//	}*/
//	
//	/*for (multimap<string, int> ::iterator iter = mm.begin(); iter != mm.end(); iter++) {
//		cout << iter->first << ", " << iter->second << '\n';
//	}
//	cout << '\n';*/
//
//	for (int i = 0; i < completion.size(); i++) {
//		mm.erase(mm.lower_bound(completion[i]));
//	}
//	/*for (multimap<string, int> ::iterator iter = mm.begin(); iter != mm.end(); iter++) {
//		cout << iter->first << ", " << iter->second << '\n';
//	}*/
//	return mm.begin()->first;
//}
//
//int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	vector<string> participant {"mislav", "stanko", "mislav", "ana", "newval"};
//	vector<string> completion { "stanko", "ana", "mislav" };
//	cout << solution(participant, completion);
//
//	return 0;
//}
