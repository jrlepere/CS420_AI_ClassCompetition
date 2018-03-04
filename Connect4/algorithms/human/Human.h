/*
 * Human.h
 *
 *  Created on: Feb 23, 2018
 *      Author: JLepere2
 */

#ifndef HUMAN_H_
#define HUMAN_H_

#include "../Algorithm.h"
#include "../../src/Utilities.h"

class Human: public Algorithm
{
public:
	Human():
		Algorithm(0) {};
	~Human(){};
	vector<int> getMove(vector<vector<int> >& board, int previousRow, int previousCol, int currentNumTiles);
};

#endif /* HUMAN_H_ */
