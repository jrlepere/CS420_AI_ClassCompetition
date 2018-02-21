/*
 * Game.h
 *
 *  Created on: Feb 21, 2018
 *      Author: JLepere2
 */

#ifndef GAME_H_
#define GAME_H_

#include "../player/Player.h"

class Game
{
public:
	Game(Player& p1, Player& p2):
		p1(p1), p2(p2) {}
	void play();

private:
	static bool isTerminalBoard(vector<vector<int> >& board);
	Player& p1;
	Player& p2;
};

#endif /* GAME_H_ */
