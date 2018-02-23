/*
 * OneAway.h
 *
 *  Created on: Feb 21, 2018
 *      Author: JLepere2
 */

#ifndef ONEAWAY_H_
#define ONEAWAY_H_

#include "HeuristicFunctionDecorator.h"

class OneAway: public HeuristicFunctionDecorator
{
public:
	OneAway(HeuristicFunction& parentHeuristic, int value):
		HeuristicFunctionDecorator(parentHeuristic, value){}
	~OneAway(){}
	int execute(vector<vector<int> >& board, int depth);
};

#endif /* ONEAWAY_H_ */
