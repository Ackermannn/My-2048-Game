#include "Chessboard.h"
int main() {

	Chessboard chess;
	char temp;
	while (true)
	{
		if (chess.isWin()) {
			cout << "YOU WIN !!!!" << endl;
			break;
		}
		if (chess.product() == false) break;
		chess.show();	
		cin >> temp;		
		int wrong_flag = 1;
		while (wrong_flag)
		{
			system("cls");
			wrong_flag = 0;
			bool move_flag = true;

			if (temp == 'w') move_flag = chess.move("up");
			else if (temp == 's') move_flag = chess.move("down");
			else if (temp == 'a') move_flag = chess.move("left");
			else if (temp == 'd') move_flag = chess.move("right");
			else {
				chess.show();
				cout << "输入错误,请重新输入: " << endl;
				wrong_flag = 1;
				cin >> temp;
			}
			if (move_flag == false) {
				cout << "无法移动,请重新输入: " << endl;
				chess.show();
				wrong_flag = 1; 
				cin >> temp;

			}
		}
	}
	cout << "Game is over" << endl;
	cout << "输入任意字符退出: " << endl;
	return 0;
}
