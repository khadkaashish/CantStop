// ===============================================================
// Can't Stop Board Game          File: unitTest.cpp
// Author:  Ashish Khadka and Aryan Tandon
// ===============================================================
#include "tools.hpp"
#include "Game.hpp"
//-----------------------------------------------------------------
void testGame(ostream& os, Game& game) {
    os << "Starting Column class unit test...\n";
	os << "Rolling dice: ";
	os << game;
	os << "Player initialization test completed!\n\n";
}
