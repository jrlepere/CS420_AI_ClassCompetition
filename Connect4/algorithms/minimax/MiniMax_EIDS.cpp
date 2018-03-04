/*
 * MiniMax_EIDS.cpp
 *
 *  Created on: Mar 3, 2018
 *      Author: JLepere2
 */

#include "MiniMax_EIDS.h"

vector<int> MiniMax_EIDS::getMove(vector<vector<int> >& board, int previousRow, int previousCol, int currentNumTiles) {
	// TODO: OPTIMIZE????
	initialBoard.clear();
	for (int r = 0; r < BOARD_SIZE; r ++) {
		vector<int> rv;
		for (int c = 0; c < BOARD_SIZE; c ++) {
			rv.push_back(board[r][c]);
		}
		initialBoard.push_back(rv);
	}
	currentTilesPlaced = currentNumTiles;
	startTime = time(0);
	maxDepth = 1;
	vector<int> bestMove;
	while (true) {
		visitedHash.clear();
		int alpha = NEG_INF;
		int beta = INF;
		int depth = 0;
		count = 0;
		vector<int> move = hMiniMax(board, depth, alpha, beta, previousRow, previousCol);
		cout<<"ply: "<<maxDepth<<" in "<<difftime(time(0), startTime)<<"s - "<<count<<"\n";
		if (difftime(time(0), startTime) > maxTime) return {bestMove[0], bestMove[1]};
		bestMove = {move[1],move[2]};
		maxDepth ++;
	}
}

vector<int> MiniMax_EIDS::hMiniMax(vector<vector<int> >& board, int depth, int alpha, int beta, int previousRow, int previousCol) {
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
			//vector<int> res = hMiniMax(board, newDepth, alpha, beta, row, col);
			vector<int> res;
			int visistedValue = visitedHash.getValue(board);
			if (visistedValue != VisitedHashTable::NOT_VISITED_VALUE) {
				res = {visistedValue};
			} else {
				res = hMiniMax(board, newDepth, alpha, beta, row, col);
				visitedHash.addVisited(board, initialBoard, res[0]);
			}
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
			//vector<int> res = hMiniMax(board, newDepth, alpha, beta, row, col);
			vector<int> res;
			int visistedValue = visitedHash.getValue(board);
			if (visistedValue != VisitedHashTable::NOT_VISITED_VALUE) {
				//cout<<"checking\n";
				res = {visistedValue};
			} else {
				res = hMiniMax(board, newDepth, alpha, beta, row, col);
				visitedHash.addVisited(board, initialBoard, res[0]);
			}
			board[row][col] = 0;
			if (res[0] < v[0]) v = {res[0], row, col};
			if (v[0] <= alpha) return v;
			beta = min(v[0], beta);
		}
		return v;
	}
}
