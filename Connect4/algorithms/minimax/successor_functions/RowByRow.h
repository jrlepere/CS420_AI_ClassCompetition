/*
 * RowByRow.h
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#ifndef ROWBYROW_H_
#define ROWBYROW_H_

#include "SuccessorFunction.h"

class RowByRow: public SuccessorFunction
{
public:
	RowByRow(){}
	~RowByRow(){}
	vector<vector<int> > execute(vector<vector<int> >& board, int previousRow, int previousCol);
};


#endif /* ROWBYROW_H_ */
