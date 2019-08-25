#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct Bus {
	int num, curPop, hour, mint;
};
vector<Bus> bus;

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	int hour = 9, minute = 0;
	for (int i = 0; i < n; i++) {
		bus.push_back({ i, 0, hour, minute });
		minute += t;
		if (minute >= 60) {
			hour++;
			minute -= 60;
		}
	}
	/*for (int i = 0; i < bus.size(); i++) {
		printf("버스번호 : %d, 출발시간 %d시 %d분\n", bus[i].num, bus[i].hour, bus[i].mint);
	}*/
	sort(timetable.begin(), timetable.end());
	/*for (int i = 0; i < timetable.size(); i++) {
		cout << timetable[i] << '\n';
	}*/
	int lastUp = 0; //아무도 못타는 경우가 있나?
	for (int i = 0; i < timetable.size(); i++) {
		int hr = stoi(timetable[i].substr(0, 2));
		int mn = stoi(timetable[i].substr(3, 2));
		for (int j = 0; j < bus.size(); j++) {
			if (bus[j].curPop < m && (bus[j].hour > hr || (bus[j].hour == hr && bus[j].mint >= mn))) {
				bus[j].curPop++;
				lastUp = i;
				break;
			}
		}
	}
	
	if (bus[bus.size() - 1].curPop < n) {
		answer = to_string(bus[bus.size() - 1].hour) + ':' + to_string(bus[bus.size() - 1].mint);
	}
	else {
		int lastHr = stoi(timetable[lastUp].substr(0, 2));
		int lastMin = stoi(timetable[lastUp].substr(3, 2));
		lastMin--;
		if (lastMin < 0) {
			lastHr--;
			lastMin += 60;
		}
		string hrStr = to_string(lastHr);
		string mnStr = to_string(lastMin);
		if (hrStr.length() == 1) hrStr = '0' + hrStr;
		if (mnStr.length() == 1) mnStr = '0' + mnStr;
		answer = hrStr + ':' + mnStr;
	}
	cout << answer;
	return answer;
}
int main(void) {

	solution(2, 10, 2, { "09:10", "09:09", "08:00" });
}