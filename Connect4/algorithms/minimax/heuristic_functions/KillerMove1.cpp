/*
 * KillerMove1.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: JLepere2
 */

#include "KillerMove1.h"

int KillerMove1::execute(vector<vector<int> >& board, int depth) {
	int pRes = parentHeuristic.execute(board, depth);
	if (pRes != 0) return pRes;

	int value = 99;

	int player;
	if (depth % 2 == 0) player = MAX;
	else player = MIN;

	bool opponentFound = false;

	// ROW TEST
	for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int i = 0; i < 4; i ++) {
			if ((board[row][i] == 0) &&
				(board[row][i+4] == 0) &&
				(board[row][i+1] != 0) &&
				(board[row][i+1] == board[row][i+2]) &&
				(board[row][i+2] == board[row][i+3])
			) {
				if (board[row][i+1] != player) opponentFound = true;
				else return board[row][i+1] * value;
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
				if (board[i+1][col] != player) opponentFound = true;
				return board[i+1][col] * value;
			}
		}
	}

	if (opponentFound) return (player * -1) * value;

	return 0;
}
