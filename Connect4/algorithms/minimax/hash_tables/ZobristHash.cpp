#include "ZobristHash.H"

ZobristHash::ZobristHash() {
	// Initialize the board once
	int numberOfPieces = 2; // 2 pieces, 1 and -1
	unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed1);
	
	std::uniform_int_distribution<int> distribution(0, LONG_MAX);
	
	for (int i = 0; i < BOARD_SIZE; i++) {	
		vector< vector <int> > temp;
		for (int j = 0; j < BOARD_SIZE; j++) {
			int rand1 = distribution(generator);
			int rand2 = distribution(generator);
			std::cout << "(" << rand1 << ", " << rand2 << ")\t";
			temp.push_back({rand1, rand2});
		}
		initValues.push_back(temp);	
		vector< vector <int> > temp2;
		temp.swap(temp2); // clear vector
	}
}

ZobristHash::~ZobristHash() {
	vector< vector <vector<int> > > emptyVector;
	initValues.swap(emptyVector);
}

int ZobristHash::getHashValue(vector< vector<int> > &board) {
	int hashValue = 0;
	
	// For hash, 0 index = 1, 1st index = -1
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			// Hash for Player Max (1)
			if (board[i][j] == MAX) {
				hashValue = hashValue ^ initValues[i][j][0];
			}
			// Hash for Player Min
			else if (board[i][j] == MIN) {
				hashValue = hashValue ^ initValues[i][j][1];
			}
		}
	}

	return hashValue;
}