/*
 * VisitedHashTable.h
 *
 *  Created on: Mar 2, 2018
 *      Author: JLepere2
 */

#ifndef VISITEDHASHTABLE_H_
#define VISITEDHASHTABLE_H_

#include <vector>
#include <string>
#include <unordered_map>
#include "../../../src/Utilities.h"
#include "ZobristHash.h"

using namespace std;

class VisitedHashTable {
public:
	VisitedHashTable() {
		map.reserve(100000);
	};
	~VisitedHashTable(){
		map.clear();
	};
	void clear() {
		map.clear();
	}
	void addVisited(vector<vector<int> >& board, vector<vector<int> >& initialBoard, int eval);
	int getValue(vector<vector<int> >& board);
	static const int NOT_VISITED_VALUE = 15353263;
private:
	unordered_map<int, int> map;
	ZobristHash hash;
};

#endif /* VISITEDHASHTABLE_H_ */
