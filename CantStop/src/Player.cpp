// ===============================================================
// Can't Stop Board Game          File: Player.cpp
// Author:  Ashish Khadka and Aryan Tandon
// ===============================================================
#include "Player.hpp"
//-----------------------------------------------------------------
Player::Player(const std::string& playerName, ECcolor playerColor)
	: fullName(playerName), color(playerColor), score(0) {}

//-----------------------------------------------------------------
ECcolor Player::getColor() const { return color; }

//-----------------------------------------------------------------
int Player::getScore() const { return score; }

//-----------------------------------------------------------------
bool Player::wonColumn(int colNum){
	if (score<3){
		scoreboard[score] = colNum; // store the score in the next available column
		score += 1;
		return (score == 3);
	}
	return false;
}

//-----------------------------------------------------------------
ostream& Player::print(ostream& os) const {
	os <<"Player Name: " <<fullName
	<<"\nColor: " <<" \t" <<colorNames[(int)(color)]
	<<"\nScore: " <<score <<endl;
	return os;
}

