/*
 * Utilities.h
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <vector>
#include <string>
#include <math.h>
#include <iostream>

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
	static int terminalBoard(vector<vector<int> > board, int depth);
	static void addMove(int row, int col);
private:
	static vector<string> pastMoves;
	static string rowStr[BOARD_SIZE];
	static string colStr[BOARD_SIZE];
};

#endif /* UTILITIES_H_ */
