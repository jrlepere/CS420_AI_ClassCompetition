/*
 * MiniMax_MaxDepth.h
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#ifndef MINIMAX_MAXDEPTH_H_
#define MINIMAX_MAXDEPTH_H_

#include "MiniMax.h"

class MiniMax_MaxDepth: public MiniMax
{
public:
	MiniMax_MaxDepth(int maxTime, int maxDepth, SuccessorFunction& successorFunction, HeuristicFunction& heuristicFunction):
		MiniMax(maxTime, successorFunction, heuristicFunction), maxDepth(maxDepth), count(0) {}
	~MiniMax_MaxDepth(){}
	vector<int> getMove(vector<vector<int> >& board, int previousRow, int previousCol, int currentNumTiles);
private:
	vector<int> hMiniMax(vector<vector<int> >& board, int depth, int alpha, int beta, int previousRow, int previousCol);
	int maxDepth;
	int count;
	vector<vector<int> > initialBoard;
};

#endif /* MINIMAX_MAXDEPTH_H_ */
