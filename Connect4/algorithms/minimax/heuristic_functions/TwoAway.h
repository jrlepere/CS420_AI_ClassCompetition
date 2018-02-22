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
	TwoAway(HeuristicFunction& parentHeuristic):
		HeuristicFunctionDecorator(parentHeuristic){}
	~TwoAway(){}
	int execute(vector<vector<int> >& board, int depth);
};

#endif /* TWOAWAY_H_ */
