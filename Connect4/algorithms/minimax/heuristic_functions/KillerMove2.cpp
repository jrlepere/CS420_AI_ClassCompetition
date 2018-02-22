/*
 * KillerMove2.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: JLepere2
 */


#include "KillerMove2.h"

int KillerMove2::execute(vector<vector<int> >& board, int depth) {
	int pRes = parentHeuristic.execute(board, depth);
	if (pRes != 0) return pRes;

	int value = 99;

	int player;
	if (depth % 2 == 0) player = MAX;
	else player = MIN;

	bool opponentFound = false;

	for (int row = 0; row < 5; row ++) {
		for (int col = 0; col < 5; col ++) {
			/*
			 * ? ? ? ?
			 * ? X ? ?
			 * ? ? X ?
			 * ? ? ? ?
			 */
			if ((board[row+1][col+1] != 0) &&
				(board[row+2][col+2] != 0) &&
				(board[row+1][col+1] == board[row+2][col+2])
			) {
				/*
				 * ? ? ? ?
				 * ? X ? ?
				 * ? X X ?
				 * ? ? ? ?
				 */
				if (board[row+2][col+1] == board[row+1][col+1]) {
					/*
					 * ? _ ? ?
					 * ? X ? ?
					 * _ X X _
					 * ? _ ? ?
					 */
					if ((board[row][col+1] == 0) &&
						(board[row+3][col+1] == 0) &&
						(board[row+2][col] == 0) &&
						(board[row+2][col+3] == 0)
					) return board[row+2][col+1] * value;
				} else if (board[row+1][col+2] == board[row+1][col+1]) {
					if ((board[row][col+2] == 0) &&
						(board[row+3][col+2] == 0) &&
						(board[row+1][col] == 0) &&
						(board[row+1][col+3] == 0)
					) return board[row+2][col+1] * value;
				}
			}
		}
	}

	if (opponentFound) return (player * -1) * value;

	return 0;
}
