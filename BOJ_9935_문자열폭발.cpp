#include<iostream>
#include<string>

using namespace std;

string ans = "";
int main(void) {
	string str, bomb;
	cin >> str >> bomb;
	
	int k = 0; //str�� ���̸�ŭ Ȯ�� (Ȯ���� �ε���)
	while (k < (int)str.length()) {

		//�ܾ���ź�� ������ ���ڿ� �����鼭, �ܾ� ��ź�� ���� �̻��� �ܾ ans ���ڿ��� ��� ���� ���� �˻�
		if (str[k] == bomb[bomb.length() - 1] && ans.length() >= bomb.length()-1) {
			bool isBomb = true;
			int idx = 0;
			for (int j = 1; j <= bomb.length()-1; j++) { //������ ���ڴ� ��¥�� �����ϱ�, �����ϰ� �˻�
				if (ans[ans.length() - bomb.length() + j] != bomb[idx]) {
					isBomb = false;
					break;
				}
				else
					idx++;
			}
			if (isBomb) { //�ܾ� ��ź�� ��� 
				for (int i = 0; i < bomb.length() - 1; i++)
					ans.pop_back();
			}
			else //��ź�˻縦 �ߴµ� �ƴ� ���
				ans += str[k];
		}
		else { //�ܾ� ��ź�� ������ ö�ڿ� ���ڰ� �޶��� (�����) ���
			ans += str[k];
		}
		k++; //Ȯ���ϴ� ���ڿ� ��ġ ����
	}
	if ((int)ans.length() != 0)
		cout << ans;
	else
		cout << "FRULA"; 
	return 0;
}