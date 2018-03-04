//============================================================================
// Name        : Connect4.cpp
// Author      : Jake Lepere && Tho Nguyen
// Version     : 1
// Copyright   : Class competition.
// Description : This project is for a class competition where we compete
//               against other student groups in a modified Connect 4 game.
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm> // to transform string to lowercase
#include <string>

#include "../algorithms/human/Human.h"
#include "../algorithms/minimax/MiniMax_DFS.h"
#include "../algorithms/minimax/MiniMax_EIDS.h"
#include "../algorithms/minimax/MiniMax_IDS.h"
#include "../algorithms/minimax/MiniMax_MaxDepth.h"
#include "../algorithms/minimax/heuristic_functions/WinnerOrLoser.h"
#include "../algorithms/minimax/heuristic_functions/KillerMove1.h"
#include "../algorithms/minimax/heuristic_functions/Doubles.h"
#include "../algorithms/minimax/heuristic_functions/DoublesAndTriples.h"
#include "../algorithms/minimax/heuristic_functions/OneAway.h"
#include "../algorithms/minimax/heuristic_functions/JakesHeuristic.h"
#include "../algorithms/minimax/heuristic_functions/JakesHeuristic2.h"
#include "../algorithms/minimax/successor_functions/Spiral.h"
#include "../algorithms/minimax/successor_functions/RowByRow.h"
#include "../algorithms/minimax/successor_functions/Bloom.h"
#include "../player/Player.h"
#include "../game/Game.h"

using namespace std;

int timeToThink();
bool whoGoesFirst();

/*
 * TODO: Documentation.
 */

/**
 * Main method for the modified connect 4 game.
 */
int main() {

	int maxTime = 30;
	maxTime = timeToThink();

	bool playerGoesFirst;
	playerGoesFirst = whoGoesFirst();

	Human h;
	Player p1(h);

	JakesHeuristic2 h2(100);
	Bloom sf2;
	//MiniMax_MaxDepth a2(maxTime, 4, sf2, h2);
	MiniMax_EIDS a2(maxTime, sf2, h2);
	Player p2(a2);

	// Our AI goes first
	if (playerGoesFirst) {
		Game g(p2, p1);
		g.play(playerGoesFirst);
	}
	// Their AI goes first
	else {
		Game g(p1, p2);
		g.play(!playerGoesFirst);
	}
	
	return 0;
}

int timeToThink() {
	int timeReturn = 0;
	cout << "Enter time to think: ";
	cin >> timeReturn;
	return timeReturn;
}

/*
* Returns true if player goes first.
*/
bool whoGoesFirst() {
	bool correctInput = false;;
	string input;
	do {
		cout << "Who goes first, player or opponent? ";
		cin >> input;

		// Transform input into all lowercase
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);

		if (input.compare("player") != 0 && input.compare("opponent") != 0) {
			cout << "Incorrect player.\n\n";
		}
		else {correctInput = true;}
	} while (!correctInput);

	if (input.compare("player") == 0) {return true;}
	else {return false;}
}