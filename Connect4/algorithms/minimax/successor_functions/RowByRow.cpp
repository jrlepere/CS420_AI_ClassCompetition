/*
 * RowByRow.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#include "RowByRow.h"

vector<vector<int> > RowByRow::execute(vector<vector<int> >& board, int previousRow, int previousCol)
{
	vector<vector<int> > successors;
	for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int col = 0; col < BOARD_SIZE; col ++) {
			if (board[row][col] == 0) {
				successors.push_back({row,col});
			}
		}
	}
	return successors;
}


