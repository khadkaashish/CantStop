// ===============================================================
// Can't Stop Board Game          File: unitTest.cpp
// Author:  Ashish Khadka and Aryan Tandon
// ===============================================================
#include "Player.hpp"
#include "tools.hpp"
//-----------------------------------------------------------------
// Function to get a valid player name (no spaces)
string getPlayerName() {
	string name;
	while (true) {
		cout << "Enter player name (no spaces): ";
		getline(cin, name);  // Read the full line

		// Remove spaces from the name
		name.erase(remove(name.begin(), name.end(), ' '), name.end());
		if (Player::isNameTaken(name)) {
			fatal ("This name is already taken! Choose another.\n");
		}
		// Check if the name is empty after removing spaces
		if (name.empty()) {
			cout << "Invalid name! The name cannot be empty or contain only spaces.\n";
		} else {
			break;  // Valid name, exit the loop
		}
	}
	return name;
}

//-----------------------------------------------------------------
// Function to get a valid ECcolor input
ECcolor getColorFromUser() {
	char choice;
	while (true) {
		cout << "Select a color (B = Blue, G = Green, Y = Yellow, O = Orange): ";
		cin >> choice;
		
		// Convert to uppercase to handle lowercase input
		choice = toupper(choice);
		ECcolor selectedColor = ECcolor::Error;
		// Switch statement to return the correct enum
		switch (choice) {
			case 'B': return ECcolor::Blue;
			case 'G': return ECcolor::Green;
			case 'Y': return ECcolor::Yellow;
			case 'O': return ECcolor::Orange;
			default:
				// Invalid input statement
				cout << "Invalid choice! Please enter B, G, Y, or O.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		
		if (selectedColor != ECcolor::Error && !Player::isColorTaken(selectedColor)) {
			return selectedColor;
		} else {
		  cout << "This color is already taken. Choose another.\n";
		}
	}
}

//-----------------------------------------------------------------
// Test for the Player class
void testPlayer(ofstream& outputFile) {
	// Open the test output file in append mode
	cout << "Starting Player class unit tests...\n";
	
	// Get player names from user input
	string name1 = getPlayerName();  // Get Player 1's name
	string name2 = getPlayerName();  // Get Player 2's name
	ECcolor color1 = getColorFromUser();
	ECcolor color2 = getColorFromUser();

	// Create Player instances
	Player player1(name1, color1);
	Player player2(name2, color2);
	
	// Test getColor()
	outputFile << "Testing getColor():\n";
	if (player1.getColor() == ECcolor::Green) {
		outputFile << "Player 1 color is correct (Green).\n";
	} else {
		outputFile << "Player 1 color is incorrect.\n";
	}
	if (player2.getColor() == ECcolor::Orange) {
		outputFile << "Player 2 color is correct (Orange).\n";
	} else {
		outputFile << "Player 2 color is incorrect.\n";
	}

	// Test getScore() (should be 0 initially)
	outputFile << "\nTesting getScore():\n";
	if (player1.getScore() == 0) {
		outputFile << "Player 1 score is correct (0).\n";
	} else {
		outputFile << "Player 1 score is incorrect.\n";
	}
	if (player2.getScore() == 0) {
		outputFile << "Player 2 score is correct (0).\n";
	} else {
		outputFile << "Player 2 score is incorrect.\n";
	}

	// Test wonColumn()
	outputFile << "\nTesting wonColumn():\n";
	if (player1.wonColumn(3) == false) {  // 1st column
		outputFile << "Player 1 column 3 captured correctly.\n";
	} else {
		outputFile << "Player 1 column 3 capture failed.\n";
	}
	if (player1.wonColumn(5) == false) {  // 2nd column
		outputFile << "Player 1 column 5 captured correctly.\n";
	} else {
		outputFile << "Player 1 column 5 capture failed.\n";
	}
	if (player1.wonColumn(7) == true) {   // 3rd column → should return true (win condition)
		outputFile << "Player 1 captured all columns and won!\n";
	} else {
		outputFile << "Player 1 failed to win.\n";
	}

	// Test operator<< (output test)
	outputFile << "\nTesting operator<< (printing players):\n";
	outputFile << "Player 1:\n" << player1;
	outputFile << "\nPlayer 2:\n" << player2;
	outputFile << "\nAll Player tests completed!" << endl;
}
