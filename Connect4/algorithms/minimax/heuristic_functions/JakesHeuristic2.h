/*
 * JakesHeuristic2.h
 *
 *  Created on: Feb 27, 2018
 *      Author: JLepere2
 */

#ifndef JAKESHEURISTIC2_H_
#define JAKESHEURISTIC2_H_

#include "HeuristicFunction.h"

class JakesHeuristic2: public HeuristicFunction
{
public:
	JakesHeuristic2(int value):
		HeuristicFunction(value) {}
	~JakesHeuristic2(){}
	int execute(vector<vector<int> >& board, int depth);
private:
};

#endif /* JAKESHEURISTIC2_H_ */
