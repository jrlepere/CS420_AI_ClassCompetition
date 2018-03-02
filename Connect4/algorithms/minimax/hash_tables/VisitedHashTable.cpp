/*
 * VisitedHashTable.cpp
 *
 *  Created on: Mar 2, 2018
 *      Author: JLepere2
 */

#include "VisitedHashTable.h"

void VisitedHashTable::addVisited(vector<vector<int> >& board, int eval) {
	map.insert({getHash1(board), eval});
	map.insert({getHash2(board), eval});
	//addHash2(board, eval);
	map.insert({getHash3(board), eval});
	map.insert({getHash4(board), eval});
	map.insert({getHash5(board), eval});
	map.insert({getHash6(board), eval});
	map.insert({getHash7(board), eval});
	map.insert({getHash8(board), eval});
}

int VisitedHashTable::getValue(vector<vector<int> >& board) {

	int hash = getHash1(board);
	auto eval = map.find(hash);
	if (eval != map.end()) return eval->second;
	return VisitedHashTable::NOT_VISITED_VALUE;

	/*
	// IDENTICAL
	int hash = getHash(board);
	auto eval = map.find(hash);
	if (eval != map.end()) return eval->second;

	// TRANSPOSE
	//hash = getTransposeHash(board);
	//eval = map.find(hash);
	//if (eval != map.end()) return eval->second;

	// VERTICAL MIRROR
	hash = getVerticalMirrorHash(board);
	eval = map.find(hash);
	if (eval != map.end()) return eval->second;

	// HORIZONTAL MIRROR
	hash = getHorizontalMirrorHash(board);
	eval = map.find(hash);
	if (eval != map.end()) return eval->second;

	return VisitedHashTable::NOT_VISITED_VALUE;
	*/
}

int VisitedHashTable::getHash1(vector<vector<int> >& board) {
	string s = "";
	for (int r = 0; r < BOARD_SIZE; r ++) {
		for (int c = 0; c < BOARD_SIZE; c ++) {
			s += board[r][c];
		}
	}
	return hash(s);
}

int VisitedHashTable::getHash2(vector<vector<int> >& board) {
	/*return hash<string>{}(
			board[0][7] + board[0][6] + board[0][5] + board[0][4] + board[0][3] + board[0][2] + board[0][1] + board[0][0]
			);*/
	string s = "";
	for (int r = 0; r < BOARD_SIZE; r ++) {
		for (int c = BOARD_SIZE - 1; c >= 0; c --) {
			s += board[r][c];
		}
	}
	return hash(s);
}

void VisitedHashTable::addHash2(vector<vector<int> >& board, int eval) {
	/*
	 * A B C D     D C B A
	 * E F G H     H G F E
	 * I J K L     L K J I
	 * M N O P     P O N M
	 */
	bool add = false;
	for (int r = 0; !add && r < BOARD_SIZE; r ++) {
		for (int c = 0; !add && c < BOARD_SIZE / 2; c ++) {
			if (board[r][c] != board[r][BOARD_SIZE - 1 + c]) {
				add = true;
			}
		}
	}
	if (!add) return;
	string s = "";
	for (int r = 0; r < BOARD_SIZE; r ++) {
		for (int c = BOARD_SIZE - 1; c >= 0; c --) {
			s += board[r][c];
		}
	}
	int h = hash(s);
	map.insert({h, eval});
	//return hash<string>{}(s);
}

int VisitedHashTable::getHash3(vector<vector<int> >& board) {
	string s = "";
	for (int r = BOARD_SIZE - 1; r >= 0; r --) {
		for (int c = 0; c < BOARD_SIZE; c ++) {
			s += board[r][c];
		}
	}
	return hash(s);
}

int VisitedHashTable::getHash4(vector<vector<int> >& board) {
	string s = "";
	for (int r = BOARD_SIZE - 1; r >= 0; r --) {
		for (int c = BOARD_SIZE - 1; c >= 0; c --) {
			s += board[r][c];
		}
	}
	return hash(s);
}

int VisitedHashTable::getHash5(vector<vector<int> >& board) {
	string s = "";
	for (int c = 0; c < BOARD_SIZE; c ++) {
		for (int r = 0; r < BOARD_SIZE; r ++) {
			s += board[r][c];
		}
	}
	return hash(s);
}

int VisitedHashTable::getHash6(vector<vector<int> >& board) {
	string s = "";
	for (int c = 0; c < BOARD_SIZE; c ++) {
		for (int r = BOARD_SIZE - 1; r >= 0; r --) {
			s += board[r][c];
		}
	}
	return hash(s);
}

int VisitedHashTable::getHash7(vector<vector<int> >& board) {
	string s = "";
	for (int c = BOARD_SIZE - 1; c >= 0; c --) {
		for (int r = 0; r < BOARD_SIZE; r ++) {
			s += board[r][c];
		}
	}
	return hash(s);
}

int VisitedHashTable::getHash8(vector<vector<int> >& board) {
	string s = "";
	for (int c = BOARD_SIZE - 1; c >= 0; c --) {
		for (int r = BOARD_SIZE - 1; r >= 0; r --) {
			s += board[r][c];
		}
	}
	return hash(s);
}
