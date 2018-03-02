/*
 * VisitedHashTable.cpp
 *
 *  Created on: Mar 2, 2018
 *      Author: JLepere2
 */

#include "VisitedHashTable.h"

void VisitedHashTable::addVisited(vector<vector<int> >& board, int eval) {
	map.insert(make_pair(getHash(board), eval));
	map.insert(make_pair(getTransposeHash(board), eval));
	// ADD 7 other inversions
}

int VisitedHashTable::getValue(vector<vector<int> >& board) {

	int hash = getHash(board);
	auto eval = map.find(hash);
	if (eval != map.end()) return eval->second;
	return VisitedHashTable::NOT_VISITED_VALUE;

	/*
	// IDENTICAL
	int hash = getHash(board);
	auto eval = map.find(hash);
	if (eval != map.end()) return eval->second;

	// TRANSPOSE
	hash = getTransposeHash(board);
	eval = map.find(hash);
	if (eval != map.end()) return eval->second;

	return VisitedHashTable::NOT_VISITED_VALUE;
	*/
}

int VisitedHashTable::getHash(vector<vector<int> >& board) {
	string s = "";
	for (int r = 0; r < BOARD_SIZE; r ++) {
		for (int c = 0; c < BOARD_SIZE; c ++) {
			s += board[r][c];
		}
	}
	return hash<string>{}(s);
}

int VisitedHashTable::getTransposeHash(vector<vector<int> >& board) {
	string s = "";
	for (int c = 0; c < BOARD_SIZE; c ++) {
		for (int r = 0; r < BOARD_SIZE; r ++) {
			s += board[r][c];
		}
	}
	return hash<string>{}(s);
}
