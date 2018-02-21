/*
 * MiniMax.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: JLepere2
 */

#include "MiniMax.h"

bool MiniMax::cutoffTest(vector<vector<int> > board, int depth, int maxDepth) {
	return (depth == maxDepth) || (difftime(time(0), startTime) > maxTime);
}
