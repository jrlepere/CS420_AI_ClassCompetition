/*
 * ToddHeuristic.h
 *
 *  Created on: Feb 26, 2018
 *      Author: toddnguyen47
 */

#ifndef TODDHEURISTIC_H_
#define TODDHEURISTIC_H_

#include "HeuristicFunction.h"
#include <iostream>

class ToddHeuristic: public HeuristicFunction
{
public:
	ToddHeuristic(int value):
		HeuristicFunction(value) {}
	~ToddHeuristic(){}
	int execute(vector<vector<int> >& board, int depth);
private:
	int winnerOrLoser(vector<vector<int> >& board, int depth, int value);
	int killerMove(vector<vector<int> >& board, int depth, int value);
	int oneFromWinner(vector<vector<int> >& board, int depth, int value);
	int oneFromKiller(vector<vector<int> >& board, int depth, int value);
	int final(vector<vector<int> >& board, int depth, int value);
	int preventOpponentKillerMove(vector <vector<int> > & board, int depth, int value);
};



#endif /* TODDHEURISTIC_H_ */
