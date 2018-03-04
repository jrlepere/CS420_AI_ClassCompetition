/*
 * MiniMax_EIDS.h
 *
 *  Created on: Mar 3, 2018
 *      Author: JLepere2
 */

#ifndef MINIMAX_EIDS_H_
#define MINIMAX_EIDS_H_

#include "MiniMax.h"

class MiniMax_EIDS: public MiniMax
{
public:
	MiniMax_EIDS(int maxTime, SuccessorFunction& successorFunction, HeuristicFunction& heuristicFunction):
		MiniMax(maxTime, successorFunction, heuristicFunction), maxDepth(0), count(0) {}
	~MiniMax_EIDS(){}
	vector<int> getMove(vector<vector<int> >& board, int previousRow, int previousCol, int currentNumTiles);
private:
	vector<int> hMiniMax(vector<vector<int> >& board, int depth, int alpha, int beta, int previousRow, int previousCol);
	int maxDepth;
	int count;
	vector<vector<int> > initialBoard;
};

#endif /* MINIMAX_EIDS_H_ */
