/*
 * HeuristicFunction.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: JLepere2
 */

#include "HeuristicFunction.h"

int HeuristicFunction::terminalBoard(vector<vector<int> > board) {
	// ROW TEST
	for (int row = 0; row < BOARD_SIZE; row ++) {
		if (board[row][3] != 0) {
			if ((board[row][0] == board[row][1]) && (board[row][1] == board[row][2]) && (board[row][2] == board[row][3])) return board[row][3] * 100;
			if ((board[row][2] == board[row][3]) && (board[row][3] == board[row][4]) && (board[row][4] == board[row][5])) return board[row][3] * 100;
			if ((board[row][6] == board[row][5]) && (board[row][5] == board[row][4]) && (board[row][4] == board[row][3])) return board[row][3] * 100;
		}
		if (board[row][4] != 0) {
			if ((board[row][1] == board[row][2]) && (board[row][2] == board[row][3]) && (board[row][3] == board[row][4])) return board[row][4] * 100;
			if ((board[row][7] == board[row][6]) && (board[row][6] == board[row][5]) && (board[row][5] == board[row][4])) return board[row][4] * 100;
		}
	}

	// COL TEST
	for (int col = 0; col < BOARD_SIZE; col ++) {
		if (board[3][col] != 0) {
			if ((board[0][col] == board[1][col]) && (board[1][col] == board[2][col]) && (board[2][col] == board[3][col])) return board[3][col] * 100;
			if ((board[2][col] == board[3][col]) && (board[3][col] == board[4][col]) && (board[4][col] == board[5][col])) return board[3][col] * 100;
			if ((board[6][col] == board[5][col]) && (board[5][col] == board[4][col]) && (board[4][col] == board[3][col])) return board[3][col] * 100;
		}
		if (board[4][col] != 0) {
			if ((board[1][col] == board[2][col]) && (board[2][col] == board[3][col]) && (board[3][col] == board[4][col])) return board[4][col] * 100;
			if ((board[7][col] == board[6][col]) && (board[6][col] == board[5][col]) && (board[5][col] == board[4][col])) return board[4][col] * 100;
		}
	}

	return 0;
}

