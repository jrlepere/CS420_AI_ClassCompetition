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

using namespace std;

class VisitedHashTable {
public:
	VisitedHashTable(){};
	~VisitedHashTable(){};
	void addVisited(vector<vector<int> >& board, int eval);
	int getValue(vector<vector<int> >& board);
	static const int NOT_VISITED_VALUE = 15353263;
private:
	int getHash(vector<vector<int> >& board);
	int getTransposeHash(vector<vector<int> >& board);
	unordered_map<int, int> map;
};



#endif /* VISITEDHASHTABLE_H_ */
