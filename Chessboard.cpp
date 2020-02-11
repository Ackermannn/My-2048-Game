#include "Chessboard.h"
Chessboard::Chessboard() {
	vector<int> temp = {};
	for (int i = 0; i < 4; i++) temp.push_back(0);
	for (int i = 0; i < 4; i++) score.push_back(temp);
	check();
}
void Chessboard::down()
{
	align("down");
	merge("down");
	align("down");
}
void Chessboard::up()
{
	align("up");
	merge("up");
	align("up");
}
void Chessboard::left()
{
	align("left");
	merge("left");
	align("left");
}

void Chessboard::right()
{
	align("right");
	merge("right");
	align("right");
}

void Chessboard::show()
{
	cout << "---��Ϸ---2048---" << endl;
	cout << "---------------------" << endl;
	for (auto x : score) {
		cout << "|";
		for (auto i : x) {
			if (i != 0) {
				cout.width(4);
				cout << i << "|";
			}
			else
				cout << "    " << "|";
		}
		cout << endl;
		cout << "---------------------" << endl;

	}
	cout << "�������[w][a][s][d]�������ƶ��ϲ�: " << endl;
}

bool Chessboard::check()
{
	free = {};
	// ����Ƿ��Ѿ�����

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (score[i][j] == 0) free.push_back({ i, j });

		}
	}
	if (free.empty())
		return true;
	else
		return false;
}

bool Chessboard::product()
{
	if (check()) {
		return false;
	}
	else {
		int min = 0, max = free.size() - 1;
		default_random_engine generator(time(NULL));//���棬������
		uniform_int_distribution<unsigned> distribution(min, max); //���ȷֲ�
		int product_idx = distribution(generator);
		int i = free[product_idx][0], j = free[product_idx][1];


		// �� 10% �ĸ��ʲ��� 4
		uniform_int_distribution<unsigned> p_distribution(0, 100);
		int p = p_distribution(generator);
		if (p > 10) score[i][j] = 2;
		else score[i][j] = 4;
		return true;
	}
}

bool Chessboard::isWin()
{
	for (auto x : score) {
		for (auto i : x) {
			if (i == 2048) return true;
		}
	}
	return false;
}

void Chessboard::align(string direction)
{
	// ���¶��� 
	if (direction == "down")
	{
		for (int col = 0; col < 4; col++)
		{
			int flag = 1;
			while (flag)
			{
				flag = 0;
				if (score[3][col] == 0 and score[2][col] != 0) {
					swap(score[3][col], score[2][col]);
					flag = 1;
				}
				if (score[2][col] == 0 and score[1][col] != 0) {
					swap(score[2][col], score[1][col]);
					flag = 1;
				}
				if (score[1][col] == 0 and score[0][col] != 0) {
					swap(score[1][col], score[0][col]);
					flag = 1;
				}

			}
		}
	}
	// ���϶��� 
	if (direction == "up")
	{
		for (int col = 0; col < 4; col++)
		{
			int flag = 1;
			while (flag)
			{
				flag = 0;
				if (score[0][col] == 0 and score[1][col] != 0) {
					swap(score[0][col], score[1][col]);
					flag = 1;
				}
				if (score[1][col] == 0 and score[2][col] != 0) {
					swap(score[1][col], score[2][col]);
					flag = 1;
				}
				if (score[2][col] == 0 and score[3][col] != 0) {
					swap(score[2][col], score[3][col]);
					flag = 1;
				}

			}
		}
	}
	if (direction == "left")
	{
		for (int row = 0; row < 4; row++)
		{
			int flag = 1;
			while (flag)
			{
				flag = 0;
				if (score[row][0] == 0 and score[row][1] != 0) {
					swap(score[row][0], score[row][1]);
					flag = 1;
				}
				if (score[row][1] == 0 and score[row][2] != 0) {
					swap(score[row][1], score[row][2]);
					flag = 1;
				}
				if (score[row][2] == 0 and score[row][3] != 0) {
					swap(score[row][2], score[row][3]);
					flag = 1;
				}

			}
		}
	}
	if (direction == "right")
	{
		for (int row = 0; row < 4; row++)
		{
			int flag = 1;
			while (flag)
			{
				flag = 0;
				if (score[row][3] == 0 and score[row][2] != 0) {
					swap(score[row][3], score[row][2]);
					flag = 1;
				}
				if (score[row][2] == 0 and score[row][1] != 0) {
					swap(score[row][2], score[row][1]);
					flag = 1;
				}
				if (score[row][1] == 0 and score[row][0] != 0) {
					swap(score[row][1], score[row][0]);
					flag = 1;
				}

			}
		}
	}
}

void Chessboard::merge(string direction)
{
	if (direction == "down") {
		// ���ºϲ�
		for (int col = 0; col < 4; col++) {

			if (score[3][col] == score[2][col]) {
				score[3][col] *= 2;
				score[2][col] = 0;
			}
			if (score[2][col] == score[1][col]) {
				score[2][col] *= 2;
				score[1][col] = 0;
			}
			if (score[1][col] == score[0][col]) {
				score[1][col] *= 2;
				score[0][col] = 0;
			}
		}
	}
	else if (direction == "up")
		for (int col = 0; col < 4; col++) {
			if (score[1][col] == score[0][col]) {
				score[1][col] = 0;
				score[0][col] *= 2;
			}

			if (score[2][col] == score[1][col]) {
				score[2][col] = 0;
				score[1][col] *= 2;
			}

			if (score[3][col] == score[2][col]) {
				score[3][col] = 0;
				score[2][col] *= 2;
			}

		}
	else if (direction == "right") {
		for (int row = 0; row < 4; row++) {
			if (score[row][2] == score[row][3]) {
				score[row][2] = 0;
				score[row][3] *= 2;
			}

			if (score[row][1] == score[row][2]) {
				score[row][1] = 0;
				score[row][2] *= 2;
			}
			if (score[row][0] == score[row][1]) {
				score[row][0] = 0;
				score[row][1] *= 2;
			}

		}


	}
	else if (direction == "left")
	{
		// ���Һϲ�
		for (int row = 0; row < 4; row++) {

			if (score[row][0] == score[row][1]) {
				score[row][0] *= 2;
				score[row][1] = 0;
			}
			if (score[row][1] == score[row][2]) {
				score[row][1] *= 2;
				score[row][2] = 0;
			}
			if (score[row][2] == score[row][3]) {
				score[row][2] *= 2;
				score[row][3] = 0;
			}
		}

	}

}
