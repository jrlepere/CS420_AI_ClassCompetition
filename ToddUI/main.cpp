#include <iostream>
#include <ctype.h>
#include "ConnectFour.h"

int getMaximumSeconds();
std::string getMove();
bool firstPlayer();
bool getUserMove(ConnectFour *cFour, std::string &input);

int main() {
	ConnectFour *cFour = new ConnectFour(getMaximumSeconds());

	bool isFirstPlayer = firstPlayer();
	std::cout << "Is first player: " << isFirstPlayer << "\n";

	cFour->printBoard();

	std::string input;
	bool playerTurn = true;

	while (input.compare("-1") != 0 && !cFour->TerminalTest(cFour->getBoard())) {
		if (playerTurn) {
			while (!getUserMove(cFour, input));

			cFour->printBoard();
			playerTurn = !playerTurn;
		}

		// Computer's turn
		else {
			std::cout << "Computer turn...\n";
			while (!getUserMove(cFour, input));
			playerTurn = !playerTurn;
		}
	}

	//std::cout << cFour->TerminalTest(cFour->getBoard());
}

bool getUserMove(ConnectFour *cFour, std::string &input) {
	int correctInput[] = { 0,1,2,3,4,5,6,7 };
	bool cCorrectInput;
	bool iCorrectInput;
	
	int row;
	int col;

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
	if (input.compare("-1") != 0) {
		// If input is successfully put on the board
		return cFour->putOnBoard(PLAYER_MAX, row, col);
	}
	// If user quits
	else {
		return true;
	}
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

bool firstPlayer() {
	std::string input;
	std::cout << "Is this first player? (Y/N): ";
	std::cin >> input;

	input = std::to_string(tolower(input.at(0)));

	if (input.compare("y")) return true;
	else return false;
}