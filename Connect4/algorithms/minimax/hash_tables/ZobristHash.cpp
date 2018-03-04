#include "ZobristHash.h"

ZobristHash::ZobristHash() {
	// Initialize the board once
	srand(time(0)); //randomize seed
	
	for (int i = 0; i < BOARD_SIZE; i++) {	
		vector<vector<int> > temp;
		for (int j = 0; j < BOARD_SIZE; j++) {
			int v1 = rand();
			int v2 = rand();
			std::cout << v1 << "   " << v2 << "\n";
			temp.push_back({v1, v2});
		}
		initValues.push_back(temp);
		temp.clear();
	}

}

int ZobristHash::getHashValue(vector<vector<int> >& board) {
	int hashValue = 0;
	
	// For hash, 0 index = 1, 1st index = -1
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			// Hash for Player Max (1)
			if (board[i][j] == MAX) {
				hashValue ^= initValues[i][j][0];
			}
			// Hash for Player Min
			else if (board[i][j] == MIN) {
				hashValue ^= initValues[i][j][1];
			}
		}
	}

	return hashValue;
}
