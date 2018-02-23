/*
 * JakesHeuristic.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: JLepere2
 */

#include "JakesHeuristic.h"

int JakesHeuristic::execute(vector<vector<int> >& board, int depth) {

	int v = winnerOrLoser(board, depth, 100);
	if (v != 0) return v;

	v = killerMove(board, depth, 99);
	if (v != 0) return v;

	v = oneFromKiller(board, depth, 97);
	if (v != 0) return v;

	v = oneFromWinner(board, depth, 98);
	if (v != 0) return v;

	return final(board, depth, 96);
}

int JakesHeuristic::winnerOrLoser(vector<vector<int> >& board, int depth, int value) {

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

int JakesHeuristic::killerMove(vector<vector<int> >& board, int depth, int value) {

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
				(board[row][i+2] == board[row][i+3])
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

int JakesHeuristic::oneFromWinner(vector<vector<int> >& board, int depth, int value) {
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

int JakesHeuristic::oneFromKiller(vector<vector<int> >& board, int depth, int value) {

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

int JakesHeuristic::final(vector<vector<int> >& board, int depth, int value) {
	return 0;
}

