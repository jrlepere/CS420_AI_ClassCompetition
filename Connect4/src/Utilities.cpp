/*
 * Utilities.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#include "Utilities.h"

using namespace std;

vector<string> UtilityFunctions::pastMoves;
string UtilityFunctions::rowStr[BOARD_SIZE] = {"A","B","C","D","E","F","G"};
string UtilityFunctions::colStr[BOARD_SIZE] = {"1","2","3","4","5","6","7","8"};

/*
	for (int row = 0; row < BOARD_SIZE; row ++) {
		if ((board[row][0] == 0) && (board[row][4] == 0) && (board[row][1] != 0) && (board[row][1] == board[row][2]) && (board[row][2] == board[row][3])) return board[row][3] * 100;
		if ((board[row][1] == 0) && (board[row][5] == 0) && (board[row][2] != 0) && (board[row][2] == board[row][3]) && (board[row][3] == board[row][4])) return board[row][4] * 100;
		if ((board[row][2] == 0) && (board[row][6] == 0) && (board[row][3] != 0) && (board[row][3] == board[row][4]) && (board[row][4] == board[row][5])) return board[row][5] * 100;
		if ((board[row][3] == 0) && (board[row][7] == 0) && (board[row][4] != 0) && (board[row][4] == board[row][5]) && (board[row][5] == board[row][6])) return board[row][6] * 100;
	}

	return 0;
*/

void UtilityFunctions::printBoard(vector<vector<int> > board) {
	cout << "  0 1 2 3 4 5 6 7"
		<< "\t" << "Player vs. Opponent" // debug this
		<< "\n";

	int size = pastMoves.size();
	int numberOfTurns = floor((size / 2.0) + 0.5);
	int counterIndex = 0;

	for (int row = 0; row < BOARD_SIZE; row ++) {
		cout << row << " ";
		for (int col = 0; col < BOARD_SIZE; col ++) {
			int v = board[row][col];
			if (v == 1) cout<<"X"<<" ";
			else if (v == -1) cout<<"O"<<" ";
			else cout<<"-"<<" ";
		}

		if (numberOfTurns > 0) {
			std::cout << "\t" << (row + 1) << ". " << pastMoves.at(counterIndex++);
			if (size % 2 == 0) {std::cout << " " << pastMoves.at(counterIndex++);}
			numberOfTurns--;
		}
		cout<<"\n";
	}
	int row = 8;
	while (numberOfTurns > 0) {
		// Leave some space
		std::cout << "                 ";
		std::cout << "\t" << (row++ + 1) << ". " << pastMoves.at(counterIndex++);
		if (size % 2 == 0) {std::cout << " " << pastMoves.at(counterIndex++);}
		std::cout << "\n";
		numberOfTurns--;
	}
	cout<<"\n";
}

void UtilityFunctions::addMove(int row, int col) {
	/*string move = colStr[row];
	move.append(colStr[col]);
	pastMoves.push_back(move);*/

	string debug[BOARD_SIZE] = {"0","1","2","3","4","5","6","7"};
	string move = debug[row];
	move.append(debug[col]);
	pastMoves.push_back(move);
}

int UtilityFunctions::terminalBoard(vector<vector<int> > board, int depth) {
	int value = 100;

	int player;
	if (depth % 2 == 0) player = MAX;
	else player = MIN;

	bool opponentFound = false;

	// ROW TEST
	for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int i = 0; i < 5; i ++) {
			if ((board[row][i] != 0) &&
				(board[row][i] == board[row][i+1]) &&
				(board[row][i+1] == board[row][i+2]) &&
				(board[row][i+2] == board[row][i+3])
			) {
				if (board[row][i] != player) opponentFound = true;
				else return board[row][i] * value;
			}
		}
	}

	// COL TEST
	for (int col = 0; col < BOARD_SIZE; col ++) {
		for (int i = 0; i < 5; i ++) {
			if ((board[i][col] != 0) &&
				(board[i][col] == board[i+1][col]) &&
				(board[i+1][col] == board[i+2][col]) &&
				(board[i+2][col] == board[i+3][col])
			) {
				if (board[i][col] != player) opponentFound = true;
				return board[i][col] * value;
			}
		}
	}

	if (opponentFound) return (player * -1) * value;

	value = 99;

	opponentFound = false;

	// ROW TEST
	for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int i = 0; i < 4; i ++) {
			if ((board[row][i] == 0) &&
				(board[row][i+4] == 0) &&
				(board[row][i+1] != 0) &&
				(board[row][i+1] == board[row][i+2]) &&
				(board[row][i+2] == board[row][i+3])
			) {
				if (board[row][i] != player) opponentFound = true;
				else return board[row][i] * value;
			}
		}
	}

	// COL TEST
	for (int col = 0; col < BOARD_SIZE; col ++) {
		for (int i = 0; i < 4; i ++) {
			if ((board[i][col] == 0) &&
				(board[i+4][col] == 0) &&
				(board[i+1][col] != 0) &&
				(board[i+1][col] == board[i+2][col]) &&
				(board[i+2][col] == board[i+3][col])
			) {
				if (board[i][col] != player) opponentFound = true;
				return board[i][col] * value;
			}
		}
	}

	if (opponentFound) return (player * -1) * value;

	value = 98;

	opponentFound = false;

	// ROW TEST
	for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int i = 0; i < 5; i ++) {
			// 3x0 ->
			if ((board[row][i+3] == 0) &&
				(board[row][i] != 0) &&
				(board[row][i] == board[row][i+1]) &&
				(board[row][i+1] == board[row][i+2])
			) {
				if (board[row][i] != player) opponentFound = true;
				else return board[row][i] * value;
			}
			// 3x0 <-
			if ((board[row][BOARD_SIZE-(i+3)-1] == 0) &&
				(board[row][BOARD_SIZE-i-1] != 0) &&
				(board[row][BOARD_SIZE-i-1] == board[row][BOARD_SIZE-(i+1)-1]) &&
				(board[row][BOARD_SIZE-(i+1)-1] == board[row][BOARD_SIZE-(i+2)-1])
			) {
				if (board[row][BOARD_SIZE-i-1] != player) opponentFound = true;
				else return board[row][BOARD_SIZE-i-1] * value;
			}
			// 2x1 ->
			if ((board[row][i+2] == 0) &&
				(board[row][i] != 0) &&
				(board[row][i] == board[row][i+1]) &&
				(board[row][i+1] == board[row][i+3])
			) {
				if (board[row][i] != player) opponentFound = true;
				else return board[row][i] * value;
			}
			// 2x1 <-
			if ((board[row][BOARD_SIZE-(i+2)-1] == 0) &&
				(board[row][BOARD_SIZE-i-1] != 0) &&
				(board[row][BOARD_SIZE-i-1] == board[row][BOARD_SIZE-(i+1)-1]) &&
				(board[row][BOARD_SIZE-(i+1)-1] == board[row][BOARD_SIZE-(i+3)-1])
			) {
				if (board[row][BOARD_SIZE-i-1] != player) opponentFound = true;
				else return board[row][BOARD_SIZE-i-1] * value;
			}
		}
	}

	// COL TEST
	for (int col = 0; col < BOARD_SIZE; col ++) {
		for (int i = 0; i < 5; i ++) {
			// 3x0 ->
			if ((board[i+3][col] == 0) &&
				(board[i][col] != 0) &&
				(board[i][col] == board[i+1][col]) &&
				(board[i+1][col] == board[i+2][col])
			) {
				if (board[i][col] != player) opponentFound = true;
				else return board[i][col] * value;
			}
			// 3x0 <-
			if ((board[BOARD_SIZE-(i+3)-1][col] == 0) &&
				(board[BOARD_SIZE-i-1][col] != 0) &&
				(board[BOARD_SIZE-i-1][col] == board[BOARD_SIZE-(i+1)-1][col]) &&
				(board[BOARD_SIZE-(i+1)-1][col] == board[BOARD_SIZE-(i+2)-1][col])
			) {
				if (board[BOARD_SIZE-i-1][col] != player) opponentFound = true;
				else return board[BOARD_SIZE-i-1][col] * value;
			}
			// 2x1 ->
			if ((board[i+2][col] == 0) &&
				(board[i][col] != 0) &&
				(board[i][col] == board[i+1][col]) &&
				(board[i+1][col] == board[i+3][col])
			) {
				if (board[i][col] != player) opponentFound = true;
				else return board[i][col] * value;
			}
			// 2x1 <-
			if ((board[BOARD_SIZE-(i+2)-1][col] == 0) &&
				(board[BOARD_SIZE-i-1][col] != 0) &&
				(board[BOARD_SIZE-i-1][col] == board[BOARD_SIZE-(i+1)-1][col]) &&
				(board[BOARD_SIZE-(i+1)-1][col] == board[BOARD_SIZE-(i+3)-1][col])
			) {
				if (board[BOARD_SIZE-i-1][col] != player) opponentFound = true;
				else return board[BOARD_SIZE-i-1][col] * value;
			}
		}
	}

	if (opponentFound) return (player * -1) * value;

	return 0;
}
