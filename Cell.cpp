#include "Cell.h"
#include <vector>
#include <iostream>
/*
CELL::CELL(BOARD* board, int i, int j, int n)
{
	
}

// check if number exists in row
bool Cell::nInRow(int row, int n) {
	for (int j = 0; j < 9; j++) {
		if (board[row][j] == n) { return true; }
	}
	return false;
}

// check if number exists in col
bool Cell::nInCol(int col, int n) {
	for (int i = 0; i < 9; i++) {
		if (board[i][col] == n) { return true; }
	}

	return false;
}

// check if number is in section
// n is potential number to be place on board
bool Cell::nInSection(int section[], int n) {
	for (int i = 0; i < 9; i++) {
		if (section[i] == n)
			return true;
	}
	return false;
}

bool Cell::nInAdjRows(int row, int n) {
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

bool Cell::nInAdjCols(int col, int n) {
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
*/