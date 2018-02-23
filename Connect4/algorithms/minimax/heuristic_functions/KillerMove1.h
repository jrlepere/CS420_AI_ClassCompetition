/*
 * KillerMove1.h
 *
 *  Created on: Feb 21, 2018
 *      Author: JLepere2
 */

#ifndef KILLERMOVE1_H_
#define KILLERMOVE1_H_

#include "HeuristicFunctionDecorator.h"

class KillerMove1: public HeuristicFunctionDecorator
{
public:
	KillerMove1(HeuristicFunction& parentHeuristic, int value):
		HeuristicFunctionDecorator(parentHeuristic, value){}
	~KillerMove1(){}
	int execute(vector<vector<int> >& board, int depth);
};

#endif /* KILLERMOVE1_H_ */
