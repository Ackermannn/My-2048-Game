#pragma once
#include<iostream>
#include<vector>
#include <random>
#include <time.h>
using namespace std;
class Chessboard
{
public:
	vector<vector<int>> score; // ������ֵ
	vector<vector<int>> free;  // �հ���������
	Chessboard();
	void down();
	void up();
	void left();
	void right();
	void show();
	bool check();
	bool product();
	bool isWin();
	void align(string direction);
	void merge(string direction);
};