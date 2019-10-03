
#include<iostream>
using namespace std;

int mag[5][8];
int k;
int red[5], lft[5], rgt[5];

void changePos(int idx, int dir) { //회전하면서 생기는 인접한 지점, 12시 방향 변화
	if (dir == 1) {
		rgt[idx]--;
		red[idx]--;
		lft[idx]--;
		if (rgt[idx] < 0) rgt[idx] = 7;
		if (red[idx] < 0) red[idx] = 7;
		if (lft[idx] < 0) lft[idx] = 7;
	}
	else {
		rgt[idx]++;
		red[idx]++;
		lft[idx]++;
		if (rgt[idx] > 7) rgt[idx] = 0;
		if (red[idx] > 7) red[idx] = 0;
		if (lft[idx] > 7) lft[idx] = 0;
	}
}

void rotate(int num, int dir) {
	if (num == 1) {
		bool spin2 = false;
		if (mag[1][rgt[1]] != mag[2][lft[2]])
			spin2 = true;

		changePos(1, dir);//1번 회전

		if (spin2) { //1번때문에 2번도 돌아가는 경우

			//2번때문에 3번도 돌아야 하는지 확인
			bool spin3 = false;
			if (mag[2][rgt[2]] != mag[3][lft[3]]) spin3 = true;
			changePos(2, dir * -1); //2번 회전

			if (spin3) {
				//3번때문에 4번도 돌아야하는지 확인
				bool spin4 = false;
				if (mag[3][rgt[3]] != mag[4][lft[4]]) spin4 = true;
				changePos(3, dir); //3번 회전

				if (spin4) changePos(4, dir * -1); //4번 회전
			}
		}
	}

	else if (num == 2) {
		bool spin1 = false;
		if (mag[2][lft[2]] != mag[1][rgt[1]]) spin1 = true; //2번떄문에 1번 도는지 확인

		bool spin3 = false;
		if (mag[2][rgt[2]] != mag[3][lft[3]]) spin3 = true; //2번떄문에 3번 도는지 확인

		changePos(2, dir); //2번 회전

		if (spin1) changePos(1, dir * -1); //1번 회전



		if (spin3) {
			//3번때문에 4번도 돌아야하는지 확인
			bool spin4 = false;
			if (mag[3][rgt[3]] != mag[4][lft[4]]) spin4 = true;
			changePos(3, dir * -1); //3번 회전

			if (spin4) changePos(4, dir); //4번 회전
		}

	}

	else if (num == 3) {
		bool spin2 = false;
		if (mag[2][rgt[2]] != mag[3][lft[3]]) spin2 = true; //3번때문에 2번도는지

		bool spin4 = false;
		if (mag[3][rgt[3]] != mag[4][lft[4]]) spin4 = true; //3번때문에 4번도는지

		changePos(3, dir); //3번회전

		if (spin4) changePos(4, dir * -1); //4번회전

		if (spin2) {
			//2번때문에 1번도는지
			bool spin1 = false;
			if (mag[1][rgt[1]] != mag[2][lft[2]]) spin1 = true;

			changePos(2, dir * -1);

			if (spin1) changePos(1, dir);
		}
	}

	else if (num == 4) {
		//4번때문에 3번 도는지 확인
		bool spin3 = false;
		if (mag[4][lft[4]] != mag[3][rgt[3]]) spin3 = true;

		//4번 회전
		changePos(4, dir);

		if (spin3) {
			//3번때문에 2번도는지 확인
			bool spin2 = false;
			if (mag[2][rgt[2]] != mag[3][lft[3]]) spin2 = true;

			changePos(3, dir * -1);

			if (spin2) {
				//2번때문에 1번 도는지 확인
				bool spin1 = false;
				if (mag[1][rgt[1]] != mag[2][lft[2]]) spin1 = true;

				changePos(2, dir);

				if (spin1) changePos(1, dir * -1);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		for (int i = 1; i <= 4; i++) {
			lft[i] = 6;
			rgt[i] = 2;
			red[i] = 0;
		}

		cin >> k;
		for (int i = 1; i <= 4; i++)
			for (int j = 0; j < 8; j++)
				cin >> mag[i][j];

		while (k--) {
			int num, dir;
			cin >> num >> dir;
			rotate(num, dir);

		}

		int res = 0;
		if (mag[1][red[1]] == 1) res += 1;
		if (mag[2][red[2]] == 1) res += 2;
		if (mag[3][red[3]] == 1) res += 4;
		if (mag[4][red[4]] == 1) res += 8;

		cout << "#" << tc << ' ' << res << '\n';


	}
	return 0;
}

