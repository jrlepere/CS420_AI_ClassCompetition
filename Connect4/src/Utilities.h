/*
 * Utilities.h
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <vector>

using namespace std;

const int BOARD_SIZE = 8;
const int MAX = 1;
const int MIN = -1;
const int MAX_WIN = 100;
const int MIN_WIN = -100;
const int INF = 1000;
const int NEG_INF = -1000;

class UtilityFunctions
{
public:
	static void printBoard(vector<vector<int> > board);
};

#endif /* UTILITIES_H_ */
