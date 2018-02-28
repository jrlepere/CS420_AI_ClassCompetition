/*
 * MiniMax_IDS.h
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#ifndef MINIMAX_IDS_H_
#define MINIMAX_IDS_H_

#include "MiniMax.h"

class MiniMax_IDS: public MiniMax
{
public:
	MiniMax_IDS(int maxTime, SuccessorFunction& successorFunction, HeuristicFunction& heuristicFunction):
		MiniMax(maxTime, successorFunction, heuristicFunction) {}
	~MiniMax_IDS(){}
	vector<int> getMove(vector<vector<int> >& board, int previousRow, int previousCol, int currentNumTiles);
private:
	vector<int> hMiniMax(vector<vector<int> >& board, int depth, int alpha, int beta, int previousRow, int previousCol);
};

#endif /* MINIMAX_IDS_H_ */
