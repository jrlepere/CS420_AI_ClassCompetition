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

#include "../algorithms/human/Human.h"
#include "../algorithms/minimax/MiniMax_DFS.h"
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

/*
 * TODO: Documentation.
 */

/**
 * Main method for the modified connect 4 game.
 */
int main() {

	int maxTime = 1000;

	Human h;
	Player p1(h);

	JakesHeuristic2 h2(100);
	Bloom sf2;
	//MiniMax_MaxDepth a2(maxTime, 4, sf2, h2);
	MiniMax_IDS a2(maxTime, sf2, h2);
	Player p2(a2);

	Game g(p1, p2);
	g.play();
	cout<<"???\n";
	string s = "" + 1;
	cout<<s;
	cout<<s;
	return 0;
}
