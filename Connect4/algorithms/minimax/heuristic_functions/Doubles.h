/*
 * Doubles.h
 *
 *  Created on: Feb 21, 2018
 *      Author: JLepere2
 */

#ifndef DOUBLES_H_
#define DOUBLES_H_

#include "HeuristicFunctionDecorator.h"

class Doubles: public HeuristicFunctionDecorator
{
public:
	Doubles(HeuristicFunction& parentHeuristic):
		HeuristicFunctionDecorator(parentHeuristic){}
	~Doubles(){}
	int execute(vector<vector<int> >& board);
};

#endif /* DOUBLES_H_ */
