/*
 * Player.h
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>

#include "../algorithms/Algorithm.h"
#include "../src/Utilities.h"

using namespace std;

class Player
{
public:
	Player(Algorithm& algo):
		algo(algo), tilesPlaced(0) {
		board = createInitialBoard();
	}
	~Player(){}
	vector<int> play(int previousRow, int previousCol);
	void opponentPlay(int row, int col);
	vector<vector<int> >& getBoard();
private:
	vector<vector<int> > createInitialBoard();
	Algorithm& algo;
	vector<vector<int> > board;
	int tilesPlaced;
};

#endif /* PLAYER_H_ */
