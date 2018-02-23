/*
 * Player.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#include "Player.h"

vector<int> Player::play(int previousRow, int previousCol) {
	vector<int> move = algo.getMove(board, previousRow, previousCol);
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
	vector<vector<int> > board;
	for (int i = 0; i < BOARD_SIZE; i ++) {
		vector<int> row;
		for (int j = 0; j < BOARD_SIZE; j ++) {
			row.push_back(0);
		}
		board.push_back(row);
	}
	return board;
}
