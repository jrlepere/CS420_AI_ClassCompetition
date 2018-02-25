#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <limits>

const int PLAYER_MAX = 1;
const int PLAYER_MIN = -1;
const int BOARD_SIZE = 8;
const int MAX_H_VALUE = 100;
const int POS_INFINITY = std::numeric_limits<int>::max();
const int NEG_INFINITY = std::numeric_limits<int>::min();

class ConnectFour {
    public:
        ConnectFour();
        ConnectFour(int input);
        virtual ~ConnectFour();
        int getTimeTaken();
        int MinimaxDecision(std::vector<std::vector<int> > state, int depth);
        int MaxValue(std::vector< std::vector<int> > state, int depth);
        int MinValue(std::vector< std::vector<int> > state, int depth);
        bool TerminalTest(std::vector< std::vector<int> > state);
        std::vector< std::vector<int> > getBoard();
        void printBoard();
		void putOnBoard(int input, int row, int col);
		int UtilityFunction(std::vector< std::vector<int> > state, int player);
		int CheckForThree(std::vector< std::vector<int> > state, int player);
		std::vector< std::vector<int> > getSuccessors(std::vector< std::vector<int> > state);
		int chosenHeuristic(std::vector< std::vector<int> > state, int depth);
		int debugHeuristic(std::vector< std::vector<int> > state, int depth);
    private:
        int timeTaken;
        std::vector< std::vector<int> > board;
};

#endif // CONNECTFOUR_H
