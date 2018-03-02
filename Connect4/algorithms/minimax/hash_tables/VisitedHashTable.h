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
	VisitedHashTable(){
		map.reserve(100000);
	};
	~VisitedHashTable(){
		map.clear();
	};
	void addVisited(vector<vector<int> >& board, int eval);
	int getValue(vector<vector<int> >& board);
	static const int NOT_VISITED_VALUE = 15353263;
private:
	int getHash1(vector<vector<int> >& board);
	int getHash2(vector<vector<int> >& board);
	void addHash2(vector<vector<int> >& board, int eval);
	int getHash3(vector<vector<int> >& board);
	int getHash4(vector<vector<int> >& board);
	int getHash5(vector<vector<int> >& board);
	int getHash6(vector<vector<int> >& board);
	int getHash7(vector<vector<int> >& board);
	int getHash8(vector<vector<int> >& board);
	unordered_map<int, int> map;
	hash<string> hash;
};



#endif /* VISITEDHASHTABLE_H_ */
