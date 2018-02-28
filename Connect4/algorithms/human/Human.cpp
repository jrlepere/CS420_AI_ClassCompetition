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
	cout<<"row: ";
	cin>>row;
	cout<<"col: ";
	cin>>col;
	return {row,col};
}
