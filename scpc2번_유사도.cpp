//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int Max = 0;
//int Select[5001];
//vector<int> a;
//void flip(vector<int> &b, int i, int j) {
//	vector<int> temp = b;
//	reverse(temp.begin() + i - 1, temp.begin() + j); //[i, j] 뒤집고 싶을때
//	int cnt = 0;
//	for (int i = 0; i < a.size(); i++) {
//		if (a[i] == temp[i]) cnt++;
//		//cout << temp[i] << ' ';
//	}
//	//printf("i = %d, j = %d\n", i, j);
//	if (Max < cnt) Max = cnt;
//		
//}
//int main(void) {
//	//setbuf(stdout, NULL);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	
//	vector<int> b;
//	int tc;
//	cin >> tc;
//
//	for (int T = 1; T <= tc; T++) {
//		cout << "Case #" << T << '\n';
//
//		int n;
//		cin >> n;
//		for (int i = 0; i < n; i++) {
//			int num;
//			cin >> num;
//			a.push_back(num);
//		}
//		for (int i = 0; i < n; i++) {
//			int num;
//			cin >> num;
//			b.push_back(num);
//		}
//		//회전하기전
//		//int Max = 0;
//		for (int i = 0; i < a.size(); i++) {
//			if (a[i] == b[i]) Max++;
//			//cout << temp[i] << ' ';
//		}
//
//		//i, j 모든 조합 뽑아서 
//		
//		int idx[5001];
//		for (int i = 1; i <= 5000; i++) {
//			idx[i] = i;
//		}
//		Select[b.size()] = 1;
//		Select[b.size() - 1] = 1; //나중에 초기화
//
//		bool zero = true;
//		do {
//			for (int i = 1; i <= b.size(); i++) {
//				int ni, nj;
//				
//				if (Select[i] && zero) {
//					
//					ni = idx[i];
//					zero = false;
//					//printf("ni,  = %d\n", ni);
//					//flip(b, ni, ni);
//				}
//				else if (Select[i] && !zero) {
//					nj = idx[i];
//					zero = true;
//					//printf("ni, nj = %d, %d\n", ni, nj);
//					flip(b, ni, nj);
//				}
//
//				/*if(Select[i])
//					cout << a[i] << ' ';*/
//			}
//			//cout << '\n';
//		} while (next_permutation(Select + 1, Select + 1 + b.size()));
//		
//		cout << Max << '\n';
//		Max = 0;
//		Select[b.size()] = 0;
//		Select[b.size() - 1] = 0; //나중에 초기화
//		a.erase(a.begin(), a.end());
//		b.erase(b.begin(), b.end());
//	}
//	return 0;
//}
