//#define _USE_MATH_DEFINES
//#include <iostream>
//#include<math.h>
//#include<iomanip>
//using namespace std;
//
//double dis;
//
//int main(int argc, char** argv)
//{
//	
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	//setbuf(stdout, NULL); //주석풀고제출
//
//	int T, test_case;
//
//	cout << fixed;
//	cout.precision(12);
//
//
//	cin >> T;
//	
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		double r, st, en;
//		cin >> r >> st >> en;
//		double blk;
//		cin >> blk;
//
//		dis = 0;
//
//		while (blk--) {
//			double lef, rig, h;
//			cin >> lef >> rig >> h;
//			
//			if (h >= r) {
//				
//				dis = dis + ((lef - r) - st); // 시작점에서 왼쪽가로
//				dis = dis + (h - r) * 2;
//				dis = dis + (r * M_PI);
//				dis = dis + rig - lef;
//				st = rig + r; //시작점 이동
//			}
//			else {
//				double temp = sqrt(pow(r, 2) - pow(r - h, 2));
//				dis = dis + (lef - temp - st);
//				dis = dis + rig - lef;
//				double angle = atan2(temp, r - h);
//				dis = dis + angle * r * 2 ;
//				st = rig + temp;
//			}
//			
//		}
//		dis = dis + en - st;
//
//		cout << "Case #" << test_case + 1 << '\n';
//		cout << dis << '\n';
//	}
//
//	return 0;
//}