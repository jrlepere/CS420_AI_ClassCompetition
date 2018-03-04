/*
 * VisitedHashTable.cpp
 *
 *  Created on: Mar 2, 2018
 *      Author: JLepere2
 */

#include "VisitedHashTable.h"

void VisitedHashTable::addVisited(vector<vector<int> >& board, vector<vector<int> >& initialBoard, int eval) {
	map.insert({hash.getHashValue(board), eval});
}

int VisitedHashTable::getValue(vector<vector<int> >& board) {
	int h = hash.getHashValue(board);
	auto eval = map.find(h);
	if (eval != map.end()) return eval->second;
	return VisitedHashTable::NOT_VISITED_VALUE;
}
