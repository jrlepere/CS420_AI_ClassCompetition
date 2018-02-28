/*
 * Algorithm.h
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include <vector>

using namespace std;

/**
 * An abstract Algorithm for specifying how the Player will select the next move.
 */
class Algorithm
{
public:

	/**
	 * Creates an Algorithm with a maximum executing time.
	 * @param maxTime the max time the algorithm can run for, in seconds.
	 */
	Algorithm(int maxTime): maxTime(maxTime), startTime(0) {}

	virtual ~Algorithm(){}

	/**
	 * Gets the position of the next optimal play on the board.
	 * @param board the board
	 * @param previousRow the row position of the last play
	 * @param previousCol the col position of the last play
	 * @return an integer vector of size 2 where
	 *   the 0 index represents the row and
	 *   the 1 index represents the col.
	 */
	virtual vector<int> getMove(vector<vector<int> >& board, int previousRow, int previousCol, int currentNumTiles)=0;

protected:
	int maxTime; // The maximum time the algorithm can execute for before having to return a move.
	int startTime; // Variable for holding the starting time of the algorithm executing.
};

#endif /* ALGORITHM_H_ */
