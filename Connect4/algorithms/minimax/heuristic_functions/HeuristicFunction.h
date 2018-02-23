/*
 * HeuristicFunction.h
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#ifndef HEURISTICFUNCTION_H_
#define HEURISTICFUNCTION_H_

#include <vector>
#include "../../../src/Utilities.h"

using namespace std;

class HeuristicFunction
{
public:
	HeuristicFunction(int value): value(value){}
	virtual ~HeuristicFunction(){}
	virtual int execute(vector<vector<int> >& board, int depth)=0;
protected:
	int value;
};

#endif /* HEURISTICFUNCTION_H_ */
