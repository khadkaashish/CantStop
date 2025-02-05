//=======================================================================
// Project: Can't Stop Board Game        File: main.cpp
// Author:  Ashish Khadka and Aryan Tandon  Copyright: 2025
// ======================================================================
#include "tools.hpp"
#include "Dice.hpp"
#include "Player.hpp"
// ----------------------------------------------------------------------
void unitDice();
void testPlayer();

int main(int argc, const char * argv[]) {
    banner();
	srand(int(time(nullptr))); // Seed the random number generator once
//	unitDice();
	testPlayer();
    bye();
}
