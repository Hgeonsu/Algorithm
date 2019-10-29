#include <string>
#include <vector>
#include<iostream>
#include<map>
#include<functional>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;

struct Info {
	string str;
	int cnt;
};

bool cmp(pii a, pii b) {
	if (a.first != b.first)
		return a.first > b.first;
	else
		return a.second < b.second;
}

bool cmp2(Info a, Info b) {
	return a.cnt > b.cnt;
}

map<string, vector<pii> > mp;
map<string, int> cntMap;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	int songNum = 0;
	for (int i = 0; i < genres.size(); i++) {
		if (mp.find(genres[i]) == mp.end()) {
			vector<pii> tmp;
			tmp.push_back({ plays[i], i }); //i번째 곡이 저만큼 플레이 됨
			mp.insert({ genres[i], tmp });
			cntMap.insert({ genres[i], plays[i] });
		}
		else {
			mp[genres[i]].push_back({ plays[i], i });
			cntMap[genres[i]] += plays[i]; //토탈 추가
		}
	}

	for (auto itr = mp.begin(); itr != mp.end(); itr++) {
		//cout << itr->first << '\n';
		sort(itr->second.begin(), itr->second.end(), cmp); //노래 재생 횟수 내림차순 정렬
														   /*vector<pii> tmp = itr->second;
														   for (int i = 0; i < tmp.size(); i++) {
														   cout << tmp[i].first << ' ' << tmp[i].second << '\n';
														   }*/

	}
	//cout << '\n';

	vector<Info> sortVec; //정렬하기 위해 옮겨담기. <장르, 총재생수>

	for (auto itr = cntMap.begin(); itr != cntMap.end(); itr++) {
		//cout << itr->first << ' ' << itr->second << '\n';
		//tmp.push_back()
		sortVec.push_back({ itr->first, itr->second });
	}
	sort(sortVec.begin(), sortVec.end(), cmp2);

	for (int i = 0; i < sortVec.size(); i++) {
		string gen = sortVec[i].str;
		answer.push_back(mp.find(gen)->second[0].second);
		if (mp.find(gen)->second.size() > 1)
			answer.push_back(mp.find(gen)->second[1].second);
	}
	return answer;
}

int main(void) {

	cout << "asdas";
}