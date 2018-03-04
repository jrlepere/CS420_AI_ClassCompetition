/*
 * Game.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: JLepere2
 */

#include <iostream>
#include "Game.h"

void Game::play(bool opponentTurn) {
	//bool p1Turn = true;
	bool p1Turn = opponentTurn; // p1 is opponent AI, p2 is our AI
	int previousRow = 3;
	int previousCol = 4;
	vector<int> move;
	while (!Game::isTerminalBoard(p1.getBoard())) {
		UtilityFunctions::printBoard(p1.getBoard(), opponentTurn);
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
		UtilityFunctions::addMove(previousRow, previousCol);
		p1Turn = !p1Turn;
	}
	UtilityFunctions::printBoard(p1.getBoard(), opponentTurn);
	
	bool p1Won = !p1Turn; // need to reverse it again
	// Since opponent is ALWAYS p1 in our implementation
	if (p1Won)
		std::cout << "You lost... Better luck next time.\n";
	else
		std::cout << "You won!\n";
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
