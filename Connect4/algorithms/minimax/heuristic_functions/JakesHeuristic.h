/*
 * JakesHeuristic.h
 *
 *  Created on: Feb 22, 2018
 *      Author: JLepere2
 */

#ifndef JAKESHEURISTIC_H_
#define JAKESHEURISTIC_H_

#include "HeuristicFunction.h"

class JakesHeuristic: public HeuristicFunction
{
public:
	JakesHeuristic(int value):
		HeuristicFunction(value) {}
	~JakesHeuristic(){}
	int execute(vector<vector<int> >& board, int depth);
private:
	int winnerOrLoser(vector<vector<int> >& board, int depth, int value);
	int killerMove(vector<vector<int> >& board, int depth, int value);
	int oneFromWinner(vector<vector<int> >& board, int depth, int value);
	int oneFromKiller(vector<vector<int> >& board, int depth, int value);
	int final(vector<vector<int> >& board, int depth, int value);
};



#endif /* JAKESHEURISTIC_H_ */
