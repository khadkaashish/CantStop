// ===============================================================
// Can't Stop Board Game          File: unitTest.cpp
// Author:  Ashish Khadka and Aryan Tandon
// ===============================================================
#include "tools.hpp"
#include "Board.hpp"
#include "Game.hpp"
//-----------------------------------------------------------------
void testGame(ostream& os) {
	os << "Starting Board class unit test...\n";
	Game game;  // Game creates the player internally
	Board board;
	
	// Use the player from the Game instance directly
	Player* player1 = game.getPlayer();  // Assuming getPlayer() returns a reference to the player
	board.startTurn(player1);
	
	os << game << endl;
	os << player1 << endl;
	// Try moving in Column 4
	os << "\n Moving in Column 4...\n";
	if (board.move(4)) {
		os << "Tower placed in Column 4!\n";
	} else {
		os << "Could not place tower in Column 4.\n";
	}
	
	// Try moving in Column 8
	os << "\n📍 Moving in Column 8...\n";
	if (board.move(8)) {
		os << "Tower placed in Column 8!\n";
	} else {
		os << "Could not place tower in Column 8.\n";
	}
	
	os << board;
	board.move(8);
	board.move(8);
	board.move(8);

	
	os << board;
	os << board;
	
	// Stop turn
	os << "\n Stopping turn...\n";
	board.stop();

	// Print final board state
	os << board;
	os << "Unit test completed.";
}
