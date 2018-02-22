/*
 * DoublesAndTriples.h
 *
 *  Created on: Feb 21, 2018
 *      Author: JLepere2
 */

#ifndef DOUBLESANDTRIPLES_H_
#define DOUBLESANDTRIPLES_H_

#include "HeuristicFunctionDecorator.h"

class DoublesAndTriples: public HeuristicFunctionDecorator
{
public:
	DoublesAndTriples(HeuristicFunction& parentHeuristic):
		HeuristicFunctionDecorator(parentHeuristic){}
	~DoublesAndTriples(){}
	int execute(vector<vector<int> >& board);
};

#endif /* DOUBLESANDTRIPLES_H_ */
