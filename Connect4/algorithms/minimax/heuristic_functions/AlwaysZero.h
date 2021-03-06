/*
 * AlwaysZero.h
 *
 *  Created on: Feb 21, 2018
 *      Author: JLepere2
 */

#ifndef ALWAYSZERO_H_
#define ALWAYSZERO_H_

#include "HeuristicFunction.h"

class AlwaysZero: public HeuristicFunction
{
public:
	AlwaysZero(int value):
		HeuristicFunction(value) {}
	~AlwaysZero(){}
	int execute(vector<vector<int> >& board, int depth);
};

#endif /* ALWAYSZERO_H_ */
