/*
 * Player.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#include "Player.h"

vector<int> Player::play() {
	vector<int> move = algo.getMove(board, 0, 0);
	int row = move[0];
	int col = move[1];
	board[row][col] = 1;
	return move;
}

void Player::opponentPlay(int row, int col) {
	board[row][col] = -1;
}

vector<vector<int> >& Player::getBoard() {
	return board;
}

vector<vector<int> > Player::createInitialBoard() {
	vector<vector<int> > board = {{0,0,0,0,0,0,0,0},
								  {0,0,0,0,0,0,0,0},
								  {0,0,0,0,0,0,0,0},
								  {0,0,0,0,0,0,0,0},
								  {0,0,0,0,0,0,0,0},
								  {0,0,0,0,0,0,0,0},
								  {0,0,0,0,0,0,0,0},
								  {0,0,0,0,0,0,0,0}};
	return {{0,0,0,0,0,0,0,0},
		   {0,0,0,0,0,0,0,0},
	   	   {0,0,0,0,0,0,0,0},
		   {0,0,0,0,0,0,0,0},
		   {0,0,0,0,0,0,0,0},
		   {0,0,0,0,0,0,0,0},
		   {0,0,0,0,0,0,0,0},
		   {0,0,0,0,0,0,0,0}};
}
