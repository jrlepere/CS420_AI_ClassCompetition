/*
 * DoublesAndTriples.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: JLepere2
 */

#include "DoublesAndTriples.h"

int DoublesAndTriples::execute(vector<vector<int> >& board, int depth) {
	int pRes = parentHeuristic.execute(board, depth);
	if (pRes != 0) return pRes;

	int doubleCount = 0;
	int tripleCount = 0;

	for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int i = 0; i < BOARD_SIZE; i ++) {
			for (int j = i + 1; j < BOARD_SIZE; j ++) {
				if (board[row][i] == board[row][j]) doubleCount += board[row][i];
				else continue;
				for (int k = j + 1; k < BOARD_SIZE; k ++) {
					if (board[row][j] == board[row][k]) tripleCount += board[row][i];
				}
			}
		}
	}

	for (int col = 0; col < BOARD_SIZE; col ++) {
		for (int i = 0; i < BOARD_SIZE; i ++) {
			for (int j = i + 1; j < BOARD_SIZE; j ++) {
				if (board[i][col] == board[j][col]) doubleCount += board[i][col];
				else continue;
				for (int k = j + 1; k < BOARD_SIZE; k ++) {
					if (board[j][col] == board[k][col]) tripleCount += board[i][col];
				}
			}
		}
	}

	float doublePercentage = 0.25;
	float triplePercentage = 0.75;

	return doublePercentage*(doubleCount/448)*100 + triplePercentage*(tripleCount/80)*100;
}
