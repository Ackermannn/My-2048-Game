#include "Chessboard.h"

Chessboard::Chessboard() {
	vector<int> temp = {};
	for (int i = 0; i < 4; i++) temp.push_back(0);
	for (int i = 0; i < 4; i++) score.push_back(temp);
	check();
}
bool Chessboard::move(string opt) {
	bool flag1 = false, flag2 = false;
	flag1 = align(opt);
	flag2 = merge(opt);
	align(opt);
	if (flag1 == false and flag2 == false) // 判断是否有移动
		return false;
	else
		return true;
}


void Chessboard::show()
{
	cout << "---游戏---2048---" << endl;
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
	cout << "输入操作[w][a][s][d]让数字移动合并: " << endl;
}

bool Chessboard::check()
{
	free = {};
	// 检查是否已经满了

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
		default_random_engine generator(time(NULL));//引擎，发生器
		uniform_int_distribution<unsigned> distribution(min, max); //均匀分布
		int product_idx = distribution(generator);
		int i = free[product_idx][0], j = free[product_idx][1];


		// 有 10% 的概率产生 4
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

bool Chessboard::align(string direction)
{
	bool align_flag = false; // 对齐动作标记
	// 向下对齐 
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
				if (flag == 1) align_flag = true;
			}
		}
	}
	// 向上对齐 
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
				if (flag == 1) align_flag = true;

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
				if (flag == 1) align_flag = true;

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
				if (flag == 1) align_flag = true;

			}
		}
	}
	return align_flag;
}

bool Chessboard::foo(int* p1, int* p2) {
	if (*p1 != 0 and *p1 == *p2) {
		*p1 *= 2; // 保留p1
		*p2 = 0;
		return true;
	}
	return false;
}

bool Chessboard::merge(string direction)
{
	int flag = false;
	int* p1, * p2;
	if (direction == "down") 
		// 上下合并
		for (int col = 0; col < 4; col++) {
			p1 = &(score[3][col]); p2 = &(score[2][col]);
			int flag1 = foo(p1, p2);
			p1 = &(score[2][col]); p2 = &(score[1][col]);
			int flag2 = foo(p1, p2);
			p1 = &(score[1][col]); p2 = &(score[0][col]);
			int flag3 = foo(p1, p2);
			if (flag1 or flag2 or flag3) flag = true;
		}	
	else if (direction == "up")
		for (int col = 0; col < 4; col++) {
			p1 = &(score[0][col]); p2 = &(score[1][col]);
			int flag1 = foo(p1, p2);
			p1 = &(score[1][col]); p2 = &(score[2][col]);
			int flag2 = foo(p1, p2);
			p1 = &(score[2][col]); p2 = &(score[3][col]);
			int flag3 = foo(p1, p2);
			if (flag1 or flag2 or flag3) flag = true;
		}
	else if (direction == "right") 
		for (int row = 0; row < 4; row++) {
			p1 = &(score[row][3]); p2 = &(score[row][2]);
			int flag1 = foo(p1, p2);
			p1 = &(score[row][2]); p2 = &(score[row][1]);
			int flag2 = foo(p1, p2);
			p1 = &(score[row][1]); p2 = &(score[row][0]);
			int flag3 = foo(p1, p2);
			if (flag1 or flag2 or flag3) flag = true;
		}	
	else if (direction == "left")
	{
		// 左右合并
		for (int row = 0; row < 4; row++) {
			p1 = &(score[row][0]); p2 = &(score[row][1]);
			int flag1 = foo(p1, p2);
			p1 = &(score[row][1]); p2 = &(score[row][2]);
			int flag2 = foo(p1, p2);
			p1 = &(score[row][2]); p2 = &(score[row][3]);
			int flag3 = foo(p1, p2);
			if (flag1 or flag2 or flag3) flag = true;
		}
	}
	return flag;

}
