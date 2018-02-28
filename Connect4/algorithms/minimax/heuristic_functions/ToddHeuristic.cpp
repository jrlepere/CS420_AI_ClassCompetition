/*
 * ToddHeuristic.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: toddnguyen47
 */

#include "ToddHeuristic.h"

int ToddHeuristic::execute(vector<vector<int> >& board, int depth) {
	WinnerOrLoser t1(100);
	OneAway t2(t1, 99);
	KillerMove1 t3(t2, 98);
	return t3.execute(board, depth);

	//return final(board, depth, 96);
}
