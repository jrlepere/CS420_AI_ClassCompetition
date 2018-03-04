/*
 * Random.h
 *
 *  Created on: Mar 1, 2018
 *      Author: JLepere2
 */

#ifndef RANDOM_H_
#define RANDOM_H_

#include "HeuristicFunctionDecorator.h"
#include <ctime>

class Random: public HeuristicFunctionDecorator
{
public:
	Random(HeuristicFunction& parentHeuristic, int value):
		HeuristicFunctionDecorator(parentHeuristic, value), range(2 * value + 1) {
		srand(time(0));
	}
	~Random(){}
	int execute(vector<vector<int> >& board, int depth);
private:
	int range;
};

#endif /* RANDOM_H_ */
