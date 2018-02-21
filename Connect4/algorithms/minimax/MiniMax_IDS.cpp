/*
 * MiniMax_IDS.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#include "MiniMax_IDS.h"
#include "MiniMax_MaxDepth.h"

vector<int> MiniMax_IDS::getMove(vector<vector<int> >& board, int previousRow, int previousCol) {
	startTime = time(0);
	int maxDepth = 1;
	vector<int> bestMove;
	while (true) {
		MiniMax_MaxDepth m(maxTime - difftime(time(0), startTime), maxDepth, successorFunction, heuristicFunction);
		vector<int> res = m.getMove(board, previousRow, previousCol);
		if (difftime(time(0), startTime) > maxTime) return bestMove;
		bestMove = res;
		maxDepth ++;
	}
}

vector<int> MiniMax_IDS::hMiniMax(vector<vector<int> >& board, int depth, int previousRow, int previousCol) {
	return {0};
}
