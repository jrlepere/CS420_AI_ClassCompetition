/*
 * Bloom.h
 *
 *  Created on: Mar 1, 2018
 *      Author: JLepere2
 */

#ifndef BLOOM_H_
#define BLOOM_H_

#include "SuccessorFunction.h"

class Bloom: public SuccessorFunction
{
public:
	Bloom(){}
	~Bloom(){}
	vector<vector<int> > execute(vector<vector<int> >& board, int previousRow, int previousCol);
};

#endif /* BLOOM_H_ */
