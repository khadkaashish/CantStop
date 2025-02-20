// ================================================================
// Name: Can't Stop Board Game        Feb, 2025
// Author:  Ashish Khadka and Aryan Tandon      File: Game.hpp
// ================================================================
#pragma once
#include "tools.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include "Column.hpp"
// -----------------------------------------------------------------
class Game {
private:
	Dice* dice; // Pointer to dice
	Player player1;
	Player player2;
	Column column2;
	Column column7;	
public:
	Game();
	~Game() { delete dice; }
	static Player getNewPlayer();
	static string getName();
	static ECcolor getColor();
	ostream& print (ostream& os);
};
//  Overload the output operator
inline ostream& operator<<(ostream& os, Game& game) {
	return game.print(os);
}


