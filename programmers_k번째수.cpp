//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//vector<int> solution(vector<int> array, vector<vector<int>> commands) {
//	vector<int> answer;
//
//	for (int i = 0; i < commands.size(); i++) {
//		/*for (int j = 0; j < commands[i].size(); j++) {
//			
//		}*/
//		vector<int> temp;
//		for (int j = commands[i][0]-1; j <= commands[i][1]-1; j++) {
//			temp.push_back(array[j]);
//		}
//		cout << '\n';
//		sort(temp.begin(), temp.end());
//		/*for (int i = 0; i < temp.size(); i++)
//			cout << temp[i] << ' ';
//		cout << '\n';*/
//		answer.push_back(temp[commands[i][2] - 1]);
//		temp.clear();
//	}
//
//	return answer;
//}
//
//int main(void) {
//	vector<int> arr { 1,5,2,6,3,7,4, };
//	vector<vector<int>> cmds{ {2, 5, 3}, {4, 4, 1}, {1, 7, 3} };
//	
//	vector<int> result;
//	result = solution(arr, cmds);
//
//	for (int i = 0; i < result.size(); i++)
//		cout << result[i] << ' ';
//}