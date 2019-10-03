
#include<iostream>
using namespace std;

int mag[5][8];
int k;
int red[5], lft[5], rgt[5];

void changePos(int idx, int dir) { //ȸ���ϸ鼭 ����� ������ ����, 12�� ���� ��ȭ
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

		changePos(1, dir);//1�� ȸ��

		if (spin2) { //1�������� 2���� ���ư��� ���

			//2�������� 3���� ���ƾ� �ϴ��� Ȯ��
			bool spin3 = false;
			if (mag[2][rgt[2]] != mag[3][lft[3]]) spin3 = true;
			changePos(2, dir * -1); //2�� ȸ��

			if (spin3) {
				//3�������� 4���� ���ƾ��ϴ��� Ȯ��
				bool spin4 = false;
				if (mag[3][rgt[3]] != mag[4][lft[4]]) spin4 = true;
				changePos(3, dir); //3�� ȸ��

				if (spin4) changePos(4, dir * -1); //4�� ȸ��
			}
		}
	}

	else if (num == 2) {
		bool spin1 = false;
		if (mag[2][lft[2]] != mag[1][rgt[1]]) spin1 = true; //2�������� 1�� ������ Ȯ��

		bool spin3 = false;
		if (mag[2][rgt[2]] != mag[3][lft[3]]) spin3 = true; //2�������� 3�� ������ Ȯ��

		changePos(2, dir); //2�� ȸ��

		if (spin1) changePos(1, dir * -1); //1�� ȸ��



		if (spin3) {
			//3�������� 4���� ���ƾ��ϴ��� Ȯ��
			bool spin4 = false;
			if (mag[3][rgt[3]] != mag[4][lft[4]]) spin4 = true;
			changePos(3, dir * -1); //3�� ȸ��

			if (spin4) changePos(4, dir); //4�� ȸ��
		}

	}

	else if (num == 3) {
		bool spin2 = false;
		if (mag[2][rgt[2]] != mag[3][lft[3]]) spin2 = true; //3�������� 2��������

		bool spin4 = false;
		if (mag[3][rgt[3]] != mag[4][lft[4]]) spin4 = true; //3�������� 4��������

		changePos(3, dir); //3��ȸ��

		if (spin4) changePos(4, dir * -1); //4��ȸ��

		if (spin2) {
			//2�������� 1��������
			bool spin1 = false;
			if (mag[1][rgt[1]] != mag[2][lft[2]]) spin1 = true;

			changePos(2, dir * -1);

			if (spin1) changePos(1, dir);
		}
	}

	else if (num == 4) {
		//4�������� 3�� ������ Ȯ��
		bool spin3 = false;
		if (mag[4][lft[4]] != mag[3][rgt[3]]) spin3 = true;

		//4�� ȸ��
		changePos(4, dir);

		if (spin3) {
			//3�������� 2�������� Ȯ��
			bool spin2 = false;
			if (mag[2][rgt[2]] != mag[3][lft[3]]) spin2 = true;

			changePos(3, dir * -1);

			if (spin2) {
				//2�������� 1�� ������ Ȯ��
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

