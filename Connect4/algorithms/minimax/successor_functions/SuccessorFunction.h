/*
 * SuccessorFunction.h
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#ifndef SUCCESSORFUNCTION_H_
#define SUCCESSORFUNCTION_H_

#include <vector>
#include "../../../src/Utilities.h"

using namespace std;

/**
 * Abstract SuccessorFunction class for definition of successor function list generator from board configuration.
 */
class SuccessorFunction
{
public:
	SuccessorFunction(){}
	virtual ~SuccessorFunction(){}

	/**
	 * Gets a list of successors.
	 * @param board the current board configuration
	 * @param previousRow the row position of the last play
	 * @param previousCol the column position of the last plat
	 * @return a vector of vectors of integers where
	 *   the 0 index is the row and
	 *   the 1 index is the column
	 *   of a successor position to play.
	 */
	virtual vector<vector<int> > execute(vector<vector<int> >& board, int previousRow, int previousCol)=0;
};

#endif /* SUCCESSORFUNCTION_H_ */
