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
	vector<int> getMove(vector<vector<int> >& board, int previousRow, int previousCol);
private:
	vector<int> minValue(vector<vector<int> >& board, int previousRow, int previousCol, int alpha, int beta, int depth);
	vector<int> maxValue(vector<vector<int> >& board, int previousRow, int previousCol, int alpha, int beta, int depth);
};

#endif /* MINIMAX_IDS_H_ */
