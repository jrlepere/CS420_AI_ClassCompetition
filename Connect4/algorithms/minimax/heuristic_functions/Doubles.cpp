/*
 * Doubles.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: JLepere2
 */

#include "Doubles.h"

int Doubles::execute(vector<vector<int> >& board) {
	int pRes = parentHeuristic.execute(board);
	if (pRes != 0) return pRes;

	int count = 0;
	for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int i = 0; i < BOARD_SIZE; i ++) {
			for (int j = i + 1; j < BOARD_SIZE; j ++) {
				if (board[row][i] == board[row][j]) count += board[row][i];
			}
		}
	}

	for (int col = 0; col < BOARD_SIZE; col ++) {
		for (int i = 0; i < BOARD_SIZE; i ++) {
			for (int j = i + 1; j < BOARD_SIZE; j ++) {
				if (board[i][col] == board[j][col]) count += board[i][col];
			}
		}
	}

	return (count/448)*100;
}
