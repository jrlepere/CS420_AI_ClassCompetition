/*
 * MiniMax_MaxDepth.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: JLepere2
 */

#include "MiniMax_MaxDepth.h"
#include <iostream>

vector<int> MiniMax_MaxDepth::getMove(vector<vector<int> >& board, int previousRow, int previousCol)
{
	startTime = time(0);
	vector<int> bestAction;
	int alpha = NEG_INF;
	int beta = INF;
	vector<int> v = maxValue(board, previousRow, previousCol, alpha, beta, 0);
	return {v[1],v[2]};
}

vector<int> MiniMax_MaxDepth::minValue(vector<vector<int> >& board, int previousRow, int previousCol, int alpha, int beta, int depth)
{
	int t = HeuristicFunction::terminalBoard(board);
	if (abs(t) == MAX) return {t, previousRow, previousCol};
	if (cutoffTest(board, depth, maxDepth)) return {heuristicFunction.execute(board), previousRow, previousCol};
	vector<vector<int> > successors = successorFunction.execute(board, previousRow, previousCol);
	vector<int> v = {INF};
	for (int i = 0; i < successors.size(); i ++) {
		vector<int> successor = successors[i];
		int row = successor[0];
		int col = successor[1];
		if (v.size() == 1) {
			v.push_back(row);
			v.push_back(col);
		}
		board[row][col] = MIN;
		vector<int> res = maxValue(board, row, col, alpha, beta, depth + 1);
		if (res[0] < v[0]) v = res;
		board[row][col] = 0;
		if (v[0] <= alpha) return v;
		beta = min(v[0], beta);
	}
	return v;
}

vector<int> MiniMax_MaxDepth::maxValue(vector<vector<int> >& board, int previousRow, int previousCol, int alpha, int beta, int depth)
{
	int t = HeuristicFunction::terminalBoard(board);
	if (abs(t) == MAX) return {t, previousRow, previousCol};
	if (cutoffTest(board, depth, maxDepth)) return {heuristicFunction.execute(board), previousRow, previousCol};
	vector<vector<int> > successors = successorFunction.execute(board, previousRow, previousCol);
	vector<int> v = {NEG_INF};
	for (int i = 0; i < successors.size(); i ++) {
		vector<int> successor = successors[i];
		int row = successor[0];
		int col = successor[1];
		if (v.size() == 1) {
			v.push_back(row);
			v.push_back(col);
		}
		board[row][col] = MAX;
		vector<int> res = minValue(board, row, col, alpha, beta, depth + 1);
		if (res[0] > v[0]) v = res;
		board[row][col] = 0;
		if (v[0] >= beta) return v;
		alpha = max(v[0], alpha);
	}
	return v;
}

