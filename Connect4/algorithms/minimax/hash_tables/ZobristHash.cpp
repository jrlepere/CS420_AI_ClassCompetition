#include "ZobristHash.H"

ZobristHash::ZobristHash() {
	// Initialize the board once
	int numberOfPieces = 2; // 2 pieces, 1 and -1
	srand(time(NULL)); //randomize seed
	
	for (int i = 0; i < BOARD_SIZE; i++) {	
		vector< vector <int> > temp;
		for (int j = 0; j < BOARD_SIZE; j++) {
			vector<int> tempPiece;			
			// 0th index is 1
			// 1st index is -1
			for (int piece = 0; piece < numberOfPieces; piece++) {
				tempPiece.push_back(rand());
			}

			temp.push_back(tempPiece);
		}
		initValues.push_back(temp);	
	}
}

int ZobristHash::getHashValue(vector< vector<int> > &board) {
	int hashValue = 0;
	
	// For hash, 0 index = 1, 1st index = -1
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
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