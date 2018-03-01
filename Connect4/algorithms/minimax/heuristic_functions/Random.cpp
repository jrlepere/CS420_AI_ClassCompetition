/*
 * Random.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: JLepere2
 */

#include "Random.h"

int Random::execute(vector<vector<int> >& board, int depth) {
	int pRes = parentHeuristic.execute(board, depth);
	if (pRes != 0) return pRes;

	return rand() % (range) - value;
}
