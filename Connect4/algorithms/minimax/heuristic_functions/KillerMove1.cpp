/*
 * KillerMove1.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: JLepere2
 */

#include "KillerMove1.h"

int KillerMove1::execute(vector<vector<int> >& board) {
	int pRes = parentHeuristic.execute(board);
	if (pRes != 0) return pRes;

	// ROW TEST
	for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int i = 0; i < 4; i ++) {
			if ((board[row][i] == 0) &&
				(board[row][i+4] == 0) &&
				(board[row][i+1] != 0) &&
				(board[row][i+1] == board[row][i+2]) &&
				(board[row][i+2] == board[row][i+3])
				) return board[row][i] * 100;
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
				) return board[i][col] * 100;
		}
	}

	return 0;
}
