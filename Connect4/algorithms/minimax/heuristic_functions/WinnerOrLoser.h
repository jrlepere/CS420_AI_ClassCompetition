/*
 * WinnerOrLoser.h
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#ifndef WINNERORLOSER_H_
#define WINNERORLOSER_H_

#include "HeuristicFunction.h"

class WinnerOrLoser: public HeuristicFunction
{
public:
	WinnerOrLoser(){}
	~WinnerOrLoser(){}
	int execute(vector<vector<int> >& board, int depth);
};

#endif /* WINNERORLOSER_H_ */
