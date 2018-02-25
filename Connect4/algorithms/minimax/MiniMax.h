/*
 * MiniMax.h
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#ifndef MINIMAX_H_
#define MINIMAX_H_

#include "../Algorithm.h"
#include "successor_functions/SuccessorFunction.h"
#include "heuristic_functions/HeuristicFunction.h"
#include <time.h>

/**
 * Abstract class definition for MiniMax Algorithm specifically for the Connect 4 game.
 */
class MiniMax: public Algorithm
{
public:
	/**
	 * MiniMax Algorithm constructor.
	 * @param maxTime the maximum time the algorithm can run for.
	 * @param successorFunction the function defining how to generate the successors.
	 */
	MiniMax(int maxTime, SuccessorFunction& successorFunction, HeuristicFunction& heuristicFunction):
		Algorithm(maxTime), successorFunction(successorFunction), heuristicFunction(heuristicFunction) {}
	virtual ~MiniMax(){}
	virtual vector<int> getMove(vector<vector<int> >& board, int previousRow, int previousCol)=0;
private:
	virtual vector<int> hMiniMax(vector<vector<int> >& board, int depth, int alpha, int beta, int previousRow, int previousCol)=0;
protected:
	bool cutoffTest(vector<vector<int> > board, int depth, int maxDepth);
	SuccessorFunction& successorFunction;
	HeuristicFunction& heuristicFunction;
};

#endif /* MINIMAX_H_ */
