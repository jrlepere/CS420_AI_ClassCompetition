/*
 * MiniMax_DFS.h
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#ifndef MINIMAX_DFS_H_
#define MINIMAX_DFS_H_

#include "MiniMax.h"

class MiniMax_DFS: public MiniMax
{
public:
	MiniMax_DFS(int maxTime, SuccessorFunction& successorFunction, HeuristicFunction& heuristicFunction):
		MiniMax(maxTime, successorFunction, heuristicFunction) {}
	~MiniMax_DFS(){}
	vector<int> getMove(vector<vector<int> >& board, int previousRow, int previousCol, int currentNumTiles);
private:
	vector<int> hMiniMax(vector<vector<int> >& board, int depth, int alpha, int beta, int previousRow, int previousCol);
};

#endif /* MINIMAX_DFS_H_ */
