/*
 * MiniMax_MaxDepth.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#include "MiniMax_MaxDepth.h"

vector<int> MiniMax_MaxDepth::getMove(vector<vector<int> >& board, int previousRow, int previousCol) {
	startTime = time(0);
	vector<int> move = hMiniMax(board, 1, previousRow, previousCol);
	return {move[1], move[2]};
}

vector<int> MiniMax_MaxDepth::hMiniMax(vector<vector<int> >& board, int depth, int previousRow, int previousCol) {
	if (cutoffTest(board, depth, maxDepth)) return {heuristicFunction.execute(board, depth), previousRow, previousCol};
	vector<vector<int> > successors = successorFunction.execute(board, previousRow, previousCol);
	if (depth % 2 == 0) {
		vector<int> v = {NEG_INF};
		for (int i = 0; i < successors.size(); i ++) {
			int row = successors[i][0];
			int col = successors[i][1];
			board[row][col] = MAX;
			vector<int> res = hMiniMax(board, depth + 1, row, col);
			board[row][col] = 0;
			if (res[0] > v[0]) v = res;
		}
		return v;
	} else {
		vector<int> v = {INF};
		for (int i = 0; i < successors.size(); i ++) {
			int row = successors[i][0];
			int col = successors[i][1];
			board[row][col] = MIN;
			vector<int> res = hMiniMax(board, depth + 1, row, col);
			board[row][col] = 0;
			if (res[0] < v[0]) v = res;
		}
		return v;
	}
}
