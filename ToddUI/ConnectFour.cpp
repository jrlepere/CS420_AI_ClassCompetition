#include "ConnectFour.h"

ConnectFour::ConnectFour() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		std::vector<int> oneRow;
		for (int j = 0; j < BOARD_SIZE; j++) {
			oneRow.push_back(0);
		}
		board.push_back(oneRow);
	}
}

ConnectFour::ConnectFour(int input) : ConnectFour() {
	timeTaken = input;
}

ConnectFour::~ConnectFour() {
	//dtor
}

int ConnectFour::getTimeTaken() {
	return timeTaken;
}

int ConnectFour::MinimaxDecision(std::vector<std::vector<int>> state, int depth) {
	std::vector<int> decisions;
	int maxReturn = NEG_INFINITY;

	// TODO. I need to return heuristic + action (row, col to put)
}

bool ConnectFour::TerminalTest(std::vector<std::vector<int>> state) {
	int zeroCounter = 0;

	// Check for win states
	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state.at(i).size(); j++) {
			if (state[i][j] != 0) {
				// Horizontal
				if (j < 5 &&
					state[i][j] == state[i][j + 1] &&
					state[i][j] == state[i][j + 2] &&
					state[i][j] == state[i][j + 3])
					return true;

				// Vertical
				if (i < 5 && 
					state[i][j] == state[i + 1][j] &&
					state[i][j] == state[i + 2][j] &&
					state[i][j] == state[i + 3][j])
					return true;
			}
			else {
				zeroCounter++;
			}
		}
	}
	
	// If there are no zeroes on the board, the board is full
	if (zeroCounter == 0)
		return true;

	return false;
}

std::vector<std::vector<int>> ConnectFour::getBoard() {
	return board;
}

void ConnectFour::printBoard() {
	std::vector<std::vector<int>>::iterator it;
	std::cout << "  1 2 3 4 5 6 7 8 \t Player vs. Opponent" << "\n";

	for (int i = 0; i < board.size(); i++) {
		std::vector<int>::iterator it2;
		char aChar = 'A' + i;
		std::cout << aChar << " ";

		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == 0)
				std::cout << "-" << " ";
			else if (board[i][j] == PLAYER_MAX)
				std::cout << "X" << " ";
			else if (board[i][j] == PLAYER_MIN)
				std::cout << "O" << " ";
		}
		std::cout << "\n";
	}

	std::cout << "\n";
}

bool ConnectFour::putOnBoard(int input, int row, int col) {
	// Check for incorrect inputs
	if (row < 0 ||
		row >= BOARD_SIZE ||
		col < 0 ||
		col >= BOARD_SIZE) {
		
		std::cout << "Incorrect input - Out of bounds.\n";
	}
	else if (board[row][col] != 0) std::cout << "Incorrect input - Space already taken\n";
	else {
		board.at(row).at(col) = input;
		return true;
	}

	return false;
}

int ConnectFour::UtilityFunction(std::vector< std::vector<int> > state, int player) {
	int utility = 0;

	// Check for three in a row
	utility = CheckForThree(state, player);

	return utility;
}

// Check for three in a row
int ConnectFour::CheckForThree(std::vector< std::vector<int> > state, int player) {
	int utility = 0;

	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state[i].size(); j++) {
			// Check horizontally three in a row - [OOO]
			if (j < 6 &&
				state[i][j] != 0 &&
				state[i][j] == state[i][j + 1] &&
				state[i][j] == state[i][j + 2]) {
				utility = MAX_H_VALUE * player;
			}
			// Check disjointed set - [00 0]
			else if (j < 5 &&
				state[i][j] != 0 &&
				state[i][j] == state[i][j + 1] &&
				state[i][j] == state[i][j + 3]) {
				utility = MAX_H_VALUE * player;
			}
			// Check disjointed set - [O OO]
			else if (j < 5 &&
				state[i][j] != 0 &&
				state[i][j] == state[i][j + 2] &&
				state[i][j] == state[i][j + 3]) {
				utility = MAX_H_VALUE * player;
			}

			// Check vertically - [000]
			if (i < 6 &&
				state[i][j] != 0 &&
				state[i][j] == state[i + 1][j] &&
				state[i][j] == state[i + 2][j]
				) {
				utility = MAX_H_VALUE * player;
			}
			// Check disjointed set - [00 0]
			else if (i < 6 &&
				state[i][j] != 0 &&
				state[i][j] == state[i + 1][j] &&
				state[i][j] == state[i + 3][j]
				) {
				utility = MAX_H_VALUE * player;
			}
			// Check disjointed set - [0 00]
			else if (i < 6 &&
				state[i][j] != 0 &&
				state[i][j] == state[i + 2][j] &&
				state[i][j] == state[i + 3][j]
				) {
				utility = MAX_H_VALUE * player;
			}
		}
	}

	return utility;
}

int ConnectFour::MaxValue(std::vector< std::vector<int> > state, int depth) {
	int player;
	
	/*if (depth % 2 == 0) player = PLAYER_MAX;
	else player = PLAYER_MIN;*/

	// DEBUG
	player = PLAYER_MAX;
	
	if (TerminalTest(state)) return UtilityFunction(state, player);
	int v = NEG_INFINITY;
	
	std::vector< std::vector<int> > successors = getSuccessors(state);

	for (std::vector<int> action : successors) {
		int row = action[0];
		int col = action[1];
		board[row][col] = player; // temporarily set the board to this move
		int minHeuristic = ConnectFour::MinValue(board, depth + 1);
		board[row][col] = 0; // reset board

		// Check if successor's heuristic is greater than our current heuristic
		v = std::max(v, minHeuristic);
	}

	return v;
}

int ConnectFour::MinValue(std::vector< std::vector<int> > state, int depth) {
	int player;

	/*if (depth % 2 == 0) player = PLAYER_MAX;
	else player = PLAYER_MIN;*/

	// DEBUG
	player = PLAYER_MIN;

	if (TerminalTest(state)) return UtilityFunction(state, player);
	int v = POS_INFINITY;

	std::vector< std::vector<int> > successors = getSuccessors(state);

	for (std::vector<int> action : successors) {
		int row = action[0];
		int col = action[1];
		board[row][col] = player; // temporarily set the board to this move
		int maxHeuristic = ConnectFour::MaxValue(board, depth + 1);
		board[row][col] = 0; // reset board

		// Check if successor's heuristic is greater than our current heuristic
		v =	std::min(v, maxHeuristic);
	}

	return v;
}

std::vector< std::vector<int> > ConnectFour::getSuccessors(std::vector< std::vector<int> > state) {
	std::vector< std::vector<int> > rowAndCol;

	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state[i].size(); j++) {
			std::vector<int> temp;
			if (state[i][j] == 0) {
				temp.push_back(i); // insert row
				temp.push_back(j); // insert column
			}
			rowAndCol.push_back(temp);
		}
	}

	return rowAndCol;
}

int ConnectFour::chosenHeuristic(std::vector< std::vector<int> > state, int depth) {
	return debugHeuristic(state, depth);
}

int ConnectFour::debugHeuristic(std::vector< std::vector<int> > state, int depth) {
	int player;
	if (depth % 2 == 0) player = PLAYER_MAX;
	else player = PLAYER_MIN;

	return ConnectFour::UtilityFunction(state, player);
}