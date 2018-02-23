/*
 * TwoAway.h
 *
 *  Created on: Feb 21, 2018
 *      Author: JLepere2
 */

#ifndef TWOAWAY_H_
#define TWOAWAY_H_


#include "HeuristicFunctionDecorator.h"

class TwoAway: public HeuristicFunctionDecorator
{
public:
	TwoAway(HeuristicFunction& parentHeuristic, int value):
		HeuristicFunctionDecorator(parentHeuristic, value) {}
	~TwoAway(){}
	int execute(vector<vector<int> >& board, int depth);
};

#endif /* TWOAWAY_H_ */
