#include <iostream>
#include "ConnectFour.h"

int getMaximumSeconds();
std::string getMove();

int main() {
	ConnectFour *cFour = new ConnectFour(getMaximumSeconds());
	
	cFour->printBoard();
	
	std::string input;
	int correctInput[] = { 0,1,2,3,4,5,6,7 };
	bool cCorrectInput;
	bool iCorrectInput;
	int row;
	int col;

	while (input.compare("-1") != 0 && !cFour->TerminalTest(cFour->getBoard())) {
		do {
			cCorrectInput = false;
			iCorrectInput = false;

			input = getMove();
			if (input.length() != 2) {
				std::cout << "ERROR: Incorrect length of input." << "\n";
			}

			// Check first character
			row = toupper(input.at(0)) - 'A';
			col = input.at(1) - '0' - 1;

			for (int i = 0; i < BOARD_SIZE; i++) {
				if (row == correctInput[i])
					cCorrectInput = true;
				if (col == correctInput[i])
					iCorrectInput = true;
			}

			if (input.compare("-1") && (!cCorrectInput || !iCorrectInput)) {
				std::cout << "ERROR: Incorrect input." << "\n";
			}

			std::cout << "\n";
		} while (input.compare("-1") != 0 && (input.length() != 2 || !cCorrectInput || !iCorrectInput));

		// Check if user quits
		if (input.compare("-1") != 0) cFour->putOnBoard(PLAYER_MIN, row, col);
		
		cFour->printBoard();
	}

	//std::cout << cFour->TerminalTest(cFour->getBoard());
}

int getMaximumSeconds() {
	int input;
	std::cout << "Enter max time allowed to \"think\"\n";
	std::cout << ">>> ";
	std::cin >> input;
	return input;
}

std::string getMove() {
	std::string input;
	std::cout << "Enter move. Enter -1 to quit: ";
	std::cin >> input;
	return input;
}