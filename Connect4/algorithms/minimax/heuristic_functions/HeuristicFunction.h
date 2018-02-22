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
	HeuristicFunction(){}
	virtual ~HeuristicFunction(){}
	virtual int execute(vector<vector<int> >& board, int depth)=0;
};



#endif /* HEURISTICFUNCTION_H_ */
