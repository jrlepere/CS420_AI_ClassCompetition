/*
 * Spiral.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#include "Spiral.h"

vector<vector<int> > Spiral::execute(vector<vector<int> >& board, int previousRow, int previousCol)
{
	vector<vector<int> > successors;

	int r;
	int c;
	int h;
	int x = max(max(previousRow, BOARD_SIZE - previousRow - 1), max(previousCol, BOARD_SIZE - previousCol - 1));
	for (int d = 1; d <= x; d ++) {
		r = previousRow - d;
		c = previousCol + d;
		h = d * 2;
		// DOWN
		if ((c >= 0) && (c < BOARD_SIZE)) {
			for (int i = 0; i < h; i ++) {
				r += 1;
				if ((r >= 0) && (r < BOARD_SIZE)) {
					if (board[r][c] == 0) {
						successors.push_back({r,c});
					}
				}
			}
		} else {
			r = previousRow + d;
		}
		// LEFT
		if ((r >= 0) && (r < BOARD_SIZE)) {
			for (int i = 0; i < h; i ++) {
				c -= 1;
				if ((c >= 0) && (c < BOARD_SIZE)) {
					if (board[r][c] == 0) {
						successors.push_back({r,c});
					}
				}
			}
		} else {
			c = previousCol - d;
		}
		// UP
		if ((c >= 0) && (c < BOARD_SIZE)) {
			for (int i = 0; i < h; i ++) {
				r -= 1;
				if ((r >= 0) && (r < BOARD_SIZE)) {
					if (board[r][c] == 0) {
						successors.push_back({r,c});
					}
				}
			}
		} else {
			r = previousRow - d;
		}
		// RIGHT
		if ((r >= 0) && (r < BOARD_SIZE)) {
			for (int i = 0; i < h; i ++) {
				c += 1;
				if ((c >= 0) && (c < BOARD_SIZE)) {
					if (board[r][c] == 0) {
						successors.push_back({r,c});
					}
				}
			}
		}
	}

	return successors;
}
