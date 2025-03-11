// ===============================================================
// Can't Stop Board Game          File: Game.cpp
// Author:  Ashish Khadka and Aryan Tandon
// ===============================================================
#include "Game.hpp"
//-----------------------------------------------------------------
// Constructor initializes dice, 2-4 players, and columns
Game::Game()
	: dice(new Dice(4)){
		getPlayers();
	}

Player* Game::player(int index) {
	if (index < 0 || index >= players.size()) {
		cout << "ERROR: Invalid player index " << index << endl;
		return nullptr;  // Return NULL if index is invalid
	}
	return &players[index];  // Return pointer to the requested player
}

//-----------------------------------------------------------------
// Gets all players
void Game::getPlayers(){
	int num;
	cout << "Enter the number of players (1-4): ";
	cin >> num;
	
	while (num < 1 || num > 4){
		cout << "Invalid number! Enter between 1 and 4 players: ";
		cin >> num;
	}
	for (int j = 0; j < num; j++){
		string name;
		ECcolor color;
		name = getName();
		color = getColor();
		players.emplace_back(name, color);
	}
}

//-----------------------------------------------------------------
// Function to get a valid player name (no spaces)
string Game::getName() {
	string name;
	for (;;) {
		cout << "Enter player name (no spaces): ";
		cin >> name;  // Read the user name

		// Check if the name is already taken
		if (Player::isNameTaken(name)) {
			cout << "The name is already taken! Please choose a different name.\n";
			continue;
		}
		break;
	}
	return name;
}

//-----------------------------------------------------------------
// Function to get a valid ECcolor input
ECcolor Game::getColor(){
	char choice;
	ECcolor color;
	
	// Display available colors
	cout << "Available colors:\n";
	if (!Player::isColorTaken(ECcolor::Blue)) cout << "B: Blue\n";
	if (!Player::isColorTaken(ECcolor::Green)) cout << "G: Green\n";
	if (!Player::isColorTaken(ECcolor::Yellow)) cout << "Y: Yellow\n";
	if (!Player::isColorTaken(ECcolor::Orange)) cout << "O: Orange\n";
	
	for (;;) {
		cout << "Select a color: ";
		cin >> choice;
		
		// Convert to uppercase to handle lowercase input
		choice = toupper(choice);
		
		// Switch statement to return the correct enum
		switch (choice) {
			case 'B': color = ECcolor::Blue; break;
			case 'G': color = ECcolor::Green; break;
			case 'Y': color = ECcolor::Yellow; break;
			case 'O': color = ECcolor::Orange; break;
			default:
				cout << "Invalid choice! Please enter B, G, Y, or O." << endl;
				continue;  // Continue the loop to ask for input again
		}
		if (Player::isColorTaken(color)) {
			cout << "Color already taken! Choose another.\n";
			continue;
		}
		break;
	}
	return color;
}

//-----------------------------------------------------------------
// Print the Game elements
ostream& Game::print(ostream& os) {
	const int* rollResults = dice->roll(); // Roll the dice
	char labels[] = {'a', 'b', 'c', 'd'};
	os << "Dice values = ";
	for (int i = 0; i < 4; ++i) {
		os << labels[i] << ":" << rollResults[i] << " ";
	}
	os << "\n\n";
	return os;
}
