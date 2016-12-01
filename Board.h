// Board Header File
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <unordered_map>

struct Cell{
	int row;
	int col;
	int value;
	std::vector<int> potentialNums;
	int isFilled = false;
};

class BOARD
{

private:
	Cell board[9][9]; // stored 2d matrix representing board
	int section1[9]; // each section represents 1 of the 9 seperate sections of soduku board starting at the upper left section starting at 1, incrementing in section from left to right
	int section2[9];
	int section3[9];
	int section4[9];
	int section5[9];
	int section6[9];
	int section7[9];
	int section8[9];
	int section9[9];
	std::vector<Cell> cellList;

public:
	BOARD();
	void newBoard();
	bool isValidRow(int row);
	void initializeBoard();
	void fillBoardByRow(int row);
	void fillSections();
	bool isValidCol(int row);
	void printBoard(); 
	void initializeSections();
	void printSections(); // print all sections
	void printSection(int section[]);  // print single section
	bool allRowsValid();
	bool allColsValid();
	bool allSectionsValid(); // checks are sections
	bool isValidSection(int section[]); // checks single section
	bool solveBoard();
	bool winCase();
	bool nInRow(int row, int n); // check if n exists in row
	bool nInCol(int col, int n); // check if n exists in col
	bool nInSection(int section[], int n); // check if n exists in section
	bool nInAdjRows(int row, int n); // checks if n in adj rows for winning condition
	bool nInAdjCols(int col, int n); // checks if n is in adj cols for winning condition
	bool canBeFilled(int row, int col, int k);	// checks if cell can be filled; k is equivalent to n
	void appendToCellList(int row, int col, int n); // appends new element to cellList with row, col, and list of qualifying numbers
	void getCellList(); // get list of potential numbers for every cell
	void printCellList(); // print cellList
	~BOARD();

};

#endif