/*
 * Utilities.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#include <vector>
#include <iostream>
#include "Utilities.h"

using namespace std;

/*
	for (int row = 0; row < BOARD_SIZE; row ++) {
		if ((board[row][0] == 0) && (board[row][4] == 0) && (board[row][1] != 0) && (board[row][1] == board[row][2]) && (board[row][2] == board[row][3])) return board[row][3] * 100;
		if ((board[row][1] == 0) && (board[row][5] == 0) && (board[row][2] != 0) && (board[row][2] == board[row][3]) && (board[row][3] == board[row][4])) return board[row][4] * 100;
		if ((board[row][2] == 0) && (board[row][6] == 0) && (board[row][3] != 0) && (board[row][3] == board[row][4]) && (board[row][4] == board[row][5])) return board[row][5] * 100;
		if ((board[row][3] == 0) && (board[row][7] == 0) && (board[row][4] != 0) && (board[row][4] == board[row][5]) && (board[row][5] == board[row][6])) return board[row][6] * 100;
	}

	return 0;
*/

void UtilityFunctions::printBoard(vector<vector<int> > board) {
	for (int row = 0; row < 8; row ++) {
		for (int col = 0; col < 8; col ++) {
			int v = board[row][col];
			if (v == 1) cout<<"X"<<" ";
			else if (v == -1) cout<<"0"<<" ";
			else cout<<"_"<<" ";

		}
		cout<<"\n";
	}
	cout<<"\n";
}
