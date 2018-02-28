/*
 * MiniMax_MaxDepth.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#include <iostream>
#include "MiniMax_MaxDepth.h"

vector<int> MiniMax_MaxDepth::getMove(vector<vector<int> >& board, int previousRow, int previousCol, int currentNumTiles) {
	currentTilesPlaced = currentNumTiles;
	startTime = time(0);
	int alpha = NEG_INF;
	int beta = INF;
	int depth = 0;
	count = 0;
	vector<int> move = hMiniMax(board, depth, alpha, beta, previousRow, previousCol);
	cout<<count<<"\n";
	return {move[1], move[2]};
}

vector<int> MiniMax_MaxDepth::hMiniMax(vector<vector<int> >& board, int depth, int alpha, int beta, int previousRow, int previousCol) {
	count ++;
	if (cutoffTest(board, depth, maxDepth)) return {heuristicFunction.execute(board, depth)};
	vector<vector<int> > successors = successorFunction.execute(board, previousRow, previousCol);
	if (depth % 2 == 0) {
		vector<int> v = {NEG_INF, -1, -1};
		for (int i = 0; i < successors.size(); i ++) {
			int row = successors[i][0];
			int col = successors[i][1];
			board[row][col] = MAX;
			int newDepth = depth + 1;
			vector<int> res = hMiniMax(board, newDepth, alpha, beta, row, col);
			board[row][col] = 0;
			if (res[0] > v[0]) {v = {res[0], row, col};}
			if (v[0] >= beta) return v;
			alpha = max(v[0], alpha);
		}
		// Shows how deep IDS is going. Comment out.
		//if (depth == 0) std::cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
		return v;
	} else {
		vector<int> v = {INF, -1, -1};
		for (int i = 0; i < successors.size(); i ++) {
			int row = successors[i][0];
			int col = successors[i][1];
			board[row][col] = MIN;
			int newDepth = depth + 1;
			vector<int> res = hMiniMax(board, newDepth, alpha, beta, row, col);
			board[row][col] = 0;
			if (res[0] < v[0]) v = {res[0], row, col};
			if (v[0] <= alpha) return v;
			beta = min(v[0], beta);
		}
		return v;
	}
}
