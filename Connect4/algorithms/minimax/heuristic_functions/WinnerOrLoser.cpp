/*
 * WinnerOrLoser.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#include "WinnerOrLoser.h"

int WinnerOrLoser::execute(vector<vector<int> >& board, int depth) {

	// ROW TEST
	for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int i = 0; i < 5; i ++) {
			if ((board[row][i] != 0) &&
				(board[row][i] == board[row][i+1]) &&
				(board[row][i+1] == board[row][i+2]) &&
				(board[row][i+2] == board[row][i+3])
			) {
				return board[row][i] * value;
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
				return board[i][col] * value;
			}
		}
	}

	return 0;
}
