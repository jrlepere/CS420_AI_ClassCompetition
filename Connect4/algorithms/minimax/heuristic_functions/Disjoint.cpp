/*
 * Disjoint.cpp
 *
 *  Created on: Feb 27, 2018
 *      Author: JLepere2
 */

#include "Disjoint.h"

int Disjoint::execute(vector<vector<int> >& board, int depth) {
	int pRes = parentHeuristic.execute(board, depth);
	if (pRes != 0) return pRes;

	int player;
	if (depth % 2 == 0) player = MAX;
	else player = MIN;

	bool opponentFound = false;

	// ROW TEST
	for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int i = 0; i < 5; i ++) {
			// X X _ X
			if ((board[row][i+2] == 0) &&
				(board[row][i] != 0) &&
				(board[row][i] == board[row][i+1]) &&
				(board[row][i+1] == board[row][i+3])
			) {
				if (board[row][i] != player) opponentFound = true;
				else return board[row][i] * value;
			}
			// X _ X X
			if ((board[row][i+1] == 0) &&
				(board[row][i] != 0) &&
				(board[row][i] == board[row][i+2]) &&
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
			// X X _ X
			if ((board[i+2][col] == 0) &&
				(board[i][col] != 0) &&
				(board[i][col] == board[i+1][col]) &&
				(board[i+1][col] == board[i+3][col])
			) {
				if (board[i][col] != player) opponentFound = true;
				else return board[i][col] * value;
			}
			// X _ X X
			if ((board[i+1][col] == 0) &&
				(board[i][col] != 0) &&
				(board[i][col] == board[i+2][col]) &&
				(board[i+2][col] == board[i+3][col])
			) {
				if (board[i][col] != player) opponentFound = true;
				else return board[i][col] * value;
			}
		}
	}

	if (opponentFound) return (player * -1) * value;

	return 0;
}



