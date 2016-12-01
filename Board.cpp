// A2DD.cpp
#include "Board.h"
#include <vector>
#include <iostream>

BOARD::BOARD()
{
	newBoard();
}

/////////////////////////////////////////////////
// function to prompt user to generate new board 
// by inputting numbers one row at a time
/////////////////////////////////////////////////
void BOARD::newBoard() {
	initializeBoard();
	initializeSections();
	std::cout << "Empty Boxes should be inputted as 0. " << std::endl;
	std::cout << "When entering rows, please follow this exapmle format " << std::endl;
	std::cout << "0 2 1 0 0 3 0 0 9" << std::endl;
	
	for (int i = 0; i < 9; i++) {
		
		// get user row and check if valid row if not ask for new row
		fillBoardByRow(i);
		while (!isValidRow(i) || !isValidCol(i)) {
			fillBoardByRow(i);
		}
	}
	fillSections();
}

/////////////////////////////
// function to print board
/////////////////////////////
void BOARD::printBoard() {
	std::cout << "-------------------" << std::endl;
	for (int i = 0; i < 9; i++) {
		if( i == 3 || i == 6) { 
			std::cout << "|-----|-----|-----|" << std::endl;
			std::cout << "|";
		}
		else{ std::cout << "|"; }
		for (int j = 0; j < 9; j++) {
			std::cout << board[i][j].value << "|";
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------" << std::endl;
}

void BOARD::fillBoardByRow(int row) {
	// input row
	std::cout << "Please input row: " << row << std::endl;
	for (int j = 0; j < 9; j++) {
		int n;
		std::cin >> n;
		board[row][j].value = n;
		board[row][j].row = row;
		board[row][j].col = j;
	}
}


void BOARD::initializeBoard() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			board[i][j].value = -1;
		}
	}
}

void BOARD::initializeSections() {
	for (int i = 1; i < 10; i++) {
		section1[i] = -1;
		section2[i] = -1;
		section3[i] = -1;
		section4[i] = -1;
		section5[i] = -1;
		section6[i] = -1;
		section7[i] = -1;
		section8[i] = -1;
		section9[i] = -1;
	}
}

void BOARD::printSections() {
	printSection(section1);
	printSection(section2);
	printSection(section3);
	printSection(section4);
	printSection(section5);
	printSection(section6);
	printSection(section7);
	printSection(section8);
	printSection(section9);
}

void BOARD::printSection(int section[]) {
	for (int i = 0; i < 9; i++) { 
		std::cout << section[i] << " ";
	}
	std::cout << std::endl;
}

////////////////////////////////////////
//  function to test if row is valid
////////////////////////////////////////
bool BOARD::isValidRow(int row) {

	for (int i = 0; i < 9; i++) {
		int tempN = board[row][i].value;

		// check for duplicates
		for (int j = 0; j < 9; j++) {
			// make sure not looking at same cell
			if (tempN == board[row][j].value && i != j && tempN > 0) { // there is a duplicate that are not 0
				std::cout << "Duplicate in row: " << row + 1 << std::endl;
				std::cout << "n: " << tempN << std::endl; ////####
				std::cout << "board" << board[row][j].value << std::endl;
				std::cout << "i: "<< i << " j: " << j << std::endl;
				return false;
			}
		}

		// check number valid number
		for (int i = 0; i < 9; i++) {
			if (board[row][i].value < 0 || board[row][i].value > 9) {
				std::cout << "Invalid number at row: " << row + 1 << " col: " << i << std::endl;
				return false;
			}
			board[row][i].isFilled = true;
		}
	}
	return true;
}

////////////////////////////////////////
//  function to test if row is valid winning
////////////////////////////////////////
bool BOARD::allRowsValid() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int tempN = board[i][j].value;

			for (int k = 0; k < 9; k++) {
				// make sure not looking at same cell
				if (tempN == board[i][k].value && k != j && tempN >= 0) { // there is a duplicate including 0 which is allowed in valid row, but not in win condition of valid row
					std::cout << "Duplicate in row: " << i + 1 << std::endl;
					std::cout << "n: " << tempN << std::endl; ////####
					std::cout << "allboard" << board[i][j].value << std::endl;
					std::cout << "i: " << i << " j: " << j << std::endl;
					return false;
				}
			}
		}
	}
	return true;
}

////////////////////////////////////////
//  function to test if col is valid
////////////////////////////////////////
bool BOARD::isValidCol(int row) {
	// check for duplicates
	for (int j = 0; j < 9; j++) {
		int tempN = board[row][j].value;
		for (int i = row; i >= 0; i--) { // i in this loop acts as aa column index
			// make sure not looking at same cell
			if (tempN == board[row][i].value && i != j && tempN > 0) { // there is a duplicate
				std::cout << "Duplicate in col: " << j + 1 << std::endl;
				std::cout << "n: " << tempN << std::endl;
				return false;
			}
		}
	}
	return true;
}

bool BOARD::allColsValid() {
	// check for duplicates
	for (int j = 0; j < 9; j++) { // traverse columns
		for (int i = 0; i < 9; i++) { // traverse rows
			int tempN = board[i][j].value;
			for (int k = 0; k < 9; k++){ // check if duplicates for each column by traversing rows
				// make sure not looking at same cell
				if (tempN == board[k][j].value && i != k && tempN >= 0) { // there is a duplicate including 0 which is allowed in valid row, but not in win condition of valid row
					std::cout << "Duplicate in allcol: " << j + 1 << std::endl;
					std::cout << "n: " << tempN << std::endl;
					return false;
				}
			}
		}
	}
	return true;
}


///////////////////////////////////////////
//  function to fill sections of board
////////////////////////////////////////////
void BOARD::fillSections() {
	// initialize traversal index for each section
	int ind1 = 0, ind2 = 0, ind3 = 0, ind4 = 0, ind5 = 0, ind6 = 0, ind7 = 0, ind8 = 0, ind9 = 0;

	// fill sections
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == 0) {
				section1[ind1] = board[i][j].value;
				ind1++;
			}
			else if (i == 1) {
				section2[ind2] = board[i][j].value;
				ind2++;
			}
			else if (i == 2) {
				section3[ind3] = board[i][j].value;
				ind3++;
			}
			else if (i == 3) {
				section4[ind4] = board[i][j].value;
				ind4++;
			}
			else if (i == 4) {
				section5[ind5] = board[i][j].value;
				ind5++;
			}
			else if (i == 5) {
				section6[ind6] = board[i][j].value;
				ind6++;
			}
			else if (i == 6) {
				section7[ind7] = board[i][j].value;
				ind7++;
			}
			else if (i == 7) {
				section8[ind8] = board[i][j].value;
				ind8++;
			}
			else if (i == 8) {
				section9[ind9] = board[i][j].value;
				ind9++;
			}
		}
	}
}

bool BOARD::isValidSection(int section[]) {
	for (int i = 0; i < 9; i++) {
		int tempN = section[i];
		for (int j = 0; j < 9; j++) {
			if (tempN == section[j] && i != j) {
				std::cout << "Invalid section. TempN: " << tempN << std::endl;
				return false;
			}
		}
	}
	return true;
}

bool BOARD::allSectionsValid() {
	if (!isValidSection(section1) || !isValidSection(section2) || !isValidSection(section3) || !isValidSection(section4) || !isValidSection(section5) || !isValidSection(section6) || !isValidSection(section7) || !isValidSection(section8) || !isValidSection(section9)) {
		return false;
	}

	return true;
}

/*
void BOARD::printCellList(){
	std::cout << "Printing Cell List: " << std::endl;
	for (int i = 0; i < cellList.size(); i++) {
		std::cout << "\nrow: " << cellList[i].row << std::endl;
		std::cout << "col: " << cellList[i].col << std::endl;
		std::cout << "Potential Numbers: ";
		for (int j = 0; j < cellList[i].potentialNums.size(); j++) {
			std::cout << cellList[i].potentialNums[j] << " ";
		}
	}
}
*/

// cell class
// have 2d of vector

void BOARD::appendToCellList(int row, int col, int n) {
	board[row][col].potentialNums.push_back(n);
	
	/*
	Cell tempCell = new Cell();
	tempCell.row = row;
	tempCell.col = col;
	tempCell.potentialNums.push_back(n);
	cellList.push_back(tempCell);
	*/

	//cellList.push_back(Cell());
	//cellList[cellList.size() - 1].row = row;
	//cellList[cellList.size() - 1].col = col;
	//cellList[cellList.size() - 1].potentialNums.push_back(int());
	//cellList[cellList.size() - 1].potentialNums[cellList[cellList.size() - 1].potentialNums.size() - 1] = n;
}

bool BOARD::winCase() {
	// win condition
	if (allSectionsValid() && allColsValid() && allRowsValid()) {
		return true;
	}
	return false;
}

// fills cells that can be filled and gets list of potential numbers for cells that aren't filled
void BOARD::getCellList() {
	// check if each cell can be filled
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				// if current cell can be filled with k, do so
				if (canBeFilled(i, j, k) && board[i][j].isFilled == false) {
					board[i][j].value = k; // fill current cell with k
					std::cout << "Set row: " << i << " col: " << j << " to value: " << board[i][j].value << std::endl;
					board[i][j].isFilled = true;
					break;
				}
				else {
					appendToCellList(i, j, k);
					//std::cout << "Appending potential number: " << k << " to potential # list for row: " << i << " col: " << j << std::endl;
				}
			}
		}
	}
}

// check if individual cell can be filled with numbers 1 - 9
bool BOARD::canBeFilled(int row, int col, int k) {
	// can fill condition for section 1; qualifying number not in row; qualifying number not in col; qualifying number (k) not in section; qualyfing number is in row: current row + 1 && current row + 2; qualifying number in current 
	if (row >= 0 && row <= 2 && col >= 0 && col <= 2) { // condition for section 1
		if (board[row][col].value == 0 && !nInRow(row, k) && !nInCol(col, k) && !nInSection(section1, k) && nInAdjRows(row, k) && nInAdjCols(col, k)) { // if true, it can be filled with k; i = current row, j = current col
			return true;
		}
	}
	// can filll condition for section 2 fil
	else if (row >= 0 && row <= 2 && col >= 3 && col <= 5) { // condition for section 2
		if (board[row][col].value == 0 && !nInRow(row, k) && !nInCol(col, k) && !nInSection(section2, k) && nInAdjRows(row, k) && nInAdjCols(col, k)) { // if true, it can be filled with k; i = current row, j = current col
			return true;
		}
	}
	// can filll condition for section 3 fil
	else if (row >= 0 && row <= 2 && col >= 6 && col <= 8) { // condition for section 3
		if (board[row][col].value == 0 && !nInRow(row, k) && !nInCol(col, k) && !nInSection(section3, k) && nInAdjRows(row, k) && nInAdjCols(col, k)) { // if true, it can be filled with k; i = current row, j = current col
			return true;
		}
	}
	// can filll condition for section 4 fil
	else if (row >= 3 && row <= 5 && col >= 0 && col <= 2) { // condition for section 4
		if (board[row][col].value == 0 && !nInRow(row, k) && !nInCol(col, k) && !nInSection(section4, k) && nInAdjRows(row, k) && nInAdjCols(col, k)) { // if true, it can be filled with k; i = current row, j = current col
			return true;
		}
	}
	// can filll condition for section 5 fil
	else if (row >= 3 && row <= 5 && col >= 3 && col <= 5) { // condition for section 5
		if (board[row][col].value == 0 && !nInRow(row, k) && !nInCol(col, k) && !nInSection(section5, k) && nInAdjRows(row, k) && nInAdjCols(col, k)) { // if true, it can be filled with k; i = current row, j = current col
			return true;
		}
	}
	// can filll condition for section 6 fil
	else if (row >= 3 && row <= 5 && col >= 6 && col <= 8) { // condition for section 6
		if (board[row][col].value == 0 && !nInRow(row, k) && !nInCol(col, k) && !nInSection(section6, k) && nInAdjRows(row, k) && nInAdjCols(col, k)) { // if true, it can be filled with k; i = current row, j = current col
			return true;
		}
	}
	// can filll condition for section 7 fil
	else if (row >= 6 && row <= 8 && col >= 0 && col <= 2) { // condition for section 7
		if (board[row][col].value == 0 && !nInRow(row, k) && !nInCol(col, k) && !nInSection(section7, k) && nInAdjRows(row, k) && nInAdjCols(col, k)) { // if true, it can be filled with k; i = current row, j = current col
			return true;
		}
	}
	// can filll condition for section 8 fil
	else if (row >= 6 && row <= 8 && col >= 3 && col <= 5) { // condition for section 8
		if (board[row][col].value == 0 && !nInRow(row, k) && !nInCol(col, k) && !nInSection(section8, k) && nInAdjRows(row, k) && nInAdjCols(col, k)) { // if true, it can be filled with k; i = current row, j = current col
			return true;
		}
	}
	// can filll condition for section 9 fil
	else if (row >= 6 && row <= 8 && col >= 6 && col <= 8) { // condition for section 9
		if (board[row][col].value == 0 && !nInRow(row, k) && !nInCol(col, k) && !nInSection(section9, k) && nInAdjRows(row, k) && nInAdjCols(col, k)) { // if true, it can be filled with k; i = current row, j = current col
			return true;
		}
	}
	else {
		std::cout << "Invalid cell from function canBeFilled() " << std::endl;
		return false;
	}
}

// check if number exists in row
bool BOARD::nInRow(int row, int n) {
	for (int j = 0; j < 9; j++) {
		if (board[row][j].value == n) { return true; }
	}
	return false;
}

// check if number exists in col
bool BOARD::nInCol(int col, int n) {
	for (int i = 0; i < 9; i++) {
		if (board[i][col].value == n) { return true; }
	}

	return false;
}

// check if number is in section
// n is potential number to be place on board
bool BOARD::nInSection(int section[], int n) {
	for (int i = 0; i < 9; i++) {
		if (section[i] == n)
			return true;
	}
	return false;
}

bool BOARD::nInAdjRows(int row, int n) {
	// col 1 condition
	if (row == 0) {
		if (nInRow(row + 1, n) && nInRow(row + 2, n)) { return true; }
	}
	else if (row == 1) {
		if (nInRow(row - 1, n) && nInRow(row + 1, n)) { return true; }
	}
	else if (row == 2) {
		if (nInRow(row - 1, n) && nInRow(row - 2, n)) { return true; }
	}
	else if (row == 3) {
		if (nInRow(row + 1, n) && nInRow(row + 2, n)) { return true; }
	}
	else if (row == 4) {
		if (nInRow(row - 1, n) && nInRow(row + 1, n)) { return true; }
	}
	else if (row == 5) {
		if (nInRow(row - 1, n) && nInRow(row - 2, n)) { return true; }
	}
	else if (row == 6) {
		if (nInRow(row + 1, n) && nInRow(row + 2, n)) { return true; }
	}
	else if (row == 7) {
		if (nInRow(row - 1, n) && nInRow(row + 1, n)) { return true; }
	}
	else if (row == 8) {
		if (nInRow(row - 1, n) && nInRow(row - 2, n)) { return true; }
	}
	else {
		return false;
	}
}

bool BOARD::nInAdjCols(int col, int n) {
	// row 1 condition
	if (col == 0) {
		if (nInCol(col + 1, n) && nInCol(col + 2, n)) { return true; }
	}
	else if (col == 1) {
		if (nInCol(col - 1, n) && nInCol(col + 1, n)) { return true; }
	}
	else if (col == 2) {
		if (nInCol(col - 1, n) && nInCol(col - 2, n)) { return true; }
	}
	else if (col == 3) {
		if (nInCol(col + 1, n) && nInCol(col + 2, n)) { return true; }
	}
	else if (col == 4) {
		if (nInCol(col - 1, n) && nInCol(col + 1, n)) { return true; }
	}
	else if (col == 5) {
		if (nInCol(col - 1, n) && nInCol(col - 2, n)) { return true; }
	}
	else if (col == 6) {
		if (nInCol(col + 1, n) && nInCol(col + 2, n)) { return true; }
	}
	else if (col == 7) {
		if (nInCol(col - 1, n) && nInCol(col + 1, n)) { return true; }
	}
	else if (col == 8) {
		if (nInCol(col - 1, n) && nInCol(col - 2, n)) { return true; }
	}
	else {
		return false;
	}
}

BOARD::~BOARD() {
}