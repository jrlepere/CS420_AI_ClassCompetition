/*
 * HeuristicFunctionDecorator.h
 *
 *  Created on: Feb 21, 2018
 *      Author: JLepere2
 */

#ifndef HEURISTICFUNCTIONDECORATOR_H_
#define HEURISTICFUNCTIONDECORATOR_H_

#include "HeuristicFunction.h"

class HeuristicFunctionDecorator: public HeuristicFunction
{
public:
	HeuristicFunctionDecorator(HeuristicFunction& parentHeuristic):
		parentHeuristic(parentHeuristic){}
	~HeuristicFunctionDecorator(){}
	virtual int execute(vector<vector<int> >& board, int depth) =0;
protected:
	HeuristicFunction& parentHeuristic;
};



#endif /* HEURISTICFUNCTIONDECORATOR_H_ */
