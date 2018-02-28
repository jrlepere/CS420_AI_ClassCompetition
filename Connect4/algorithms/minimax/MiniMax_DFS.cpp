/*
 * MiniMax_DFS.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#include "MiniMax_DFS.h"

vector<int> MiniMax_DFS::getMove(vector<vector<int> >& board, int previousRow, int previousCol) {
	startTime = time(0);
	int alpha = NEG_INF;
	int beta = INF;
	int depth = 1;
	vector<int> move = hMiniMax(board, depth, alpha, beta, previousRow, previousCol);
	return {move[1], move[2]};
}

vector<int> MiniMax_DFS::hMiniMax(vector<vector<int> >& board, int depth, int alpha, int beta, int previousRow, int previousCol) {
	if (cutoffTest(board, depth, INF)) return {heuristicFunction.execute(board, depth)};
	vector<vector<int> > successors = successorFunction.execute(board, previousRow, previousCol);
	if (depth % 2 == 0) {
		vector<int> v = {NEG_INF};
		for (int i = 0; i < successors.size(); i ++) {
			int row = successors[i][0];
			int col = successors[i][1];
			board[row][col] = MAX;
			vector<int> res = hMiniMax(board, depth + 1, alpha, beta, row, col);
			board[row][col] = 0;
			if (res[0] > v[0]) {v = {res[0], row, col};}
			if (v[0] >= beta) return v;
			alpha = max(v[0], alpha);
		}
		return v;
	} else {
		vector<int> v = {INF};
		for (int i = 0; i < successors.size(); i ++) {
			int row = successors[i][0];
			int col = successors[i][1];
			board[row][col] = MIN;
			vector<int> res = hMiniMax(board, depth + 1, alpha, beta, row, col);
			board[row][col] = 0;
			if (res[0] < v[0]) {v = {res[0], row, col};}
			if (v[0] <= alpha) return v;
			beta = min(v[0], beta);
		}
		return v;
	}
}
