/*
 * Bloom.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: JLepere2
 */

#include <iostream>
#include "Bloom.h"

vector<vector<int> > Bloom::execute(vector<vector<int> >& board, int previousRow, int previousCol)
{
	vector<vector<int> > successors;

	// Max Number Of Bloom Iterations
	int x = max(max(previousRow, BOARD_SIZE - previousRow - 1), max(previousCol, BOARD_SIZE - previousCol - 1));

	int pr = previousRow;
	int pc = previousCol;
	int i = 1;
	bool canUp = true;
	bool canDown = true;
	bool canLeft = true;
	bool canRight = true;
	while (i <= x) {
		canUp = canUp && pr - i >= 0;
		canDown = canDown && pr + i < BOARD_SIZE;
		canLeft = canLeft && pc - i >= 0;
		canRight = canRight && pc + i < BOARD_SIZE;
		// UP & DOWN
		if (canUp) if (board[pr-i][pc] == 0) successors.push_back({pr-i,pc});  // NORTH
		if (canDown) if (board[pr+i][pc] == 0) successors.push_back({pr+i,pc});  // SOUTH
		if (canLeft) if (board[pr][pc-i] == 0) successors.push_back({pr,pc-i});  // WEST
		if (canRight) if (board[pr][pc+i] == 0) successors.push_back({pr,pc+i}); // EAST
		// FILL-INS
		bool canUp2 = true;
		bool canDown2 = true;
		bool canRight2 = true;
		bool canLeft2 = true;
		for (int j = 1; j < i; j ++) {
			canUp2 = canUp2 && pr - j >= 0;
			canDown2 = canDown2 && pr + j < BOARD_SIZE;
			canLeft2 = canLeft2 && pc - j >= 0;
			canRight2 = canRight2 && pc + j < BOARD_SIZE;
			if (canRight) {
				if (canDown2) if (board[pr+j][pc+i] == 0) successors.push_back({pr+j,pc+i});
				if (canUp2) if (board[pr-j][pc+i] == 0) successors.push_back({pr-j,pc+i});
			}
			if (canLeft) {
				if (canDown2) if (board[pr+j][pc-i] == 0) successors.push_back({pr+j,pc-i});
				if (canUp2) if (board[pr-j][pc-i] == 0) successors.push_back({pr-j,pc-i});
			}
			if (canDown) {
				if (canRight2) if (board[pr+i][pc+j] == 0) successors.push_back({pr+i,pc+j});
				if (canLeft2) if (board[pr+i][pc-j] == 0) successors.push_back({pr+i,pc-j});
			}
			if (canUp) {
				if (canRight2) if (board[pr-i][pc+j] == 0) successors.push_back({pr-i,pc+j});
				if (canLeft2) if (board[pr-i][pc-j] == 0) successors.push_back({pr-i,pc-j});
			}
		}
		// DIAGONALS
		if (canDown) {
			if (canRight) if (board[pr+i][pc+i] == 0) successors.push_back({pr+i,pc+i});
			if (canLeft) if (board[pr+i][pc-i] == 0) successors.push_back({pr+i,pc-i});
		}
		if (canUp) {
			if (canRight) if (board[pr-i][pc+i] == 0) successors.push_back({pr-i,pc+i});
			if (canLeft) if (board[pr-i][pc-i] == 0) successors.push_back({pr-i,pc-i});
		}
		i ++;
	}
	cout<<successors.size()<<"\n";
	for (int t = 0; t < successors.size(); t ++) {
		cout<<successors[t][0]<<" "<<successors[t][1]<<"\n";
	}
	cout<<"---------------------\n\n\n";
	int f;
	cin>>f;
	return successors;
}
