#include<iostream>
#include<set>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;



const int dzero[4] = { -3, 3, -1, 1 }; //상하좌우
const int dr[4] = { -1,1,0,0 };
const int dc[4] = { 0,0,-1, 1 };

int main(void) {
	string str ="", dst = "123456780";
	
	for (int i = 0; i < 9; i++) {
		/*string input;
		cin >> input;
		str += input;*/
		int input;
		cin >> input;
		str += input + '0';
	}
	

	
	

	set<string> vis;
	vis.insert(str);
	
	queue<string> q;
	q.push(str);
	int cnt = 0;
	
	while(!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i <qSize; i++) {
			string cur = q.front(); //현재 문자열
			q.pop();

			if (cur == dst) { //목적 문자랑 같으면 종료
				cout << cnt;
				return 0;
			}
			//cnt++;

			int zeroPos=0; //0위치 검색
			for (; cur[zeroPos] != '0'; zeroPos++); 
			/*{
				if (cur[j] == '0') {
					zeroPos = j;
					break;
				}
				
			}*/
			//printf("0위치 %d\n", zeroPos);
			int zeroR = zeroPos / 3;
			int zeroC = zeroPos % 3;

			for (int j = 0; j < 4; j++) {
				int nr = zeroR + dr[j];
				int nc = zeroC + dc[j];
				if (nr < 0 || nc < 0 || nr >= 3 || nc >= 3) continue;
				
				string next = cur;
				//swap(next[zeroPos], next[zeroPos + dzero[j]]);
				char temp = next[zeroPos];
				next[zeroPos] = next[zeroPos + dzero[j]];
				next[zeroPos + dzero[j]] = temp;

				if (vis.find(next) == vis.end()){
					vis.insert(next);
					q.push(next);
				}
			}
		}
		cnt++;
	}
	return 0;
}
