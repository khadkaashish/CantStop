// ================================================================
// Name: Can't Stop Board Game        Jan, 2025
// Author:  Ashish Khadka and Aryan Tandon      File: Player.hpp
// ================================================================
#pragma once
#include "tools.hpp"
#include "enums.hpp"
// -----------------------------------------------------------------
class Player{
private:
	string fullName;
	ECcolor color;
	int score;
	int scoreboard[3];
	
public:
	Player(const string& playerName, ECcolor playerColor);
	~Player(){}
	
	//	Accessor functions
	ECcolor getColor() const;
	int getScore() const;
	
	//	stores the number of captured columns
	bool wonColumn(int colNum);
	
	//	Print function
	ostream& print(ostream& os) const;
};

//	Overload the output operator
inline ostream& operator<<(ostream& os, Player& player) {
	return player.print(os);
}
