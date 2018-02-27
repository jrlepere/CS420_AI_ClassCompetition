/*
 * ToddHeuristic.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: toddnguyen47
 */

#include "ToddHeuristic.h"

int ToddHeuristic::execute(vector<vector<int> >& board, int depth) {

	int v = winnerOrLoser(board, depth, 100);
	if (v != 0) return v;

	v = ToddHeuristic::preventOpponentKillerMove(board, depth, 97);
	if (v != 0) return v;

	v = killerMove(board, depth, 99);
	if (v != 0) return v;

	v = oneFromKiller(board, depth, 97);
	if (v != 0) return v;

	v = oneFromWinner(board, depth, 98);
	if (v != 0) return v;

	return final(board, depth, 96);
}

int ToddHeuristic::winnerOrLoser(vector<vector<int> >& board, int depth, int value) {

	// ROW TEST
	for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int i = 0; i < 5; i ++) {
			if ((board[row][i] != 0) &&
				(board[row][i] == board[row][i+1]) &&
				(board[row][i+1] == board[row][i+2]) &&
				(board[row][i+2] == board[row][i+3])
			) return board[row][i] * value;
		}
	}

	// COL TEST
	for (int col = 0; col < BOARD_SIZE; col ++) {
		for (int i = 0; i < 5; i ++) {
			if ((board[i][col] != 0) &&
				(board[i][col] == board[i+1][col]) &&
				(board[i+1][col] == board[i+2][col]) &&
				(board[i+2][col] == board[i+3][col])
				) return board[i][col] * value;
		}
	}

	return 0;
}

int ToddHeuristic::killerMove(vector<vector<int> >& board, int depth, int value) {

	int player;
	if (depth % 2 == 0) player = MAX;
	else player = MIN;

	bool opponentFound = false;

	// ROW TEST
	for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int i = 0; i < 4; i ++) {
			if ((board[row][i] == 0) &&
				(board[row][i+4] == 0) &&
				(board[row][i+1] != 0) &&
				(board[row][i+1] == board[row][i+2]) &&
				(board[row][i+1] == board[row][i+3])
			) {
				if (board[row][i+1] != player) opponentFound = true;
				else return board[row][i+1] * value;
			}
		}
	}

	// COL TEST
	for (int col = 0; col < BOARD_SIZE; col ++) {
		for (int i = 0; i < 4; i ++) {
			if ((board[i][col] == 0) &&
				(board[i+4][col] == 0) &&
				(board[i+1][col] != 0) &&
				(board[i+1][col] == board[i+2][col]) &&
				(board[i+2][col] == board[i+3][col])
			) {
				if (board[i+1][col] != player) opponentFound = true;
				return board[i+1][col] * value;
			}
		}
	}

	if (opponentFound) return (player * -1) * value;

	return 0;

}

int ToddHeuristic::oneFromWinner(vector<vector<int> >& board, int depth, int value) {
	int player;
	if (depth % 2 == 0) player = MAX;
	else player = MIN;

	bool opponentFound = false;

	// ROW TEST
	for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int i = 0; i < 5; i ++) {
			// 3x0 ->
			if ((board[row][i+3] == 0) &&
				(board[row][i] != 0) &&
				(board[row][i] == board[row][i+1]) &&
				(board[row][i+1] == board[row][i+2])
			) {
				if (board[row][i] != player) opponentFound = true;
				else return board[row][i] * value;
			}
			// 3x0 <-
			if ((board[row][BOARD_SIZE-(i+3)-1] == 0) &&
				(board[row][BOARD_SIZE-i-1] != 0) &&
				(board[row][BOARD_SIZE-i-1] == board[row][BOARD_SIZE-(i+1)-1]) &&
				(board[row][BOARD_SIZE-(i+1)-1] == board[row][BOARD_SIZE-(i+2)-1])
			) {
				if (board[row][BOARD_SIZE-i-1] != player) opponentFound = true;
				else return board[row][BOARD_SIZE-i-1] * value;
			}
			// 2x1 ->
			if ((board[row][i+2] == 0) &&
				(board[row][i] != 0) &&
				(board[row][i] == board[row][i+1]) &&
				(board[row][i+1] == board[row][i+3])
			) {
				if (board[row][i] != player) opponentFound = true;
				else return board[row][i] * value;
			}
			// 2x1 <-
			if ((board[row][BOARD_SIZE-(i+2)-1] == 0) &&
				(board[row][BOARD_SIZE-i-1] != 0) &&
				(board[row][BOARD_SIZE-i-1] == board[row][BOARD_SIZE-(i+1)-1]) &&
				(board[row][BOARD_SIZE-(i+1)-1] == board[row][BOARD_SIZE-(i+3)-1])
			) {
				if (board[row][BOARD_SIZE-i-1] != player) opponentFound = true;
				else return board[row][BOARD_SIZE-i-1] * value;
			}
		}
	}

	// COL TEST
	for (int col = 0; col < BOARD_SIZE; col ++) {
		for (int i = 0; i < 5; i ++) {
			// 3x0 ->
			if ((board[i+3][col] == 0) &&
				(board[i][col] != 0) &&
				(board[i][col] == board[i+1][col]) &&
				(board[i+1][col] == board[i+2][col])
			) {
				if (board[i][col] != player) opponentFound = true;
				else return board[i][col] * value;
			}
			// 3x0 <-
			if ((board[BOARD_SIZE-(i+3)-1][col] == 0) &&
				(board[BOARD_SIZE-i-1][col] != 0) &&
				(board[BOARD_SIZE-i-1][col] == board[BOARD_SIZE-(i+1)-1][col]) &&
				(board[BOARD_SIZE-(i+1)-1][col] == board[BOARD_SIZE-(i+2)-1][col])
			) {
				if (board[BOARD_SIZE-i-1][col] != player) opponentFound = true;
				else return board[BOARD_SIZE-i-1][col] * value;
			}
			// 2x1 ->
			if ((board[i+2][col] == 0) &&
				(board[i][col] != 0) &&
				(board[i][col] == board[i+1][col]) &&
				(board[i+1][col] == board[i+3][col])
			) {
				if (board[i][col] != player) opponentFound = true;
				else return board[i][col] * value;
			}
			// 2x1 <-
			if ((board[BOARD_SIZE-(i+2)-1][col] == 0) &&
				(board[BOARD_SIZE-i-1][col] != 0) &&
				(board[BOARD_SIZE-i-1][col] == board[BOARD_SIZE-(i+1)-1][col]) &&
				(board[BOARD_SIZE-(i+1)-1][col] == board[BOARD_SIZE-(i+3)-1][col])
			) {
				if (board[BOARD_SIZE-i-1][col] != player) opponentFound = true;
				else return board[BOARD_SIZE-i-1][col] * value;
			}
		}
	}

	if (opponentFound) return (player * -1) * value;

	return 0;
}

int ToddHeuristic::oneFromKiller(vector<vector<int> >& board, int depth, int value) {

	int player;
	if (depth % 2 == 0) player = MAX;
	else player = MIN;

	bool opponentFound = false;

	// ROW TEST
	for (int row = 0; row < BOARD_SIZE; row ++) {
		for (int i = 0; i < 4; i ++) {
			if ((board[row][i] == 0) &&
				(board[row][i+4] == 0)
			) {
				if ((
						(board[row][i+1] == 0) &&
						(board[row][i+2] != 0) &&
						(board[row][i+2] == board[row][i+3])
					) || (
						(board[row][i+2] == 0) &&
						(board[row][i+1] != 0) &&
						(board[row][i+1] == board[row][i+3])
					) || (
						(board[row][i+3] == 0) &&
						(board[row][i+1] != 0) &&
						(board[row][i+1] == board[row][i+2])
					)
				) {
					if (board[row][i+1] != player) opponentFound = true;
					else return board[row][i+1] * value;
				}
			}
		}
	}

	// COL TEST
	for (int col = 0; col < BOARD_SIZE; col ++) {
		for (int i = 0; i < 4; i ++) {
			if ((board[i][col] == 0) &&
				(board[i+4][col] == 0)
			) {
				if ((
						(board[i+1][col] == 0) &&
						(board[i+2][col] != 0) &&
						(board[i+2][col] == board[i+3][col])
					) || (
						(board[i+2][col] == 0) &&
						(board[i+1][col] != 0) &&
						(board[i+1][col] == board[i+3][col])
					) || (
						(board[i+3][col] == 0) &&
						(board[i+1][col] != 0) &&
						(board[i+1][col] == board[i+2][col])
					)
				) {
					if (board[i+1][col] != player) opponentFound = true;
					else return board[i+1][col] * value;
				}
			}
		}
	}

	if (opponentFound) return (player * -1) * value;

	return 0;

}

int ToddHeuristic::preventOpponentKillerMove(vector <vector<int> > & board, int depth, int value) {
	// Determine if player or opponent
	int player;
	if (depth % 2 == 0) player = MAX;
	else player = MIN;

	bool foundOpponent = false;

	// Test if it will block the move
	int testHeuristic = 10;

	// Check vertical
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < 7; j++) {
			// Check for XX_X
			if (j > 1 &&
				board[i][j] == 0 &&
				board[i][j-2] == (player * -1) &&
				board[i][j-2] == board[i][j-1] &&
				board[i][j-2] == board[i][j+1]) {
				return value * player;
			}
		}
	}

	return 0;
}

int ToddHeuristic::final(vector<vector<int> >& board, int depth, int value) {
	return 0;
}
