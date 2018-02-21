/*
 * MiniMax_IDS.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#include "MiniMax_IDS.h"
#include "MiniMax_MaxDepth.h"

vector<int> MiniMax_IDS::getMove(vector<vector<int> >& board, int previousRow, int previousCol)
{
	startTime = time(0);
	vector<int> bestPlay;
	int depth = 0;
	while (true) {
		depth ++;
		MiniMax_MaxDepth miniMax(maxTime-difftime(time(0),startTime), depth, successorFunction, heuristicFunction);
		vector<int> play = miniMax.getMove(board, previousRow, previousCol);
		if (difftime(time(0), startTime) > maxTime) return bestPlay;
		else bestPlay = play;
	}
}

vector<int> MiniMax_IDS::minValue(vector<vector<int> >& board, int previousRow, int previousCol, int alpha, int beta, int depth)
{
	return {0};
}

vector<int> MiniMax_IDS::maxValue(vector<vector<int> >& board, int previousRow, int previousCol, int alpha, int beta, int depth)
{
	return {0};
}
