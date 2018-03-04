/*
 * Human.cpp
 *
 *  Created on: Feb 23, 2018
 *      Author: JLepere2
 */

#include <iostream>
#include "Human.h"

vector<int> Human::getMove(vector<vector<int> >& board, int previousRow, int previousCol, int currentNumTiles) {
	int correctInput[] = { 0,1,2,3,4,5,6,7 };
	bool cCorrectInput;
	bool iCorrectInput;
	bool isBoardPieceEmpty;
	
	int row;
	int col;

	string input;

	do {
		cCorrectInput = false;
		iCorrectInput = false;
		isBoardPieceEmpty = false;

		std::cout << "Enter move. Enter -1 to quit: ";
		std::cin >> input;

		if (input.length() != 2) {
			std::cout << "ERROR: Incorrect length of input." << "\n";
		}

		// Check first character
		row = tolower(input.at(0)) - 'a';
		col = input.at(1) - '0' - 1;

		for (int i = 0; i < BOARD_SIZE; i++) {
			if (row == correctInput[i])
				cCorrectInput = true;
			if (col == correctInput[i])
				iCorrectInput = true;
		}

		if (cCorrectInput && iCorrectInput && board[row][col] != 0) {
			std::cout << "ERROR: Position already occupied.\n";
		}
		else if (cCorrectInput && iCorrectInput && board[row][col] == 0) {
			isBoardPieceEmpty = true;
		}

		if (input.compare("-1") && (!cCorrectInput || !iCorrectInput)) {
			std::cout << "ERROR: Incorrect input." << "\n";
		}
		std::cout << "\n";
		
	} while (input.compare("-1") != 0 && (input.length() != 2 || !cCorrectInput || !iCorrectInput || !isBoardPieceEmpty));

	// Check if user quits
	if (input.compare("-1") != 0) {
		return {row,col};
	}
	// If user quits
	else {
		std::cout << "Thank you for playing!\n";
		exit(EXIT_SUCCESS);
	}
}
