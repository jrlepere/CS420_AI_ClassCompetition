/*
 * CanWin.cpp
 *
 *  Created on: Feb 28, 2018
 *      Author: JLepere2
 */

#include "CanWin.h"

int CanWin::execute(vector<vector<int> >& board, int depth) {
	int pRes = parentHeuristic.execute(board, depth);
	if (pRes != 0) return pRes;

	int count = 0;

	for (int r = 0; r < BOARD_SIZE; r ++) {
		for (int c = 0; c < BOARD_SIZE; c ++) {
			if (board[r][c] != 0) {
				int player = board[r][c];
				int opponent = player * -1;
				if (r > 2 && (board[r-3][c] != opponent) && (board[r-2][c] != opponent) && (board[r-1][c] != opponent)) count += player;
				if (r > 1 && r < BOARD_SIZE - 1 && (board[r-2][c] != opponent) && (board[r-1][c] != opponent) && (board[r+1][c] != opponent)) count += player;
				if (r > 0 && r < BOARD_SIZE - 2 && (board[r-1][c] != opponent) && (board[r+1][c] != opponent) && (board[r+2][c] != opponent)) count += player;
				if (r < BOARD_SIZE - 3 && (board[r+1][c] != opponent) && (board[r+2][c] != opponent) && (board[r+3][c] != opponent)) count += player;
				if (c > 2 && (board[r][c-3] != opponent) && (board[r][c-2] != opponent) && (board[r][c-1] != opponent)) count += player;
				if (c > 1 && c < BOARD_SIZE - 1 && (board[r][c-2] != opponent) && (board[r][c-1] != opponent) && (board[r][c+1] != opponent)) count += player;
				if (c > 0 && c < BOARD_SIZE - 2 && (board[r][c-1] != opponent) && (board[r][c+1] != opponent) && (board[r][c+2] != opponent)) count += player;
				if (c < BOARD_SIZE - 3 && (board[r][c+1] != opponent) && (board[r][c+2] != opponent) && (board[r][c+3] != opponent)) count += player;
			}
		}
	}

	return count*value/320;
}
