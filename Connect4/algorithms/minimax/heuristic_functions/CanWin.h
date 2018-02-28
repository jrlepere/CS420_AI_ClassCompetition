/*
 * CanWin.h
 *
 *  Created on: Feb 28, 2018
 *      Author: JLepere2
 */

#ifndef CANWIN_H_
#define CANWIN_H_

#include "HeuristicFunctionDecorator.h"

class CanWin: public HeuristicFunctionDecorator
{
public:
	CanWin(HeuristicFunction& parentHeuristic, int value):
		HeuristicFunctionDecorator(parentHeuristic, value){}
	~CanWin(){}
	int execute(vector<vector<int> >& board, int depth);
};

#endif /* CANWIN_H_ */
