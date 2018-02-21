/*
 * Spiral.h
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#ifndef SPIRAL_H_
#define SPIRAL_H_

#include "SuccessorFunction.h"

class Spiral: public SuccessorFunction
{
public:
	Spiral(){}
	~Spiral(){}
	vector<vector<int> > execute(vector<vector<int> >& board, int previousRow, int previousCol);
};

#endif /* SPIRAL_H_ */
