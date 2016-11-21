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
	bool isValidRow(int row);
	void initializeBoard();
	void fillRow(int row);
	bool isValidCol(int row);
	void printBoard();
};

#endif