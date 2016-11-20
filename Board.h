// Board Header File
#ifndef BOARD_H
#define BOARD_H

class BOARD
{

private:
	int board[9][9];

public:
	BOARD();
	void newBoard();
	bool isValidRow(int board[][9], int row);
	void initializeBoard(int board[][9]);
	void fillRow(int bord[][9], int row);
	bool isValidCol(int board[][9], int row);
};

#endif