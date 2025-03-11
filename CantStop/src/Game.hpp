// ================================================================
// Name: Can't Stop Board Game        Feb, 2025
// Author:  Ashish Khadka and Aryan Tandon      File: Game.hpp
// ================================================================
#pragma once
#include "tools.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include "Column.hpp"
#include "Board.hpp"
// -----------------------------------------------------------------
class Game {
private:
	Dice* dice; // Pointer to dice
	Board board;
	vector<Player> players;

public:
	Game();
	~Game() { delete dice; }
	static string getName();
	static ECcolor getColor();
	
	Player* player(int index);
	void getPlayers();
	
	void oneTurn (Player* pp);
	ostream& print (ostream& os);
};
//  Overload the output operator
inline ostream& operator<<(ostream& os, Game& game) {
	return game.print(os);
}
