/*
 * Disjoint.h
 *
 *  Created on: Feb 27, 2018
 *      Author: JLepere2
 */

#ifndef DISJOINT_H_
#define DISJOINT_H_

#include "HeuristicFunctionDecorator.h"

class Disjoint: public HeuristicFunctionDecorator
{
public:
	Disjoint(HeuristicFunction& parentHeuristic, int value):
		HeuristicFunctionDecorator(parentHeuristic, value){}
	~Disjoint(){}
	int execute(vector<vector<int> >& board, int depth);
};

#endif /* DISJOINT_H_ */
