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

	return false;
}
