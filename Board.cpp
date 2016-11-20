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
	initializeBoard(board);
	std::cout << "Empty Boxes should be inputted as 0. " << std::endl;
	std::cout << "When entering rows, please follow this exapmle format " << std::endl;
	std::cout << "0 2 1 0 0 3 0 0 9" << std::endl;
	
	for (int i = 0; i < 9; i++) {
		
		// get user row and check if valid row if not ask for new row
		int j = 0;
		fillRow(board, i);
		while (!isValidRow(board, i) && !isValidCol(board,i)) {
			fillRow(board, i);
		}
	}
}

void BOARD::fillRow(int bord[][9], int row) {
	// input row
	std::cout << "Please inpute row: " << row << std::endl;
	for (int j = 0; j < 9; j++) {
		int n;
		std::cin >> n;
		board[row][j] = n;
	}
}


void BOARD::initializeBoard(int board[][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			board[i][j] = -1;
		}
	}
}

////////////////////////////////////////
//  function to test if row is valid
////////////////////////////////////////
bool BOARD::isValidRow(int board[][9], int row) {
	

	for (int i = 0; i < 9; i++) {
		int tempN = board[row][i];

		// check for duplicates
		for (int j = 0; j < 9; j++) {
			// make sure not looking at same cell
			if (tempN == board[row][j] && i != j && tempN != 0) { // there is a duplicate
				std::cout << "Duplicate at row: " << row << " col: " << j + 1 << std::endl;
				return false;
			}
		}

		// check number valid number
		for (int i = 0; i < 9; i++) {
			if (board[row][i] < 0 || board[row][i] > 9) {
				std::cout << "Invalid number at row: " << row << " col: " << i << std::endl;
				return false;
			}
		}
	}
	return true;
}

////////////////////////////////////////
//  function to test if col is valid
////////////////////////////////////////
bool BOARD::isValidCol(int board[][9], int row) {
	// check for duplicates
	for (int j = 0; j < 9; j++) {
		int tempN = board[row][j];
		for (int i = row; i >= 0; i--) {
			// make sure not looking at same cell
			if (tempN == board[i][j] && i != j && tempN != 0 && tempN != -1) { // there is a duplicate
				std::cout << "Duplicate at row: " << row << " col: " << j + 1 << std::endl;
				return false;
			}
		}
	}
	return true;
}
