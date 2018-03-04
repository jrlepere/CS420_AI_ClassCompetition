/*
 * VisitedHashTable.cpp
 *
 *  Created on: Mar 2, 2018
 *      Author: JLepere2
 */

#include "VisitedHashTable.h"

void VisitedHashTable::addVisited(vector<vector<int> >& board, vector<vector<int> >& initialBoard, int eval) {
	map.insert({getHash1(board), eval});
	//addHash2(board, initialBoard, eval);
	//addHash3(board, initialBoard, eval);
	//addHash4(board, initialBoard, eval);
}

int VisitedHashTable::getValue(vector<vector<int> >& board) {
	int hash = getHash1(board);
	auto eval = map.find(hash);
	if (eval != map.end()) return eval->second;
	return VisitedHashTable::NOT_VISITED_VALUE;
}

int VisitedHashTable::getHash1(vector<vector<int> >& board) {
	string s = "";
	for (int r = 0; r < BOARD_SIZE; r ++) {
		for (int c = 0; c < BOARD_SIZE; c ++) {
			s += board[r][c];
		}
	}
	return hash(s);
	//return hash.getHashValue(board);
}

/*
void VisitedHashTable::addHash2(vector<vector<int> >& board, vector<vector<int> >& initialBoard, int eval) {
	string s = "";
	for (int r = 0; r < BOARD_SIZE; r ++) {
		for (int c = BOARD_SIZE - 1; c >= 0; c --) {
			if (initialBoard[r][BOARD_SIZE-(1+c)] != 0 && initialBoard[r][BOARD_SIZE-(1+c)] != board[r][c]) return;
			s += board[r][c];
		}
	}
	map.insert({hash(s), eval});
}

void VisitedHashTable::addHash3(vector<vector<int> >& board, vector<vector<int> >& initialBoard, int eval) {
	string s = "";
	for (int r = BOARD_SIZE - 1; r >= 0; r --) {
		for (int c = 0; c < BOARD_SIZE; c ++) {
			if (initialBoard[BOARD_SIZE-(1+r)][c] != 0 && initialBoard[BOARD_SIZE-(1+r)][c] != board[r][c]) return;
			s += board[r][c];
		}
	}
	map.insert({hash(s), eval});
}

void VisitedHashTable::addHash4(vector<vector<int> >& board, vector<vector<int> >& initialBoard, int eval) {
	string s = "";
	for (int r = BOARD_SIZE - 1; r >= 0; r --) {
		for (int c = BOARD_SIZE - 1; c >= 0; c --) {
			if (initialBoard[BOARD_SIZE-(1+r)][BOARD_SIZE-(1+c)] != 0 && initialBoard[BOARD_SIZE-(1+r)][BOARD_SIZE-(1+c)] != board[r][c]) return;
			s += board[r][c];
		}
	}
	map.insert({hash(s), eval});
}
*/
/*
void VisitedHashTable::addHash5(vector<vector<int> >& board, vector<vector<int> >& initialBoard, int eval) {
	string s = "";
	for (int c = 0; c < BOARD_SIZE; c ++) {
		for (int r = 0; r < BOARD_SIZE; r ++) {
			if (initialBoard[c][r] != 0 && initialBoard[c][r] != board[r][c]) return;
			s += board[r][c];
		}
	}
	map.insert({hash(s), eval});
}

void VisitedHashTable::addHash6(vector<vector<int> >& board, vector<vector<int> >& initialBoard, int eval) {
	string s = "";
	for (int c = 0; c < BOARD_SIZE; c ++) {
		for (int r = BOARD_SIZE - 1; r >= 0; r --) {
			if (initialBoard[c][BOARD_SIZE-(1+r)] != 0 && initialBoard[c][BOARD_SIZE-(1+r)] != board[r][c]) return;
			s += board[r][c];
		}
	}
	map.insert({hash(s), eval});
}

int VisitedHashTable::getHash2(vector<vector<int> >& board) {
	string s = "";
	for (int r = 0; r < BOARD_SIZE; r ++) {
		for (int c = BOARD_SIZE - 1; c >= 0; c --) {
			s += board[r][c];
		}
	}
	return hash(s);
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
*/
