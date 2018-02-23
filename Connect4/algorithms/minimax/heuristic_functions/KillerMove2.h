/*
 * KillerMove2.h
 *
 *  Created on: Feb 22, 2018
 *      Author: JLepere2
 */

#ifndef KILLERMOVE2_H_
#define KILLERMOVE2_H_

#include "HeuristicFunctionDecorator.h"

class KillerMove2: public HeuristicFunctionDecorator
{
public:
	KillerMove2(HeuristicFunction& parentHeuristic, int value):
		HeuristicFunctionDecorator(parentHeuristic, value){}
	~KillerMove2(){}
	int execute(vector<vector<int> >& board, int depth);
};

#endif /* KILLERMOVE2_H_ */
