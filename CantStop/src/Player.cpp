// ===============================================================
// Can't Stop Board Game          File: Player.cpp
// Author:  Ashish Khadka and Aryan Tandon
// ===============================================================
#include "Player.hpp"
//-----------------------------------------------------------------
bool Player::takenColors[4] = {false, false, false, false}; // Initialize player color tracking
vector<string> Player::takenNames = {};  // Initialize player name tracking

Player::Player(const string& playerName, ECcolor playerColor)
			   : name(playerName), color(playerColor), score(0) {
	string lowerName = playerName;
	transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
	
	// Check if name is taken **before storing**
	if (isNameTaken(lowerName)) {
		fatal("This player name is already taken! Choose another.");
	}

	// Check if color is taken
	int colorIndex = static_cast<int>(playerColor) - 1;
	if (colorIndex < 0 || colorIndex >= 4 || takenColors[colorIndex]) {
		fatal("Color already taken or invalid! Choose a different color.");
	}

	// Assign values only after validation
	name = playerName;
	color = playerColor;
	takenNames.push_back(lowerName);
	takenColors[colorIndex] = true;
}

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
	os <<"Player Name: " << name
	<<"\nColor: " <<" \t" <<colorNames[(int)(color)]
	<<"\nScore: " <<score <<endl;
	return os;
}

//-----------------------------------------------------------------
// Check if a color is already taken
bool Player::isColorTaken(ECcolor playerColor) {
	int colorIndex = (int)(playerColor) - 1;
	return (colorIndex >= 0 && colorIndex < 4) ? takenColors[colorIndex] : true;
}

//-----------------------------------------------------------------
// Check if a name is already taken
bool Player::isNameTaken(const string& playerName) {
	string lowerName = playerName;
	transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
	return find(takenNames.begin(), takenNames.end(), lowerName) != takenNames.end();
}


//-----------------------------------------------------------------
// Reset the taken colors (for a new game)
void Player::resetTakenData() {
	for (int i = 0; i < 4; i++) {
		takenColors[i] = false;
	}
	takenNames.clear();
}
