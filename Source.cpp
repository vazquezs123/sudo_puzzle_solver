#include <iostream>
#include <vector>
#include <string>
#include "Board.h"

bool isValidResponse(std::string str);
int main() {
	// create 2d matrix board with
	BOARD myboard;
	std::string userResponse;  //store 'yes' or 'no' from user
	myboard.printBoard();

	// ensure board is correct
	std::cout << "Is this the board you wish to solve? Please answer 'yes' or 'no' : " << std::endl;
	std::cin >> userResponse;
	
	// get valid response
	while (!isValidResponse(userResponse)) {
		std::cout << "Invalid response. Please enter 'yes' or 'no' : " << std::endl;
		std::cin >> userResponse;
	}
	while ( userResponse == "no") {
		myboard.newBoard();
		// ensure board is correct
		std::cout << "Is this the board you wish to solve? Please answer 'yes' or 'no' : " << std::endl;
		std::cin >> userResponse;

		// get valid response
		while (!isValidResponse(userResponse)) {
			std::cout << "Invalid response. Please enter 'yes' or 'no' : " << std::endl;
			std::cin >> userResponse;
		}
	}

	// board is now filled with supposed correct board
	std::cout << "Solving the below board: " << std::endl;
	myboard.printBoard();

	std::cout << myboard.allRowsValid() << myboard.allColsValid() << std::endl;


	return 0;
}

bool isValidResponse(std::string str) {
	bool isValid = false;
	if (str == "yes" || str == "no" ) {
		return true;
	}
	else { return false; }
}
