/*
 * MiniMax.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: JLepere2
 */

#include "MiniMax.h"

bool MiniMax::cutoffTest(vector<vector<int> > board, int depth, int maxDepth) {

	// -- DEPTH TEST AND TIME TEST -- //
	if ((depth == maxDepth) || (difftime(time(0), startTime) > maxTime)) return true;

	// -- ROW TEST -- //
	for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int i = 0; i < 5; i ++) {
			// GOAL
			if ((board[row][i] != 0) &&
				(board[row][i] == board[row][i+1]) &&
				(board[row][i+1] == board[row][i+2]) &&
				(board[row][i+2] == board[row][i+3])
			) return true;
		}
	}

	// -- COL TEST -- //
	for (int col = 0; col < BOARD_SIZE; col ++) {
		for (int i = 0; i < 5; i ++) {
			// GOAL
			if ((board[i][col] != 0) &&
				(board[i][col] == board[i+1][col]) &&
				(board[i+1][col] == board[i+2][col]) &&
				(board[i+2][col] == board[i+3][col])
			) return true;
		}
	}

	// -- TERMINAL BOARD -- //
	/*for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int col = 0; col < BOARD_SIZE; col ++) {
			if (board[row][col] == 0) return false;
		}
	}*/

	// TERMINAL BOARD TEST
	// ROW 0
	if (board[0][0] == 0) return false;
	if (board[0][1] == 0) return false;
	if (board[0][2] == 0) return false;
	if (board[0][3] == 0) return false;
	if (board[0][4] == 0) return false;
	if (board[0][5] == 0) return false;
	if (board[0][6] == 0) return false;
	if (board[0][7] == 0) return false;
	// ROW 1
	if (board[1][0] == 0) return false;
	if (board[1][1] == 0) return false;
	if (board[1][2] == 0) return false;
	if (board[1][3] == 0) return false;
	if (board[1][4] == 0) return false;
	if (board[1][5] == 0) return false;
	if (board[1][6] == 0) return false;
	if (board[1][7] == 0) return false;
	// ROW 2
	if (board[2][0] == 0) return false;
	if (board[2][1] == 0) return false;
	if (board[2][2] == 0) return false;
	if (board[2][3] == 0) return false;
	if (board[2][4] == 0) return false;
	if (board[2][5] == 0) return false;
	if (board[2][6] == 0) return false;
	if (board[2][7] == 0) return false;
	// ROW 3
	if (board[3][0] == 0) return false;
	if (board[3][1] == 0) return false;
	if (board[3][2] == 0) return false;
	if (board[3][3] == 0) return false;
	if (board[3][4] == 0) return false;
	if (board[3][5] == 0) return false;
	if (board[3][6] == 0) return false;
	if (board[3][7] == 0) return false;
	// ROW 4
	if (board[4][0] == 0) return false;
	if (board[4][1] == 0) return false;
	if (board[4][2] == 0) return false;
	if (board[4][3] == 0) return false;
	if (board[4][4] == 0) return false;
	if (board[4][5] == 0) return false;
	if (board[4][6] == 0) return false;
	if (board[4][7] == 0) return false;
	// ROW 5
	if (board[5][0] == 0) return false;
	if (board[5][1] == 0) return false;
	if (board[5][2] == 0) return false;
	if (board[5][3] == 0) return false;
	if (board[5][4] == 0) return false;
	if (board[5][5] == 0) return false;
	if (board[5][6] == 0) return false;
	if (board[5][7] == 0) return false;
	// ROW 6
	if (board[6][0] == 0) return false;
	if (board[6][1] == 0) return false;
	if (board[6][2] == 0) return false;
	if (board[6][3] == 0) return false;
	if (board[6][4] == 0) return false;
	if (board[6][5] == 0) return false;
	if (board[6][6] == 0) return false;
	if (board[6][7] == 0) return false;
	// ROW 7
	if (board[7][0] == 0) return false;
	if (board[7][1] == 0) return false;
	if (board[7][2] == 0) return false;
	if (board[7][3] == 0) return false;
	if (board[7][4] == 0) return false;
	if (board[7][5] == 0) return false;
	if (board[7][6] == 0) return false;
	if (board[7][7] == 0) return false;

	return true;
}
