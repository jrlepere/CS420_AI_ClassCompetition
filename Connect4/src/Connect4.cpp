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

#include "../algorithms/minimax/MiniMax_DFS.h"
#include "../algorithms/minimax/MiniMax_IDS.h"
#include "../algorithms/minimax/MiniMax_MaxDepth.h"
#include "../algorithms/minimax/heuristic_functions/WinnerOrLoser.h"
#include "../algorithms/minimax/heuristic_functions/KillerMove1.h"
#include "../algorithms/minimax/heuristic_functions/Doubles.h"
#include "../algorithms/minimax/heuristic_functions/DoublesAndTriples.h"
#include "../algorithms/minimax/successor_functions/Spiral.h"
#include "../algorithms/minimax/successor_functions/RowByRow.h"
#include "../player/Player.h"
#include "../game/Game.h"

using namespace std;

/*
 * TODO: AB pruning
 * TODO: Documentation.
 * TODO: Integer MIN/MAX
 * TODO: Kill states
 */

/**
 * Main method for the modified connect 4 game.
 */
int main() {

	int maxTime = 28;

	WinnerOrLoser h1;
	KillerMove1 k1(h1);
	DoublesAndTriples d1(k1);
	Spiral sf1;
	MiniMax_MaxDepth a1(maxTime, 3, sf1, d1);
	Player p1(a1);

	WinnerOrLoser h2;
	KillerMove1 k2(h2);
	DoublesAndTriples d2(k2);
	RowByRow sf2;
	MiniMax_MaxDepth a2(maxTime, 3, sf2, d2);
	Player p2(a2);

	Game g(p1, p2);
	g.play();

	return 0;
}
