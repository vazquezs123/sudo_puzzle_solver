// Board Header File
#ifndef BOARD_H
#define BOARD_H

class BOARD
{

private:
	int board[9][9]; // stored 2d matrix representing board
	int section1[9]; // each section represents 1 of the 9 seperate sections of soduku board starting at the upper left section starting at 1, incrementing in section from left to right
	int section2[9];
	int section3[9];
	int section4[9];
	int section5[9];
	int section6[9];
	int section7[9];
	int section8[9];
	int section9[9];

public:
	BOARD();
	void newBoard();
	bool isValidRow(int row);
	void initializeBoard();
	void fillRow(int row);
	void fillSections();
	bool isValidCol(int row);
	void printBoard(); 
	void initializeSections();
	void solveBoard();
	void printSections(); // print all sections
	void printSection(int section[]);  // print single section

};

#endif