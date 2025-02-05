// ===============================================================
// Can't Stop Board Game          File: unitTest.cpp
// Author:  Ashish Khadka and Aryan Tandon
// ===============================================================
#include "Player.hpp"
#include "Dice.hpp"
#include "tools.hpp"
#include <cassert>
//-----------------------------------------------------------------

// Test for the Player class
void testPlayer() {
	cout << "Starting Player class unit tests...\n";
	
	// Create Player instances
	Player player1("RedWolf", ECcolor::Orange);
	Player player2("RubyMan", ECcolor::Blue);

	// Test getColor()
	assert(player1.getColor() == ECcolor::Orange);
	assert(player2.getColor() == ECcolor::Blue);
	cout << "✅ getColor() tests passed.\n";

	// Test getScore() (should be 0 initially)
	assert(player1.getScore() == 0);
	assert(player2.getScore() == 0);
	cout << "✅ getScore() tests passed.\n";

	// Test wonColumn()
	assert(player1.wonColumn(3) == false);  // 1st column
	assert(player1.wonColumn(5) == false);  // 2nd column
	assert(player1.wonColumn(7) == true);   // 3rd column → should return true (win condition)
	cout << "✅ wonColumn() tests passed.\n";

	// Test operator<< (output test)
	cout << "Printing Player 1:\n" << player1 << endl;
	cout << "Printing Player 2:\n" << player2 << endl;

	cout << "✅ All Player tests passed!\n";
}

// Helper function to roll and print dice
void rollAndPrint(Dice& dice, ofstream& testOutput, const string& testName) {
	testOutput << testName << endl;
	dice.roll();
	testOutput << "Rolled: " << dice << endl;
	testOutput << "-------------------------" << endl;
}

// Test for the Dice class
void unitDice() {
	// Open the test output file in append mode
	ofstream testOutput("test_output.txt", ios::app);

	if (!testOutput) {
		cerr << "Error opening test output file: test_output.txt" << endl;
		return;
	}

	// Test 1: Default Constructor (1 Die)
	{
		Dice dice1;  // Default constructor (1 die)
		rollAndPrint(dice1, testOutput, "Test 1: Rolling 1 die (default constructor)");
	}

	// Test 2: Constructor with 2 Dice
	{
		Dice dice2(2);  // Constructor with 2 dice
		rollAndPrint(dice2, testOutput, "Test 2: Rolling 2 dice");
	}
	
	// Test 3: Constructor with 3 Dice
	{
		Dice dice3(3);  // Constructor with 3 dice
		rollAndPrint(dice3, testOutput, "Test 3: Rolling 3 dice");
	}
	
	// Test 4: Constructor with 4 Dice
	{
		Dice dice4(4);  // Constructor with 4 dice
		rollAndPrint(dice4, testOutput, "Test 4: Rolling 4 dice");
	}

	// Test 5: Constructor with 5 Dice
	{
		Dice dice5(5);  // Constructor with 5 dice
		rollAndPrint(dice5, testOutput, "Test 5: Rolling 5 dice");
	}
	
	// Test 6: Constructor with 6 Dice
	{
		Dice dice6(6);  // Constructor with 5 dice
		rollAndPrint(dice6, testOutput, "Test 6: Rolling 6 dice");
	}
	
	
	// Test 7: Edge Case – 0 Dice (Invalid Input)
	{
		Dice dice6(0);  // Constructor with 0 dice
		rollAndPrint(dice6, testOutput, "Test 6: Rolling 0 dice");
	}
}
