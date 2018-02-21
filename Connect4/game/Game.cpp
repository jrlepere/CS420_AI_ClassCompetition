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
	vector<int> move;
	while (!Game::isTerminalBoard(p1.getBoard())) {
		UtilityFunctions::printBoard(p1.getBoard());
		if (p1Turn) {
			move = p1.play();
			p2.opponentPlay(move[0], move[1]);
		} else {
			move = p2.play();
			p1.opponentPlay(move[0], move[1]);
		}
		p1Turn = !p1Turn;
	}
	UtilityFunctions::printBoard(p1.getBoard());
}

bool Game::isTerminalBoard(vector<vector<int> >& board) {

	// ROW TEST
	for (int row = 0; row < BOARD_SIZE; row ++) {
		if (board[row][3] != 0) {
			if ((board[row][0] == board[row][1]) && (board[row][1] == board[row][2]) && (board[row][2] == board[row][3])) return true;
			if ((board[row][2] == board[row][3]) && (board[row][3] == board[row][4]) && (board[row][4] == board[row][5])) return true;
			if ((board[row][6] == board[row][5]) && (board[row][5] == board[row][4]) && (board[row][4] == board[row][3])) return true;
		}
		if (board[row][4] != 0) {
			if ((board[row][1] == board[row][2]) && (board[row][2] == board[row][3]) && (board[row][3] == board[row][4])) return true;
			if ((board[row][7] == board[row][6]) && (board[row][6] == board[row][5]) && (board[row][5] == board[row][4])) return true;
		}
	}

	// COL TEST
	for (int col = 0; col < BOARD_SIZE; col ++) {
		if (board[3][col] != 0) {
			if ((board[0][col] == board[1][col]) && (board[1][col] == board[2][col]) && (board[2][col] == board[3][col])) return true;
			if ((board[2][col] == board[3][col]) && (board[3][col] == board[4][col]) && (board[4][col] == board[5][col])) return true;
			if ((board[6][col] == board[5][col]) && (board[5][col] == board[4][col]) && (board[4][col] == board[3][col])) return true;
		}
		if (board[4][col] != 0) {
			if ((board[1][col] == board[2][col]) && (board[2][col] == board[3][col]) && (board[3][col] == board[4][col])) return true;
			if ((board[7][col] == board[6][col]) && (board[6][col] == board[5][col]) && (board[5][col] == board[4][col])) return true;
		}
	}

	for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int col = 0; col < BOARD_SIZE; col ++) {
			if (board[row][col] == 0) return false;
		}
	}

	return true;
}
