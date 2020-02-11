#pragma once
#include<iostream>
#include<vector>
#include <random>
#include <time.h>
using namespace std;
class Chessboard
{
	bool foo(int* p1, int* p2);
public:
	vector<vector<int>> score; // 棋盘数值
	vector<vector<int>> free;  // 空白区的坐标
	Chessboard();
	bool move(string opt);
	void show();
	bool check();
	bool product();
	bool isWin();
	bool align(string direction);
	bool merge(string direction);
};