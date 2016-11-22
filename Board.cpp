// A2DD.cpp
#include "BOARD.h"
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
		fillRow(i);
		while (!isValidRow(i) || !isValidCol(i)) {
			fillRow(i);
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
			std::cout << board[i][j] << "|";
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------" << std::endl;
}

void BOARD::fillRow(int row) {
	// input row
	std::cout << "Please inpute row: " << row << std::endl;
	for (int j = 0; j < 9; j++) {
		int n;
		std::cin >> n;
		board[row][j] = n;
	}
}


void BOARD::initializeBoard() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			board[i][j] = -1;
		}
	}
}

void BOARD::initializeSections() {
	for (int i = 0; i < 9; i++) {
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
		int tempN = board[row][i];

		// check for duplicates
		for (int j = 0; j < 9; j++) {
			// make sure not looking at same cell
			if (tempN == board[row][j] && i != j && tempN > 0) { // there is a duplicate that are not 0
				std::cout << "Duplicate in row: " << row + 1 << std::endl;
				std::cout << "n: " << tempN << std::endl; ////####
				std::cout << "board" << board[row][j] << std::endl;
				std::cout << "i: "<< i << " j: " << j << std::endl;
				return false;
			}
		}

		// check number valid number
		for (int i = 0; i < 9; i++) {
			if (board[row][i] < 0 || board[row][i] > 9) {
				std::cout << "Invalid number at row: " << row + 1 << " col: " << i << std::endl;
				return false;
			}
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
			int tempN = board[i][j];

			for (int k = 0; k < 9; k++) {
				// make sure not looking at same cell
				if (tempN == board[i][k] && k != j && tempN >= 0) { // there is a duplicate including 0 which is allowed in valid row, but not in win condition of valid row
					std::cout << "Duplicate in row: " << i + 1 << std::endl;
					std::cout << "n: " << tempN << std::endl; ////####
					std::cout << "allboard" << board[i][j] << std::endl;
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
		int tempN = board[row][j];
		for (int i = row; i >= 0; i--) { // i in this loop acts as aa column index
			// make sure not looking at same cell
			if (tempN == board[row][i] && i != j && tempN > 0) { // there is a duplicate
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
			int tempN = board[i][j];
			for (int k = 0; k < 9; k++){ // check if duplicates for each column by traversing rows
				// make sure not looking at same cell
				if (tempN == board[k][j] && i != k && tempN >= 0) { // there is a duplicate including 0 which is allowed in valid row, but not in win condition of valid row
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
				section1[ind1] = board[i][j];
				ind1++;
			}
			else if (i == 1) {
				section2[ind2] = board[i][j];
				ind2++;
			}
			else if (i == 2) {
				section3[ind3] = board[i][j];
				ind3++;
			}
			else if (i == 3) {
				section4[ind4] = board[i][j];
				ind4++;
			}
			else if (i == 4) {
				section5[ind5] = board[i][j];
				ind5++;
			}
			else if (i == 5) {
				section6[ind6] = board[i][j];
				ind6++;
			}
			else if (i == 6) {
				section7[ind7] = board[i][j];
				ind7++;
			}
			else if (i == 7) {
				section8[ind8] = board[i][j];
				ind8++;
			}
			else if (i == 8) {
				section9[ind9] = board[i][j];
				ind9++;
			}
		}
	}
}

void BOARD::solveBoard() {
	// win condition
	
	
}
