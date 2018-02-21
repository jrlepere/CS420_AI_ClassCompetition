/*
 * Game.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: JLepere2
 */

#include <iostream>
#include "Game.h"

void Game::play() {
	bool p1Turn = true;
	int previousRow = 0;
	int previousCol = 0;
	vector<int> move;
	while (!Game::isTerminalBoard(p1.getBoard())) {
		UtilityFunctions::printBoard(p1.getBoard());
		if (p1Turn) {
			move = p1.play(previousRow, previousCol);
			p2.opponentPlay(move[0], move[1]);
			previousRow = move[0];
			previousCol = move[1];
		} else {
			move = p2.play(previousRow, previousCol);
			p1.opponentPlay(move[0], move[1]);
			previousRow = move[0];
			previousCol = move[1];
		}
		p1Turn = !p1Turn;
	}
	UtilityFunctions::printBoard(p1.getBoard());
}

bool Game::isTerminalBoard(vector<vector<int> >& board) {

	// ROW TEST
	for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int i = 0; i < 5; i ++) {
			if ((board[row][i] != 0) &&
				(board[row][i] == board[row][i+1]) &&
				(board[row][i+1] == board[row][i+2]) &&
				(board[row][i+2] == board[row][i+3])
				) return true;
		}
	}

	// COL TEST
	for (int col = 0; col < BOARD_SIZE; col ++) {
		for (int i = 0; i < 5; i ++) {
			if ((board[i][col] != 0) &&
				(board[i][col] == board[i+1][col]) &&
				(board[i+1][col] == board[i+2][col]) &&
				(board[i+2][col] == board[i+3][col])
				) return true;
		}
	}

	// FULL BOARD
	for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int col = 0; col < BOARD_SIZE; col ++) {
			if (board[row][col] == 0) return false;
		}
	}

	return true;
}
