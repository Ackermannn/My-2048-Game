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
		if (chess.product() == false) break;
		chess.show();	
		cin >> temp;		
		int wrong_flag = 1;
		while (wrong_flag)
		{
			system("cls");
			wrong_flag = 0;

			if (temp == 'w') chess.up();
			else if (temp == 's') chess.down();
			else if (temp == 'a') chess.left();
			else if (temp == 'd') chess.right();
			else {
				chess.show();
				cout << "输入错误,请重新输入: " << endl;
				wrong_flag = 1;
				cin >> temp;
			}
		}
	}
	cout << "Game is over" << endl;
	cout << "输入任意字符退出: " << endl;
	return 0;
}
