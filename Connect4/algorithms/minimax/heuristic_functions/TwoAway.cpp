/*
 * TwoAway.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: JLepere2
 */

#include "TwoAway.h"

int TwoAway::execute(vector<vector<int> >& board, int depth) {
	int pRes = parentHeuristic.execute(board, depth);
	if (pRes != 0) return pRes;

	// ROW TEST
	for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int i = 0; i < 5; i ++) {
			// 3x0 ->
			if ((board[row][i+3] == 0) &&
				(board[row][i] != 0) &&
				(board[row][i] == board[row][i+1]) &&
				(board[row][i+1] == board[row][i+2])
			) return board[row][i] * 99;
			// 3x0 <-
			if ((board[row][BOARD_SIZE-(i+3)-1] == 0) &&
				(board[row][BOARD_SIZE-i-1] != 0) &&
				(board[row][BOARD_SIZE-i-1] == board[row][BOARD_SIZE-(i+1)-1]) &&
				(board[row][BOARD_SIZE-(i+1)-1] == board[row][BOARD_SIZE-(i+2)-1])
			) return board[row][BOARD_SIZE-i-1] * 99;
			// 2x1 ->
			if ((board[row][i+2] == 0) &&
				(board[row][i] != 0) &&
				(board[row][i] == board[row][i+1]) &&
				(board[row][i+1] == board[row][i+3])
			) return board[row][i] * 99;
			// 2x1 <-
			if ((board[row][BOARD_SIZE-(i+2)-1] == 0) &&
				(board[row][BOARD_SIZE-i-1] != 0) &&
				(board[row][BOARD_SIZE-i-1] == board[row][BOARD_SIZE-(i+1)-1]) &&
				(board[row][BOARD_SIZE-(i+1)-1] == board[row][BOARD_SIZE-(i+3)-1])
			) return board[row][BOARD_SIZE-i-1] * 99;
		}
	}

	// COL TEST
	for (int col = 0; col < BOARD_SIZE; col ++) {
		for (int i = 0; i < 5; i ++) {
			if ((board[i+3][col] == 0) &&
				(board[i][col] != 0) &&
				(board[i][col] == board[i+1][col]) &&
				(board[i+1][col] == board[i+2][col])
			) return board[i][col] * 99;
			if ((board[BOARD_SIZE-(i+3)-1][col] == 0) &&
				(board[BOARD_SIZE-i-1][col] != 0) &&
				(board[BOARD_SIZE-i-1][col] == board[BOARD_SIZE-(i+1)-1][col]) &&
				(board[BOARD_SIZE-(i+1)-1][col] == board[BOARD_SIZE-(i+2)-1][col])
			) return board[BOARD_SIZE-i-1][col] * 99;
			if ((board[i+2][col] == 0) &&
				(board[i][col] != 0) &&
				(board[i][col] == board[i+1][col]) &&
				(board[i+1][col] == board[i+3][col])
			) return board[i][col] * 99;
			if ((board[BOARD_SIZE-(i+2)-1][col] == 0) &&
				(board[BOARD_SIZE-i-1][col] != 0) &&
				(board[BOARD_SIZE-i-1][col] == board[BOARD_SIZE-(i+1)-1][col]) &&
				(board[BOARD_SIZE-(i+1)-1][col] == board[BOARD_SIZE-(i+3)-1][col])
			) return board[BOARD_SIZE-i-1][col] * 99;
		}
	}

	return 0;
}
