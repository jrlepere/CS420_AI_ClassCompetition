#ifndef ZOBRISTHASH_H_
#define ZOBRISTHASH_H_

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "../../../src/Utilities.h"

class ZobristHash {
public:
	ZobristHash();
	~ZobristHash(){};
	int getHashValue(vector<vector<int> >& board);
private:
	vector<vector<vector<int> > > initValues;
};

#endif /* ZOBRISTHASH_H_ */
