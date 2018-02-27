/*
 * JakesHeuristic2.cpp
 *
 *  Created on: Feb 27, 2018
 *      Author: JLepere2
 */

#include "JakesHeuristic2.h"
#include "WinnerOrLoser.h"
#include "OneAway.h"
#include "KillerMove1.h"

int JakesHeuristic2::execute(vector<vector<int> >& board, int depth) {

	WinnerOrLoser t1(100);
	KillerMove1 t2(t1, 99);
	OneAway t3(t2, 98);
	return t1.execute(board, depth);

}
