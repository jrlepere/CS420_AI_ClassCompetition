/*
 * Human.cpp
 *
 *  Created on: Feb 23, 2018
 *      Author: JLepere2
 */

#include <iostream>
#include "Human.h"

vector<int> Human::getMove(vector<vector<int> >& board, int previousRow, int previousCol, int currentNumTiles) {
	int row;
	int col;
	bool failSomeTest = true;
	do {
		cout<<"row: ";
		cin>>row;
		cout<<"col: ";
		cin>>col;

		if (board[row][col] != 0) {
			std::cout << "ERROR: Input already taken.\n\n";
		}
		else {failSomeTest = false;}
	} while (failSomeTest);

	return {row,col};
}
